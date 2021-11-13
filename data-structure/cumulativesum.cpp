#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct cumulative_sum {
  vector<T> dat;
  cumulative_sum(int n): dat(n + 1, 0) {}
  cumulative_sum(int n, T x): dat(n + 1, x) {}

  void set(int k, T x) { dat[k + 1] = x; }

  void build() {
    for (int i = 0; i < static_cast<int>(dat.size()) - 1; i++) {
      dat[i + 1] += dat[i];
    }
  }

  // [l,r)
  T query(int l, int r) { return dat[r] - dat[l]; }

  T operator[](int k) { return dat[k + 1]; }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cumulative_sum<int> sum(n);
  for (int i = 0; i < n; i++) {
    sum.set(i, a[i]);
  }

  sum.build();

  cout << sum.query(0, n) << endl;
}