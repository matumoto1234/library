#pragma once

#include "./base.hpp"
#include "math/mod-inv.hpp"

#include <cassert>
#include <numeric>
#include <string>
#include <variant>
#include <vector>

namespace string_library {
  // recommend { MOD:2^61-1, base:random }
  template <typename Container, long long base = 998244353, long long mod = (1LL << 61) - 1>
  class RollingHash {
    using i128 = __int128_t;
    using ll = long long;
    using ull = unsigned long long;
    static_assert(mod >= 1, "mod >= 1");
    static_assert(gcd(base, mod) == 1, "gcd(base, mod) == 1");

    static constexpr ll llbase() {
      return base;
    }

    static constexpr ull ullmod() {
      return mod;
    }

    Container raw_;

    vector<ll> vs_;
    vector<ull> hash_, cumulative_sum_, inv_;

  public:
    RollingHash(const Container &vs) {
      vs_.reserve(vs.size());
      for (const auto &v: vs) {
        vs_.emplace_back(v);
      }
      build();
      raw_ = vs;
    }

  private:
    constexpr ll mul(ll a, ll b) const {
      i128 res = a;
      res *= b;
      res = (res >> 61) + (res & ullmod());
      if (res >= ullmod()) {
        res -= ullmod();
      }
      return ll(res);
    }

    constexpr ll mod_pow(ll a, ll e) const {
      ll res = 1;
      while (e > 0) {
        if (e & 1) {
          res = mul(res, a);
        }
        a = mul(a, a);
        e >>= 1;
      }
      return res;
    }

    void build() {
      int n = vs_.size();
      hash_.assign(n, 0);
      cumulative_sum_.assign(n + 1, 0);
      inv_.assign(n + 1, 0);

      ull accum_pow = 1;
      inv_[n] = mod_pow(math_library::modinv(llbase(), ullmod()), n);

      for (int i = 0; i < n; i++) {
        int ri = n - i - 1;
        inv_[ri] = mul(inv_[ri + 1], llbase());
        hash_[i] = mul(vs_[i], accum_pow);

        ull sum = hash_[i] + cumulative_sum_[i];
        if (sum >= ullmod()) {
          sum -= ullmod();
        }
        cumulative_sum_[i + 1] = sum;
        accum_pow = mul(accum_pow, llbase());
      }
    }

  public:
    int size() const {
      return vs_.size();
    }

    // [l,r)
    long long find(int l, int r) const {
      ll res = ll(cumulative_sum_[r]) - ll(cumulative_sum_[l]);

      if (res < 0)
        res += ullmod();

      res = mul(res, inv_[l]);
      return (long long)res;
    }

    long long all() const {
      return find(0, vs_.size());
    }

    Container raw() const {
      return raw_;
    }

    auto at(int k) const {
      return raw_.at(k);
    }

    bool operator==(const RollingHash &rhs) const {
      if (size() != rhs.size())
        return false;

      return all() == rhs.all();
    }

    bool operator<(const RollingHash &rhs) const {
      if (size() != rhs.size())
        return false;

      int valid = 1;
      int invalid = size();
      while (abs(valid - invalid) > 1) {
        int mid = (valid + invalid) / 2;
        if (find(0, mid) == rhs.find(0, mid))
          valid = mid;
        else
          invalid = mid;
      }

      int idx = valid + 1;
      return raw_.at(idx) < rhs.at(idx);
    }
  };
} // namespace string_library
