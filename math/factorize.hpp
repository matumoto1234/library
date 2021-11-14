#include "./base.hpp"

#include <vector>

namespace math {
  vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
      while (n % i == 0) {
        res.emplace_back(i);
        n /= i;
      }
    }
    if (n > 1) res.emplace_back(n);
    return res;
  }
} // namespace math