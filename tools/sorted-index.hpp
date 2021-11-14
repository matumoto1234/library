#pragma once

#include "./base.hpp"

#include <numeric>
#include <vector>

namespace tools {
  template <typename Iterator>
  vector<int> sorted_index(Iterator first, Iterator last) {
    using T = remove_reference_t<decltype(*first)>;
    vector<T> a(first, last);
    vector<int> res(a.size());
    iota(res.begin(), res.end(), 0);
    stable_sort(res.begin(), res.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    return res;
  }
} // namespace tools