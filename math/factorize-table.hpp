#pragma once

#include "./base.hpp"

#include <vector>

namespace matumoto {
  struct FactorizeTable {
    vector<int> ps;
    FactorizeTable(int N): ps(N + 1, 1) {}

    void build() {
      int N = ps.size();
      for (ll i = 2; i <= N; i++) {
        if (ps[i] != 1)
          continue;
        ps[i] = i;
        for (ll j = i * i; j <= N; j += i) {
          if (ps[j] != 1)
            continue;
          ps[j] = i;
        }
      }
    }

    vector<int> factorize(int x) {
      vector<int> res;
      while (ps[x] != 1) {
        res.push_back(ps[x]);
        x /= ps[x];
      }
      return res;
    }

    bool is_prime(int k) {
      if (k <= 1)
        return false;
      return ps[k] == k;
    }

    int operator[](int i) {
      return ps[i];
    }
  };
} // namespace matumoto