#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct CumulativeSum {
  vector<T> dat;
  CumulativeSum(int n) : dat(n + 1, 0) {}
  CumulativeSum(int n, T x) : dat(n + 1, x) {}

  void set(int k, T x) { dat[k + 1] = x; }

  void add(int k, T x) { dat[k + 1] = x; }

  T get(int k) { return dat[k + 1]; }

  void build() {
    for (size_t i = 0; i < dat.size() - 1; i++) {
      dat[i + 1] += dat[i];
    }
  }

  // [l,r)
  T query(int l, int r) { return dat[r] - dat[l]; }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  CumulativeSum<int> sum(n);
  for (int i = 0; i < n; i++) {
    sum.set(i, a[i]);
  }

  sum.build();

  cout << sum.query(0, n) << endl;
}