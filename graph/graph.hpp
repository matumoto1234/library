#pragma once

#include "./base.hpp"

#include <utility>
#include <vector>

namespace graph {
  class Graph {
    vector<pair<int, int>> edges_;
    vector<vector<int>> graph_;

  public:
    Graph() = default;

    void add_edge(int from, int to) {
      graph_[from].emplace_back(to);
      edges_.emplace_back(from, to);
    }

    pair<int, int> get_edge(int k) { return edges_[k]; }
    vector<pair<int, int>> edges() { return edges_; }
    vector<vector<int>> graph() { return graph_; }
  };
} // namespace graph
