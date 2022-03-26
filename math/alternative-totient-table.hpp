#pragma once

#include "./base.hpp"
#include "./count-factor.hpp"

#include <vector>

namespace math_library {
  // Θ(NloglogN)
  vector<int> alternative_totient_table(int N) {
    vector<int> table = count_factor(N);

    vector<int> alt(N + 1, 0);
    alt[1] = N;
    for (int i = 2; i <= N; i++) {
      alt[i] = N - i;
    }

    for (int i = 2; i <= N; i++) {
      if (table[i] < 0)
        continue;

      for (int j = i; j < N; j += i) {
        if (table[i] % 2) {
          alt[j] -= (N - j) / i;
        } else {
          alt[j] += (N - j) / i;
        }
      }
    }
    return alt;
  }
} // namespace math_library