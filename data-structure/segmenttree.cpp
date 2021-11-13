#include <bits/stdc++.h>
using namespace std;

template<typename T, T (*op)(T, T), T (*e)()>
class segment_tree {
private:
  int n;
  vector<T> dat;

  T search(int l, int r) {
    T vl = e(), vr = e();
    l += n, r += n;
    while (l < r) {
      if (l & 1) vl = op(vl, dat[l++]);
      if (r & 1) vr = op(vr, dat[--r]);
      l >>= 1, r >>= 1;
    }
    return op(vl, vr);
  }

public:
  segment_tree() {}
  segment_tree(int _n) { assign(_n); }

  void assign(int _n) {
    n = 1;
    while (n < _n) {
      n <<= 1;
    }
    dat.assign(2 * n, e());
  }

  T get(int i) { return dat[i + n]; }

  void set(int i, T key) {
    i += n;
    dat[i] = key;
    while (i > 0) {
      i >>= 1;
      dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
  }

  // [l, r)
  T prod(int l, int r) { return search(l, r); }

  T all_prod() { return n != 0 ? dat[0] : e(); }
};

int op(int a, int b) {
  return min(a, b);
}

int e() {
  return INT32_MAX;
}

// AOJ_DSL_2_A
int main() {
  int n, q;
  cin >> n >> q;
  segment_tree<int, op, e> seg(n);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.set(x, y);
    } else {
      cout << seg.prod(x, y + 1) << "\n";
    }
  }
  return 0;
}