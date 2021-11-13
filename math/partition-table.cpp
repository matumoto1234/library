#include <bits/stdc++.h>
using namespace std;

template<typename T>
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

int main() {
  int n, k;
  cin >> n >> k;
  auto dp = PartitionTable<int>(n, k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j) cout << ' ';
      cout << dp[i][j];
    }
    cout << endl;
  }
}