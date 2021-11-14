#pragma once

#include "./base.hpp"

namespace math {
  ll totient(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        res -= res / i;
        while (n % i == 0)
          n /= i;
      }
    }
    if (n > 1) res -= res / n;
    return res;
  }
} // namespace math