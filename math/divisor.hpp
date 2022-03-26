#pragma once

#include "./base.hpp"

#include <algorithm>
#include <vector>

namespace math_library {
  vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        res.emplace_back(i);
        if (i * i != n)
          res.emplace_back(n / i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
} // namespace math_library