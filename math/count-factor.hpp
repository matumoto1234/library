#pragma once

#include "./base.hpp"

#include <cstdint>
#include <vector>

namespace matumoto {
  vector<int> count_factor(int N) {
    constexpr int INF = INT32_MAX / 2;
    vector<int> table(N + 1, 0);

    for (int i = 2; i <= N; i++) {
      if (table[i])
        continue;
      table[i] = 1;
      for (int j = 2 * i; j <= N; j += i) {
        if (j % (i * i) == 0)
          table[j] = -INF;
        else
          table[j]++;
      }
    }
    return table;
  }
} // namespace matumoto