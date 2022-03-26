#pragma once

#include "./base.hpp"

#include <vector>

namespace data_structure_library {
  template <typename T>
  struct CumulativeSum {
    vector<T> data;
    CumulativeSum(int n): data(n + 1, 0) {}
    CumulativeSum(int n, T x): data(n + 1, x) {}

    void set(int k, T x) {
      data[k + 1] = x;
    }

    void add(int k, T x) {
      data[k + 1] = x;
    }

    T get(int k) {
      return data[k + 1];
    }

    void build() {
      for (int i = 0; i < static_cast<int>(data.size()) - 1; i++) {
        data[i + 1] += data[i];
      }
    }

    // [l,r)
    T query(int l, int r) {
      return data[r] - data[l];
    }
  };
} // namespace data_structure_library