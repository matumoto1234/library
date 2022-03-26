#pragma once

#include "./base.hpp"

#include <vector>

namespace math_library {
  struct EratosthenesSieve {
    vector<bool> prime_table;

    EratosthenesSieve() {}
    EratosthenesSieve(int N): prime_table(N + 1, true) {
      prime_table[0] = prime_table[1] = false;
    }

    void build() {
      int n = prime_table.size();
      for (ll i = 2; i * i < n; i++) {
        if (!prime_table[i])
          continue;
        for (ll j = i * i; j < n; j += i) {
          prime_table[j] = false;
        }
      }
    }

    bool operator[](int k) {
      return prime_table[k];
    }
  };
} // namespace math_library