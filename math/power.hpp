#pragma once

#include "./base.hpp"

#include <cassert>
#include <numeric>

namespace math {
  // verify:AOJ_NTL_1_B
  namespace power_helper {

    template <typename T>
    T extgcd(T a, T b, T &x, T &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      T d = extgcd(b, a % b, y, x);
      y = y - (a / b) * x;
      return d;
    }

  } // namespace power_helper

  ll power(ll a, ll e, ll p = -1) {
    assert(p != 0);
    assert(p >= -1);

    if (e < 0) {
      assert(p != -1 and gcd(a, p) == 1);
      ll x, y;
      power_helper::extgcd(a, p, x, y);
      a = (x % p + p) % p;
      e *= -1;
    }

    ll res = 1;
    while (e > 0) {
      if (e & 1) {
        res *= a;
        if (p != -1) res %= p;
      }
      a *= a;
      if (p != -1) a %= p;
      e >>= 1;
    }
    return res;
  }
} // namespace math