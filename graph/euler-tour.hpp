#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

namespace graph_library {
  class EulerTour {
    vector<int> in_time, out_time, dep, par, edge_table_;
    vector<vector<int>> G;

    void dfs(int v, int &time, int d) {
      in_time[v] = time;
      dep[v] = d;
      edge_table_[time] = v;
      time++;
      for (auto to: G[v]) {
        if (in_time[to] != -1)
          continue;
        par[to] = v;
        dfs(to, time, d + 1);
      }
      out_time[v] = time;
      edge_table_[time] = -v;
      time++;
    }

  public:
    EulerTour(int n): G(n) {}

    void add_edge(int from, int to) {
      G[from].emplace_back(to);
    }

    void build(int s) {
      int n = G.size();
      in_time.assign(n, -1);
      out_time.assign(n, -1);
      dep.assign(n, -1);
      par.assign(n, -1);
      edge_table_.assign(2 * n, -1);

      int time = 0;
      dfs(s, time, 0);
    }

    int in(int v) {
      return in_time[v];
    }
    int out(int v) {
      return out_time[v];
    }
    int depth(int v) {
      return dep[v];
    }
    int parent(int v) {
      return par[v];
    }
    vector<int> edge_table() {
      return edge_table_;
    }

    // edge_table:[first, second), vertex_table:[first, second]
    pair<int, int> subtree(int v) {
      return pair(in_time[v], out_time[v]);
    }

    vector<int> vertex_table() {
      vector<int> res = edge_table_;
      for (auto &v: res) {
        if (v < 0)
          v = par[-v];
      }
      // 半開区間->閉区間の誤差
      res.pop_back();
      return res;
    }
  };

  class EulerTour {
    vector<int> in_time_, out_time_, depths_, parents_, edge_table_;

    void dfs(const vector<UnWeightedEdges> &adj_list, int v, int &time, int d) {
      in_time_[v] = time;
      depths_[v] = d;
      edge_table_[time] = v;
      time++;

      for (auto e: adj_list[v]) {
        int to = e.to();

        if (in_time_[to] != -1)
          continue;

        parents_[to] = v;
        dfs(adj_list, to, time, d + 1);
      }
      out_time_[v] = time;
      edge_table_[time] = -v;
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
      return in_time_[v];
    }
    int out(int v) {
      return out_time_[v];
    }
    int depth(int v) {
      return depths_[v];
    }
    int parent(int v) {
      return parents_[v];
    }
    vector<int> edge_table() {
      return edge_table_;
    }
  };
} // namespace graph_library
