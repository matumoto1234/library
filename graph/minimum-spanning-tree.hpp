#pragma once

#include "../data-structure/union-find.hpp"
#include "./base.hpp"
#include "./graph-type.hpp"

#include <queue>

namespace graph_library {

  template <typename Cost>
  struct MinimumSpanningTree {
    WeightedGraph<Cost> graph_;
    WeightedGraph<Cost> mst_;
    MinimumSpanningTree(const WeightedGraph<Cost> &graph): graph_(graph) {}

    Cost kruskal() {
      mst_ = WeightedGraph<Cost>(graph_.size()); // init
      if (graph_.size() == 0) {
        return Cost(0);
      }

      vector<WeightedEdge<Cost>> edges = graph_.edges();
      sort(edges.begin(), edges.end());

      data_structure_library::UnionFind uf(graph_.size());

      Cost sum = 0;

      for (auto edge: edges) {
        int from = edge.from();
        int to = edge.to();

        if (uf.same(from, to))
          continue;

        uf.merge(from, to);
        sum += edge.cost();
        mst_.add_edge(edge);
      }

      return sum;
    }

    Cost prim() {
      mst_ = WeightedGraph<Cost>(graph_.size()); // init
      if (graph_.size() == 0) {
        return Cost(0);
      }

      priority_queue<WeightedEdge<Cost>, vector<WeightedEdge<Cost>>, greater<WeightedEdge<Cost>>> pq;
      pq.emplace(/*from=*/0, /*to=*/0, Cost(0));

      vector<vector<WeightedEdge<Cost>>> adj_list = graph_.graph();
      vector<bool> used(graph_.size(), false);

      Cost sum = 0;

      while (not pq.empty()) {
        auto e = pq.top();
        pq.pop();

        int v = e.to();

        if (used[v])
          continue;

        sum += e.cost();
        used[v] = true;
        mst_.add_edge(e);

        for (auto edge: adj_list[v]) {
          int to = edge.to();

          if (used[to])
            continue;

          pq.push(edge);
        }
      }

      return sum;
    }
  };

} // namespace graph_library
