#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct binomial_table {
  vector<vector<T>> data;
  binomial_table(int N) {
    data.assign(N + 1, vector<T>(N + 1, 0));
    data[0][0] = 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= i; j++) {
        data[i + 1][j] += data[i][j];
        data[i + 1][j + 1] += data[i][j];
      }
    }
  }

  T query(int n, int r) { return data[n][r]; }
};

int main() {
  int n;
  cin >> n;
  binomial_table<int> table(n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j) cout << " ";
      cout << table.query(i, j);
    }
    cout << "\n";
  }
}