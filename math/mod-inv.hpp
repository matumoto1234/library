#pragma once

#include "./base.hpp"
#include "./extgcd.hpp"

namespace math {
  ll modinv(ll n, ll mod) {
    ll x, y;
    extgcd(n, mod, x, y);
    return (x % mod + mod) % mod;
  }
} // namespace math