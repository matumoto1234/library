#pragma once

#include "./base.hpp"
#include "graph-type.hpp"

namespace matumoto {
  template <typename Cost>
  UnWeightedGraph to_unweighted(const WeightedGraph<Cost> &graph) {
    UnWeightedGraph res(graph.size());

    const WeightedEdges<Cost> &edges = graph.edges();
    for (const WeightedEdge<Cost> &edge: edges) {
      UnWeightedEdge unweighted_edge(edge.from(), edge.to());
      res.add_edge(unweighted_edge);
    }

    return res;
  }
} // namespace matumoto
