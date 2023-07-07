#include "base.hpp"

#include <utility>
#include <vector>

namespace matumoto {
  vector<pair<int, int>> adjacency_list_to_edges(const vector<vector<int>> &adj_list) {
    vector<pair<int, int>> edges;
    for (int v = 0; v < (int)adj_list.size(); v++) {
      for (const auto &to: adj_list[v]) {
        edges.emplace_back(v, to);
      }
    }
    return edges;
  }

  template <typename Cost>
  vector<tuple<int, int, Cost>> adjacency_list_to_edges(const vector<vector<pair<Cost, int>>> &adj_list) {
    vector<tuple<int, int, Cost>> edges;
    for (int v = 0; v < (int)adj_list.size(); v++) {
      for (const auto &[cost, to]: adj_list[v]) {
        edges.emplace_back(v, to, cost);
      }
    }
    return edges;
  }
} // namespace matumoto
