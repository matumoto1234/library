#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct DynamicImos {
  vector<T> xs, imos;
  vector<tuple<T, T, T>> intervals;

  DynamicImos() {}

  // [l, r)
  void add(T l, T r, T v) {
    intervals.emplace_back(l, r, v);
    xs.emplace_back(l);
    xs.emplace_back(r);
  }

  void build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    imos.assign(xs.size(), 0);

    for ( auto [l, r, v] : intervals ) {
      l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
      r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
      imos[l] += v;
      imos[r] -= v;
    }

    for ( int i = 1; i < static_cast<int>(imos.size()); i++ ) {
      imos[i] += imos[i - 1];
    }
  }

  // vector<[l,r), value>
  vector<pair<pair<T, T>, T>> interval_values() {
    vector<pair<pair<T, T>, T>> res(xs.size() - 1);
    for ( int i = 0; i < static_cast<int>(xs.size()) - 1; i++ ) {
      T l = xs[i];
      T r = xs[i + 1];
      T v = imos[i];
      res[i] = pair(pair(l, r), v);
    }
    return res;
  }
};