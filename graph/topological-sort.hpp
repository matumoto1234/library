#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <queue>

namespace matumoto {
  // if graph is not DAG, return {}
  vector<int> topological_sort(const UnWeightedGraph &graph) {
    int n = graph.size();
    vector<int> in_degree(n, 0);

    auto edges = graph.edges();
    for (auto e: edges) {
      in_degree[e.to()]++;
    }

    vector<UnWeightedEdges> adj_list = graph.graph();

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (in_degree[i] == 0)
        q.push(i);
    }

    vector<int> sorted_indexes;
    while (not q.empty()) {
      int v = q.front();
      q.pop();

      sorted_indexes.emplace_back(v);
      for (auto e: adj_list[v]) {
        int to = e.to();

        in_degree[to]--;
        if (in_degree[to] == 0)
          q.push(to);
      }
    }

    bool has_cycle = int(sorted_indexes.size()) < n;
    if (has_cycle) {
      return {};
    }
    return sorted_indexes;
  }
} // namespace matumoto
