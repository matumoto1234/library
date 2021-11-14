#pragma once

#include "./base.hpp"

#include <algorithm>
#include <vector>

namespace math {
  template <typename T = long long>
  vector<T> divisor(T n) {
    vector<T> res;
    for (long long i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        res.emplace_back(i);
        if (i * i != n) res.emplace_back(n / i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
} // namespace math