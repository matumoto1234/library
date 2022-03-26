#pragma once

#include "./base.hpp"

#include <vector>

namespace library_data_structure {
  // verify:https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
  template <typename T>
  class IntervalScheduling {
    vector<pair<T, T>> intervals_;
    vector<bool> used;

  public:
    IntervalScheduling() {}

    void add_interval(T l, T r) {
      intervals_.emplace_back(l, r);
    }

    int inf() {
      return numeric_limits<int>::max() / 2;
    }

    void build() {
      used.assign(intervals_.size(), false);

      sort(intervals_.begin(), intervals_.end(), [](pair<T, T> a, pair<T, T> b) {
        if (a.second != b.second)
          return a.second < b.second;
        return a.first < b.first;
      });

      int last = -inf();
      for (size_t i = 0; i < intervals_.size(); i++) {
        auto [l, r] = intervals_[i];

        if (last <= l) {
          used[i] = true;
          last = r;
        }
      }
    }

    bool is_used(int k) {
      return used[k];
    }

    vector<pair<T, T>> intervals() {
      vector<pair<T, T>> res;
      for (size_t i = 0; i < intervals_.size(); i++) {
        if (!used[i])
          continue;
        res.emplace_back(intervals_[i]);
      }
      return res;
    }
  };
} // namespace library_data_structure