#pragma once

#include "./base.hpp"

#include <vector>

namespace graph {
  class EulerTour {
  private:
    vector<int> _in, _out, _depth, _parent, _edge_table;
    vector<vector<int>> G;

    void dfs(int v, int &time, int dep) {
      _in[v] = time;
      _depth[v] = dep;
      _edge_table[time] = v;
      time++;
      for (auto to: G[v]) {
        if (_in[to] != -1) continue;
        _parent[to] = v;
        dfs(to, time, dep + 1);
      }
      _out[v] = time;
      _edge_table[time] = -v;
      time++;
    }

  public:
    EulerTour(int n): G(n) {}

    void add_edge(int from, int to) { G[from].emplace_back(to); }

    void build(int s) {
      _in.assign(G.size(), -1);
      _out.assign(G.size(), -1);
      _depth.assign(G.size(), -1);
      _parent.assign(G.size(), -1);
      _edge_table.assign(2 * G.size(), -1);

      int time = 0;
      dfs(s, time, 0);
    }

    // edge_table:[first, second), vertex_table:[first, second]
    pair<int, int> subtree(int v) { return make_pair(_in[v], _out[v]); }

    vector<int> in() { return _in; }
    vector<int> out() { return _out; }
    vector<int> depth() { return _depth; }
    vector<int> parent() { return _parent; }
    vector<int> edge_table() { return _edge_table; }

    vector<int> vertex_table() {
      vector<int> res = _edge_table;
      for (auto &v: res) {
        if (v < 0) v = _parent[v];
      }
      // 半開区間->閉区間の誤差
      res.pop_back();
      return res;
    }
  };
} // namespace graph
