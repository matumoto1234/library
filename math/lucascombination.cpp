#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct LucasCombination {
  vector<vector<T>> data;
  int MOD;
  LucasCombination(int _MOD) {
    MOD = _MOD;
    data.assign(MOD + 1, vector<T>(MOD + 1, 0));
    data[0][0] = 1;
    for (int i = 0; i < MOD; i++) {
      for (int j = 0; j <= i; j++) {
        data[i + 1][j] += data[i][j];
        data[i + 1][j] %= MOD;
        data[i + 1][j + 1] += data[i][j];
        data[i + 1][j + 1] %= MOD;
      }
    }
  }

  T query(int n, int r) {
    T res = 1;
    while (n > 0) {
      int ni = n % MOD;
      int ri = r % MOD;
      res *= data[ni][ri];
      res %= MOD;
      n /= MOD;
      r /= MOD;
    }
    return res;
  }
};

int main() {
}