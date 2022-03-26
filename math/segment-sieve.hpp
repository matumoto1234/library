#pragma once

#include "./base.hpp"

#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

namespace math_library {
  class SegmentSieve {
    ll l, r, sqrt_r;
    vector<int> small_sieve;
    vector<vector<ll>> large_sieve;
    vector<ll> aux; // aux[i] := large_sieve[i] の素因数の積

  public:
    SegmentSieve(ll l, ll r): l(l), r(r), sqrt_r(sqrt(r) + 1) {
      small_sieve.resize(sqrt_r);
      iota(small_sieve.begin(), small_sieve.end(), 0);
      large_sieve.resize(r - l);
      aux.assign(r - l, 1);

      for (ll i = 2; i * i < r; i++) {
        if (small_sieve[i] < i)
          continue;

        small_sieve[i] = i;
        for (ll j = i * i; j < sqrt_r; j += i) {
          if (small_sieve[j] == j)
            small_sieve[j] = i;
        }

        ll begin = (l + i - 1) / i * i;

        for (ll j = begin; j < r; j += i) {
          ll k = j;
          do {
            // aux[j - l] > sqrt_r ?
            if (aux[j - l] * aux[j - l] > r)
              break;

            large_sieve[j - l].push_back(i);
            aux[j - l] *= i;
            k /= i;
          } while (k % i == 0);
        }
      }
    }

    vector<ll> factor(ll n) {
      assert(l <= n and n < r);

      vector<ll> res = large_sieve[n - l];
      n /= aux[n - l];

      if (n >= sqrt_r) {
        res.push_back(n);
        return res;
      }

      while (n > 1) {
        res.push_back(small_sieve[n]);
        n /= small_sieve[n];
      }

      return res;
    }
  };
}; // namespace math_library