#include <bits/stdc++.h>
using namespace std;

template <typename T>
class fenwick_tree {
private:
  int n;
  vector<T> dat;

  // [1,r]
  T sum(int r) {
    T res = 0;
    for ( int k = r; k > 0; k -= (k & -k) ) {
      res += dat[k];
    }
    return res;
  }

public:
  fenwick_tree(int n_) : n(n_ + 2), dat(n_ + 2, 0) {}

  // i:0-indexed
  void add(int i, T x) {
    for ( int k = ++i; k < n; k += (k & -k) ) {
      dat[k] += x;
    }
  }

  T get(int k) { return dat[++k]; }

  // [l,r)
  T sum(int l, int r) { return sum(r) - sum(l); }

  // min({x | sum(x) >= w})
  int lower_bound(T w) {
    if ( w <= 0 ) return 0;
    int x = 0, twopow = 1;
    while ( twopow < n ) {
      twopow <<= 1;
    }
    for ( int sz = twopow; sz > 0; sz >>= 1 ) {
      if ( x + sz < n and dat[x + sz] < w ) {
        w -= dat[x + sz];
        x += sz;
      }
    }
    return x;
  }

  // min({x | sum(x) > w})
  int upper_bound(T w) { return lower_bound(w + 1); }
};

template <typename T>
long long inversion(vector<T> vs) {

  auto uni = vs;
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for ( T &v : vs ) {
    v = lower_bound(uni.begin(), uni.end(), v) - uni.begin();
  }

  int n = vs.size();
  fenwick_tree<long long> ft(n + 1);
  long long res = 0;
  for ( T v : vs ) {
    res += ft.sum(v + 1, n);
    ft.add(v, 1);
  }
  return res;
}

// AOJ_ALDS1_5_D
int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  for ( int &a : as ) {
    cin >> a;
  }
  cout << inversion(as) << endl;
}