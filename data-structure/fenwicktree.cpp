#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick_tree {
private:
  int n;
  vector<T> dat;

  // [1,r]
  T sum(int r) {
    T res = 0;
    for (int k = r; k > 0; k -= (k & -k)) {
      res += dat[k];
    }
    return res;
  }

public:
  fenwick_tree(int n_): n(n_ + 2), dat(n_ + 2, 0) {}

  // i:0-indexed
  void add(int i, T x) {
    for (int k = ++i; k < n; k += (k & -k)) {
      dat[k] += x;
    }
  }

  T get(int k) { return dat[++k]; }

  // [l,r)
  T sum(int l, int r) { return sum(r) - sum(l); }

  // min({x | sum(x) >= w})
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0, twopow = 1;
    while (twopow < n) {
      twopow <<= 1;
    }
    for (int sz = twopow; sz > 0; sz >>= 1) {
      if (x + sz < n and dat[x + sz] < w) {
        w -= dat[x + sz];
        x += sz;
      }
    }
    return x;
  }

  // min({x | sum(x) > w})
  int upper_bound(T w) { return lower_bound(w + 1); }
};

// ARC033_C
int main() {
  int q;
  cin >> q;

  fenwick_tree<int> xset(200000);
  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      xset.add(x, 1);
    } else {
      int v = xset.lower_bound(x);
      cout << v << endl;
      xset.add(v, -1);
    }
  }
}