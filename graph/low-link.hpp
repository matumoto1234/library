#pragma once

#include "./base.hpp"

#include <algorithm>
#include <vector>

namespace library_graph {
  class LowLink {
  public:
    vector<int> articulations;
    vector<pair<int, int>> bridges;

    LowLink(int V): G(V) {}

    void add_edge(int from, int to) { G[from].emplace_back(to); }

    void build() {
      int V = G.size();
      ord.assign(V, -1);
      low.resize(V);

      int k = 0;
      for (int i = 0; i < V; i++) {
        if (ord[i] == -1)
          dfs(i, k, -1);
      }
      sort(articulations.begin(), articulations.end());
      sort(bridges.begin(), bridges.end());
    }

  private:
    vector<vector<int>> G;
    vector<int> ord, low;

    void dfs(int id, int &k, int par) {
      ord[id] = low[id] = k;
      k++;

      bool is_articulation = false;
      int child_cnt = 0;

      for (int to: G[id]) {
        if (ord[to] == -1) {
          child_cnt++;
          dfs(to, k, id);

          low[id] = min(low[id], low[to]);
          if (par != -1 and ord[id] <= low[to])
            is_articulation = true;
          if (ord[id] < low[to])
            bridges.emplace_back(min(id, to), max(id, to));
        } else if (to != par) {
          low[id] = min(low[id], ord[to]);
        }
      }

      if (par == -1 and child_cnt >= 2)
        is_articulation = true;
      if (is_articulation)
        articulations.emplace_back(id);
    }
  };
} // namespace library_graph