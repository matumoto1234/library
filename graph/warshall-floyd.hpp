#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <limits>

namespace matumoto {
  template <typename Cost>
  class WarshallFloyd {
    vector<pair<Cost, int>> graph_;
    vector<vector<Cost>> distances_;
    vector<vector<int>> nexts_;
    bool has_neg_cycle_;

  public:
    WarshallFloyd(const vector<pair<Cost, int>> &graph): graph_(graph), has_neg_cycle_(false) {
      int n = graph_.size();
      distances_.assign(n, vector<Cost>(n, inf()));
      for (int i = 0; i < n; i++) {
        distances_[i][i] = 0;
      }

      nexts_.assign(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          nexts_[i][j] = j;
        }
      }

      auto edges = graph_.edges();
      for (auto edge: edges) {
        int from = edge.from();
        int to = edge.to();
        Cost cost = edge.cost();

        // if there are multiple edges, use the minimum cost edge.
        distances_.at(from).at(to) = min(distances_.at(from).at(to), cost);
      }

      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (distances_[i][k] == inf() or distances_[k][j] == inf()) {
              continue;
            }

            if (distances_[i][j] > distances_[i][k] + distances_[k][j]) {
              distances_[i][j] = distances_[i][k] + distances_[k][j];
              nexts_[i][j] = nexts_[i][k];
            }
          }
        }
      }

      for (int i = 0; i < n; i++) {
        if (distances_[i][i] < 0) {
          has_neg_cycle_ = true;
          break;
        }
      }
    }

    static constexpr Cost inf() {
      return numeric_limits<Cost>::max() / 2;
    }

    vector<Cost> &operator[](int k) {
      return distances_.at(k);
    }

    bool has_negative_cycle() const {
      return has_neg_cycle_;
    }

    vector<int> restore(int s, int g) {
      vector<int> path;
      for (int v = s; v != g; v = nexts_.at(v).at(g)) {
        path.emplace_back(v);
      }
      path.emplace_back(g);
      return path;
    }
  };
} // namespace matumoto
