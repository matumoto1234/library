#pragma once

#include "./base.hpp"

namespace tools {
  template <int m>
  class ModInt {
    
    using ll = long long;
    unsigned int v;

    constexpr ll safe_mod(ll x, ll m) {
      x %= m;
      if (x < 0) x += m;
      return x;
    }

    constexpr ll constexpr_mod_pow(ll x, ll n, int m) {
      if (m==1) return 0;
    }

    ModInt(): v(0) {}
    ModInt(long long x) { v = x % MOD; }
  };
} // namespace tools