#pragma once

#include "./base.hpp"
#include "./extgcd.hpp"

namespace math {
  constexpr ll modinv(ll n, ll mod) {
    ll x = 0, y = 0;
    extgcd(n, mod, x, y);
    return (x % mod + mod) % mod;
  }
} // namespace math