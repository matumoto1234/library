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
    int size_;

  public:
    WeightedGraph(int N): graph_(N), size_(N) {}

    void add_edge(int from, int to, Cost cost) {
      graph_.at(from).emplace_back(to, cost);
      edges_.emplace_back(from, to, cost);
    }

    int size() const { return size_; }
    tuple<int, int, Cost> get_edge(int k) const { return edges_.at(k); }
    vector<tuple<int, int, Cost>> edges() const { return edges_; }
    vector<vector<WeightedEdge>> graph() const { return graph_; }
  };
} // namespace graph
