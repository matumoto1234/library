#pragma once

#include "./base.hpp"
#include "graph-type.hpp"

namespace matumoto {
  template <typename Cost>
  WeightedGraph<Cost> to_weighted(const UnWeightedGraph &graph, const Cost &init) {
    WeightedGraph<Cost> res(graph.size());

    const UnWeightedEdges &edges = graph.edges();
    for (const UnWeightedEdge &edge: edges) {
      WeightedEdge<Cost> weighted_edge(edge.from(), edge.to(), init);
      res.add_edge(weighted_edge);
    }

    return res;
  }
} // namespace matumoto
