#include <bits/stdc++.h>
using namespace std;

template <typename T = long long>
struct mexset {
  set<pair<T, T>> s;

  T inf() { return numeric_limits<T>::max() / 2; }

  mexset() {
    s.emplace(inf(), inf());
    s.emplace(-inf(), -inf());
  }

  bool contains(T x) const {
    auto [lower, upper] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    return lower <= x and x <= upper;
  }

  bool insert(T x) {
    if ( contains(x) ) return false;
    auto nit = s.lower_bound(make_pair(x + 1, x + 1));
    auto it = prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if ( u == x - 1 ) {
      if ( nl == x + 1 ) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else {
        s.erase(it);
        s.emplace(l, x);
      }
    } else {
      if ( nl == x + 1 ) {
        s.erase(nit);
        s.emplace(x, nu);
      } else {
        s.emplace(x, x);
      }
    }
    return true;
  }

  bool erase(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    if ( x != l ) s.emplace(l, x - 1);
    if ( x != u ) s.emplace(x + 1, u);
    return true;
  }

  T mex(T x = 0) const {
    auto [l, u] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    if ( l <= x and x <= u ) {
      return u + 1;
    } else {
      return x;
    }
  }
};

// hhkb2020_C
int main() {
  int n;
  cin >> n;

  mexset<int> s;

  for ( int i = 0; i < n; i++ ) {
    int p;
    cin >> p;
    s.insert(p);
    cout << s.mex() << endl;
  }
}