#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <algorithm>

namespace graph_library {
  template <typename Cost>
  class BellmanFord {
    WeightedGraph<Cost> graph_;
    WeightedEdges<Cost> edges_;
    vector<Cost> distances_;
    vector<int> befores_;
    int start_, goal_;
    bool has_neg_cycle_, has_neg_cycle_to_goal_;

  public:
    BellmanFord(const WeightedGraph<Cost> &graph, int start, int goal = -1): graph_(graph), start_(start), goal_(goal), has_neg_cycle_(false), has_neg_cycle_to_goal_(false) {
      int n = graph_.size();

      if (goal_ == -1)
        goal_ = n - 1;

      edges_ = graph_.edges();

      distances_.assign(n, inf());
      befores_.assign(n, -1);

      distances_.at(start) = 0;

      for (int i = 0; i < 2 * n; i++) {
        for (auto edge: edges_) {
          int from = edge.from();
          int to = edge.to();
          Cost cost = edge.cost();

          if (distances_.at(from) >= inf())
            continue;

          if (distances_.at(to) <= distances_.at(from) + cost)
            continue;

          distances_.at(to) = distances_.at(from) + cost;
          befores_.at(from) = to;

          if (i >= n - 1) {
            distances_.at(to) = -inf();
            has_neg_cycle_ = true;

            if (to == goal_) {
              has_neg_cycle_to_goal_ = true;
              return;
            }
          }
        }
      }
    }

    static constexpr Cost inf() {
      return numeric_limits<Cost>::max() / 2;
    }

    bool has_negative_cycle() const {
      return has_neg_cycle_;
    }

    bool has_negative_cycle_to_goal_() const {
      return has_neg_cycle_to_goal_;
    }

    Cost operator[](int k) {
      return distances_.at(k);
    }

    vector<int> restore(int to) {
      vector<int> path;
      if (befores_.at(to) == -1) {
        path.emplace_back(to);
        return path;
      }

      while (befores_.at(to) != -1) {
        path.emplace_back(to);
        to = befores_.at(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
  };
} // namespace graph_library
