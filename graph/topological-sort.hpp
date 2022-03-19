#pragma once

#include "./base.hpp"

#include <queue>
#include <vector>

namespace library_graph {
  struct TopologicalSort {
    vector<vector<int>> G;
    vector<int> in_degree;

    TopologicalSort(int V): G(V), in_degree(V, 0) {}

    void add_edge(int from, int to) {
      G[from].emplace_back(to);
      in_degree[to]++;
    }

    vector<int> build() {
      int V = G.size();
      queue<int> q;
      for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0)
          q.push(i);
      }

      vector<int> res;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.emplace_back(v);
        for (int to: G[v]) {
          in_degree[to]--;
          if (in_degree[to] == 0)
            q.push(to);
        }
      }

      return res;
    }
  };
} // namespace library_graph