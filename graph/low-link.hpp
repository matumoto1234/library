#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <algorithm>

namespace graph_library {
  class LowLink {
    UnWeightedGraph graph_;
    vector<UnWeightedEdges> adj_list_;
    vector<int> order_, lowlink_;
    vector<int> articulations_;
    vector<UnWeightedEdge> bridges_;

  public:
    LowLink(const UnWeightedGraph &graph): graph_(graph) {
      adj_list_ = graph_.graph();

      int n = graph_.size();
      order_.assign(n, -1);
      lowlink_.assign(n, 0);

      int k = 0;
      for (int i = 0; i < n; i++) {
        if (order_[i] == -1)
          dfs(i, k, -1);
      }
      sort(articulations_.begin(), articulations_.end());
      sort(bridges_.begin(), bridges_.end());
    }

    vector<int> articulations() const {
      return articulations_;
    }

    vector<UnWeightedEdge> bridges() const {
      return bridges_;
    }

  private:
    void dfs(int idx, int &k, int parent) {
      order_[idx] = lowlink_[idx] = k;
      k++;

      bool is_articulation = false;
      int child_cnt = 0;

      for (auto edge: adj_list_[idx]) {
        int to = edge.to();

        if (order_[to] == -1) {
          child_cnt++;
          dfs(to, k, idx);

          lowlink_[idx] = min(lowlink_[idx], lowlink_[to]);
          if (parent != -1 and order_[idx] <= lowlink_[to])
            is_articulation = true;
          if (order_[idx] < lowlink_[to])
            bridges_.emplace_back(min(idx, to), max(idx, to));
        } else if (to != parent) {
          lowlink_[idx] = min(lowlink_[idx], order_[to]);
        }
      }

      if (parent == -1 and child_cnt >= 2)
        is_articulation = true;
      if (is_articulation)
        articulations_.emplace_back(idx);
    }
  };
} // namespace graph_library
