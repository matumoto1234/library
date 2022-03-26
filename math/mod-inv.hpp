#pragma once

#include "./base.hpp"
#include "./extgcd.hpp"

namespace math_library {
  constexpr ll modinv(ll n, ll mod) {
    ll x = 0, y = 0;
    extgcd(n, mod, x, y);
    return (x % mod + mod) % mod;
  }
} // namespace math_library