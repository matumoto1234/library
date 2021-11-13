#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct LongestCommonSubsequence {
  vector<T> s, t;
  int h, w;
  vector<vector<int>> dp;
  LongestCommonSubsequence(vector<T> _s, vector<T> _t): s(_s), t(_t) {
    h = _s.size();
    w = _t.size();
  }
  LongestCommonSubsequence(string _s, string _t) {
    h = _s.size(), w = _t.size();
    for (int i = 0; i < h; i++)
      s.emplace_back(_s[i]);
    for (int i = 0; i < w; i++)
      t.emplace_back(_t[i]);
  }

  int build() {
    dp.assign(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
          continue;
        }
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
      }
    }
    return dp[h][w];
  }

  vector<T> restore() {
    vector<T> res;
    int i = h, j = w;
    while (i > 0 and j > 0) {
      if (s[i - 1] == t[j - 1]) {
        res.emplace_back(s[i - 1]);
        i--;
        j--;
        continue;
      }
      if (dp[i - 1][j] > dp[i][j - 1])
        i--;
      else
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

// EDPC_F
int main() {
  string s, t;
  cin >> s >> t;
  LongestCommonSubsequence<char> LCS(s, t);
  int length = LCS.build();
  vector<char> ans = LCS.restore();

  cout << "length:" << length << endl;
  for (auto c: ans)
    cout << c;
  cout << endl;
}