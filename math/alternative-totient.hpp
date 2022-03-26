#pragma once

#include "./base.hpp"
#include "./factorize.hpp"

#include <algorithm>
#include <vector>

namespace library_math {
  long long alternative_totient(long long x, long long n) {
    if (x == 1)
      return n;
    auto ps = factorize(x);
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int k = ps.size();
    long long res = n - x;
    for (int i = 1; i < (1 << k); i++) {
      long long prod = 1;
      int cnt = 0;
      for (int j = 0; j < k; j++) {
        if (i >> j & 1) {
          prod *= ps[j];
          cnt++;
        }
      }
      if (cnt % 2) {
        res += (n - x) / prod;
      } else {
        res -= (n - x) / prod;
      }
    }
    return res;
  }
} // namespace library_math
