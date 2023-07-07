#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <stack>
#include <tuple>

namespace matumoto {
  class LowestCommonAncestor {
    UnWeightedGraph graph_;
    int height_, root_;
    vector<vector<int>> doubling_parents_;
    vector<int> depths_;

  public:
    LowestCommonAncestor(const UnWeightedGraph &graph, int root = 0): graph_(graph), root_(root) {
      int n = graph_.size();

      height_ = 1;
      while ((1 << height_) <= n) {
        height_++;
      }

      doubling_parents_.assign(height_, vector<int>(n, -1));
      depths_.assign(n, 0);

      vector<UnWeightedEdges> adj_list = graph_.graph();
      // <v, par, dep>
      stack<tuple<int, int, int>> st;
      st.emplace(root, -1, 0);
      while (not st.empty()) {
        auto [v, par, dep] = st.top();
        st.pop();

        doubling_parents_.at(0).at(v) = par;
        depths_.at(v) = dep;
        for (UnWeightedEdge e: adj_list.at(v)) {
          int to = e.to();
          if (to != par) {
            st.emplace(to, v, dep + 1);
          }
        }
      }

      for (int k = 0; k + 1 < height_; k++) {
        for (int v = 0; v < n; v++) {
          if (doubling_parents_.at(k).at(v) != -1) {
            int kth_pow_par = doubling_parents_.at(k).at(v);
            doubling_parents_.at(k + 1).at(v) = doubling_parents_.at(k).at(kth_pow_par);
          }
        }
      }
    }

    int query(int u, int v) {
      if (depths_.at(u) > depths_.at(v))
        swap(u, v);
      for (int k = 0; k < height_; k++)
        if ((depths_.at(v) - depths_.at(u)) >> k & 1)
          v = doubling_parents_.at(k).at(v);

      if (u == v)
        return u;

      for (int k = height_ - 1; k >= 0; k--)
        if (doubling_parents_.at(k).at(u) != doubling_parents_.at(k).at(v))
          u = doubling_parents_.at(k).at(u), v = doubling_parents_.at(k).at(v);

      return doubling_parents_.at(0).at(u);
    }

    int distance(int u, int v) {
      return depths_.at(u) + depths_.at(v) - depths_[query(u, v)] * 2;
    }
  };
} // namespace matumoto
