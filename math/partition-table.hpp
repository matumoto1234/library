#pragma once

#include "./base.hpp"

#include <vector>

namespace library_math {
  template <typename T>
  vector<vector<T>> PartitionTable(int n, int k) {
    vector<vector<T>> dp(n + 1, vector<T>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        if (i - j >= 0)
          dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    return dp;
  }
} // namespace library_math