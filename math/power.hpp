#pragma once

#include "./base.hpp"
#include "./extgcd.hpp"

#include <cassert>
#include <numeric>

namespace matumoto {
  // verify:AOJ_NTL_1_B
  constexpr ll power(ll a, ll e, ll p = -1) {
    assert(p != 0);
    assert(p >= -1);

    if (e < 0) {
      assert(p != -1 and gcd(a, p) == 1);
      ll x, y;
      extgcd(a, p, x, y);
      a = (x % p + p) % p;
      e *= -1;
    }

    ll res = 1;
    while (e > 0) {
      if (e & 1) {
        res *= a;
        if (p != -1)
          res %= p;
      }
      a *= a;
      if (p != -1)
        a %= p;
      e >>= 1;
    }
    return res;
  }
} // namespace matumoto