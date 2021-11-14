#pragma once

#include <cassert>
using ll = long long;

namespace math {
  int logarithm(ll base, ll n) {
    assert(base != 0);
    int cnt = 0;
    while (n % base == 0) {
      n /= base;
      cnt++;
    }
    return cnt;
  }
} // namespace math