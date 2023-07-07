#pragma once

#include "adjacency-list-to-edges.hpp"
#include "base.hpp"
#include "tools/assert-msg.hpp"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace matumoto {
  template <typename Cost>
  class BellmanFord {
    // adjacency list
    vector<vector<pair<Cost, int>>> adj_list_;
    vector<tuple<int, int, Cost>> edges_;
    vector<Cost> dists_;
    vector<int> prevs_;
    int start_, goal_;
    bool has_neg_cycle_, has_neg_cycle_to_goal_;

  public:
    BellmanFord(const vector<vector<pair<Cost, int>>> &adj_list, int start, int goal = -1)
      : adj_list_(adj_list),
        dists_(adj_list_.size(), inf()),
        prevs_(adj_list_.size(), -1),
        start_(start),
        goal_(goal),
        has_neg_cycle_(false),
        has_neg_cycle_to_goal_(false) {
      int n = adj_list_.size();
      if (goal_ == -1) {
        goal_ = n - 1;
      }
      assert_msg(0 <= start and start < n, "start:" + to_string(start) + " n:" + to_string(n));
      assert_msg(0 <= goal and goal < n, "goal:" + to_string(goal) + " n:" + to_string(n));

      edges_ = adjacency_list_to_edges(adj_list_);

      dists_[start] = 0;

      for (int i = 0; i < 2 * n; i++) {
        for (const auto &[from, to, cost]: edges_) {
          assert_msg(0 <= from and from < n, "from:" + to_string(from) + " n:" + to_string(n));
          assert_msg(0 <= to and to < n, "to:" + to_string(to) + " n:" + to_string(n));

          if (dists_[from] >= inf() or dists_[from] + cost >= dists_[to]) {
            continue;
          }

          if (i >= n - 1 and to == goal) {
            has_neg_cycle_ = true;
            has_neg_cycle_to_goal_ = true;
            return;
          } else if (i >= n - 1) {
            has_neg_cycle_ = true;
            dists_[to] = -inf();
          } else {
            dists_[to] = dists_[from] + cost;
            prevs_[to] = from;
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

    bool has_negative_cycle_to_goal() const {
      return has_neg_cycle_to_goal_;
    }

    Cost &operator[](int k) {
      assert_msg(0 <= k and k < (int)dists_.size(), "k:" + to_string(k) + " size:" + to_string(dists_.size()));
      return dists_[k];
    }

    vector<int> restore(int to) {
      assert_msg(0 <= to and to < (int)dists_.size(), "to:" + to_string(to) + " size:" + to_string(prevs_.size()));
      vector<int> path;
      if (prevs_[to] == -1) {
        path.emplace_back(to);
        return path;
      }

      while (prevs_[to] != -1) {
        path.emplace_back(to);
        to = prevs_.at(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
  };
} // namespace matumoto
