#pragma once

#include "./base.hpp"

#include <cassert>

namespace math {
  constexpr int logarithm(ll base, ll n) {
    assert(base != 0);
    int cnt = 0;
    while (n % base == 0) {
      n /= base;
      cnt++;
    }
    return cnt;
  }
} // namespace math