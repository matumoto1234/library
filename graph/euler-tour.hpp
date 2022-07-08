#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

namespace graph_library {
  class EulerTour {
    vector<int> in_time_, out_time_, depths_, parents_, edge_table_;

    void dfs(const vector<UnWeightedEdges> &adj_list, int v, int &time, int d) {
      in_time_.at(v) = time;
      depths_.at(v) = d;
      edge_table_.at(time) = v;
      time++;

      for (auto e: adj_list.at(v)) {
        int to = e.to();

        if (in_time_.at(to) != -1)
          continue;

        parents_.at(to) = v;
        dfs(adj_list, to, time, d + 1);
      }
      out_time_.at(v) = time;
      edge_table_.at(time) = -v;
      time++;
    }

  public:
    EulerTour(const UnWeightedGraph &graph, int root) {
      int n = graph.size();
      in_time_.assign(n, -1);
      out_time_.assign(n, -1);
      depths_.assign(n, -1);
      parents_.assign(n, -1);
      edge_table_.assign(2 * n, -1);

      vector<UnWeightedEdges> adj_list = graph.graph();

      int time = 0;
      dfs(adj_list, root, time, 0);
    }

    int in(int v) {
      return in_time_.at(v);
    }
    int out(int v) {
      return out_time_.at(v);
    }
    int depth(int v) {
      return depths_.at(v);
    }
    int parent(int v) {
      return parents_.at(v);
    }
    vector<int> edge_table() {
      return edge_table_;
    }

    // edge_table: [first, second], vertex_table:[first, second)
    pair<int, int> subtree(int v) {
      return pair(in_time_.at(v), out_time_.at(v));
    }

    vector<int> vertex_table() {
      vector<int> res = edge_table_;
      for (auto &v: res) {
        if (v < 0)
          v = parents_.at(-v);
      }
      // 半開区間->閉区間の誤差
      res.pop_back();
      return res;
    }
  };
} // namespace graph_library
