#pragma once

#include "./base.hpp"

#include <utility>
#include <vector>

namespace graph {
  template <typename Cost>
  class WeightedGraph {
  public:
    using WeightedEdge = pair<int, Cost>;

  private:
    vector<tuple<int, int, Cost>> edges_;
    vector<vector<WeightedEdge>> graph_;

  public:
    WeightedGraph() = default;

    void add_edge(int from, int to, Cost cost) {
      graph_[from].emplace_back(to, cost);
      edges_.emplace_back(from, to, cost);
    }

    tuple<int, int, Cost> get_edge(int k) { return edges_[k]; }
    vector<tuple<int, int, Cost>> edges() { return edges_; }
    vector<vector<WeightedGraph>> graph() { return graph_; }
  };
} // namespace graph
