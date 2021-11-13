#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Compress {
  vector<T> xs;
  Compress() {}
  Compress(int N): xs(N, 0) {}
  Compress(const vector<T> &vs): xs(vs) {}

  void set(int i, T x) { xs[i] = x; }

  void set(const vector<T> &vs) {
    for (int i = 0; i < min<int>(xs.size(), vs.size()); i++) {
      xs[i] = vs[i];
    }
  }

  void add(T x) { xs.emplace_back(x); }

  void add(const vector<T> &vs) {
    for (const T &x: vs) {
      xs.emplace_back(x);
    }
  }

  Compress<T> build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    return *this;
  }

  vector<T> get(const vector<T> &vs) const {
    vector<T> res = vs;
    for (T &x: res) {
      x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    return res;
  }

  int get(T k) const { return lower_bound(xs.begin(), xs.end(), k) - xs.begin(); }

  const T &operator[](int k) const { return xs[k]; }
};

// ABC036_C
int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  for (auto &a: as)
    cin >> a;

  vector<int> Compressed = Compress(as).build().get(as);
  for (auto x: Compressed) {
    cout << x << "\n";
  }
}