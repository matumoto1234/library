#include <bits/stdc++.h>
using namespace std;

struct divisor_table {
  vector<int> smallest_ps;
  divisor_table(int N) : smallest_ps(N + 1, 1) {}

  void build() {
    int N = smallest_ps.size();
    for (long long i = 2; i <= N; i++) {
      if (smallest_ps[i] != 1) continue;
      smallest_ps[i] = i;
      for (long long j = i * i; j <= N; j += i) {
        if (smallest_ps[j] != 1) continue;
        smallest_ps[j] = i;
      }
    }
  }

  // M := count({ p = prime, p|x })
  // O(M2^M log x)
  vector<int> divisor(int x) {
    vector<int> ps;
    while (smallest_ps[x] != 1) {
      ps.push_back(smallest_ps[x]);
      x /= smallest_ps[x];
    }
    int m = ps.size();
    vector<int> ds(1 << m);
    for (int i = 0; i < (1 << m); i++) {
      int prod = 1;
      for (int j = 0; j < m; j++) {
        if (i >> j & 1) prod *= ps[j];
      }
      ds[i] = prod;
    }
    return ds;
  }

  bool is_prime(int k) {
    if (k <= 1) return false;
    return smallest_ps[k] == k;
  }

  int operator[](int i) { return smallest_ps[i]; }
};

int main() {
}