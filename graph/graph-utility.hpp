#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

namespace graph_library {
  template <typename Cost>
  WeightedGraph<Cost> reverse(const WeightedGraph<Cost> &g) {
    const WeightedEdges<Cost> &edges = g.edges();
    WeightedGraph<Cost> rg(g.size());
    for (const WeightedEdge<Cost> &edge: edges) {
      rg.add_edge(edge.to(), edge.from(), edge.cost());
    }

    return rg;
  }

  UnWeightedGraph reverse(const UnWeightedGraph &g) {
    const UnWeightedEdges &edges = g.edges();
    UnWeightedGraph rg(g.size());
    for (const auto &edge: edges) {
      rg.add_edge(edge.to(), edge.from());
    }

    return rg;
  }
} // namespace graph_library
