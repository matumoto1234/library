#pragma once

#include "../data-structure/fenwick-tree.hpp"
#include "./base.hpp"

#include <vector>

namespace tools_library {
  // verify:AOJ_ALDS1_5_D
  template <typename T>
  long long inversion(vector<T> vs) {
    auto uni = vs;
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (T &v: vs) {
      v = lower_bound(uni.begin(), uni.end(), v) - uni.begin();
    }

    int n = vs.size();
    data_structure::FenwickTree<long long> ft(n + 1);
    long long res = 0;
    for (T v: vs) {
      res += ft.sum(v + 1, n);
      ft.add(v, 1);
    }
    return res;
  }
} // namespace tools_library