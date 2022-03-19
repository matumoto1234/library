#pragma once

#include "./base.hpp"

#include <vector>

namespace library_graph {
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

    void add_edge(int from, int to) { G[from].emplace_back(to); }

    void build(int s) {
      in_time.assign(G.size(), -1);
      out_time.assign(G.size(), -1);
      dep.assign(G.size(), -1);
      par.assign(G.size(), -1);
      edge_table_.assign(2 * G.size(), -1);

      int time = 0;
      dfs(s, time, 0);
    }

    int in(int v) { return in_time[v]; }
    int out(int v) { return out_time[v]; }
    int depth(int v) { return dep[v]; }
    int parent(int v) { return par[v]; }
    vector<int> edge_table() { return edge_table_; }

    // edge_table:[first, second), vertex_table:[first, second]
    pair<int, int> subtree(int v) { return pair(in_time[v], out_time[v]); }

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
} // namespace library_graph
