#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Compress {
  vector<T> xs;
  Compress() {}
  Compress(int N) : xs(N, 0) {}
  Compress(const vector<T> &vs) : xs(vs) {}

  void add(T x) { xs.emplace_back(x); }
  void add(const vector<T> &vs) {
    for ( const T &x : vs ) {
      xs.emplace_back(x);
    }
  }

  void build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
  }

  vector<T> get(const vector<T> &vs) {
    vector<T> res = vs;
    for ( T &x : res ) {
      x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    return res;
  }

  int get(T k) const {
    return lower_bound(xs.begin(), xs.end(), k) - xs.begin();
  }

  const T &operator[](int k) const { return xs[k]; }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  Compress<int> comp(a);
}