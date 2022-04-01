#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

namespace graph_library {
  // want to use concept

  template <class Graph>
  Graph reverse_edges(const Graph &g) {
    const auto &edges = g.edges();
    Graph rg(g.size());

    for (auto edge: edges) {
      swap(edge.from(), edge.to());
      rg.add_edge(edge);
    }

    return rg;
  }
} // namespace graph_library
