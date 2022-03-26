#pragma once

#include "./base.hpp"

#include <string>
#include <vector>

namespace library_string {
  // verify:AOJ_ALDS1_14_B
  // recommend { MOD:2^61-1, base:random }
  struct RollingHash {
    using i128 = __int128_t;
    using ll = long long;
    ll base, mod;
    vector<ll> dat, hash, cumulative_sum, inv;
    RollingHash(vector<ll> vs, ll B = (int)1e9 + 7, ll MOD = (1LL << 61) - 1): dat(vs) {
      set_base(B);
      set_mod(MOD);
    }
    RollingHash(string &s, ll B = (int)1e9 + 7, ll MOD = (1LL << 61) - 1) {
      for (char c: s) {
        dat.emplace_back(c);
      }
      set_base(B);
      set_mod(MOD);
    }

    void set_base(ll B) {
      base = B;
    }
    void set_mod(ll MOD) {
      mod = MOD;
    }

    // mod multiprecation
    ll mod_mul(ll a, ll b) {
      i128 res = a;
      res *= b;
      res = (res >> 61) + (res & mod);
      if (res >= mod)
        res -= mod;
      return (ll)res;
    }

    ll pow(ll a, i128 e) {
      if (e == 0)
        return 1;
      if (e % 2 == 0) {
        ll res = pow(a, e / 2);
        return mod_mul(res, res);
      }
      return mod_mul(pow(a, e - 1), a);
    }

    void build() {
      int n = dat.size();
      hash.assign(n, 0);
      cumulative_sum.assign(n + 1, 0);
      inv.assign(n + 1, 0);
      vector<ll> pow_table(n + 1);

      i128 e = mod - 2;
      inv[n] = pow(base, n * e);
      pow_table[0] = 1;

      for (int i = n - 1; i >= 0; i--) {
        pow_table[n - i] = mod_mul(pow_table[n - i - 1], base);
        inv[i] = mod_mul(inv[i + 1], base);
      }
      for (int i = 0; i < n; i++) {
        hash[i] = mod_mul(dat[i], pow_table[i]);
      }
      for (int i = 0; i < n; i++) {
        cumulative_sum[i + 1] = (hash[i] + cumulative_sum[i]) % mod;
      }
    }

    // [l,r)
    long long find(int l, int r) {
      ll res = cumulative_sum[r] - cumulative_sum[l];
      if (res < 0)
        res += mod;
      res = mod_mul(res, inv[l]);
      return (long long)res;
    }
  };
} // namespace library_string