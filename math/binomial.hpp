#pragma once

#include "./base.hpp"

namespace library_math {
  constexpr ll binomial(ll n, ll r) {
    ll res = 1;
    for (ll i = 0; i < r; i++) {
      res *= n - i;
      res /= i + 1;
    }
    return res;
  }
} // namespace library_math