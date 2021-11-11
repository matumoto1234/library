#include <bits/stdc++.h>
using namespace std;

template <typename T = long long>
struct pairset {
  set<pair<T, T>> s;

  pairset() {}

  T inf() { return numeric_limits<T>::max() / 2; }

  bool empty() const { return s.empty(); }

  bool contains(T x) const {
    if ( s.empty() ) return false;
    auto [lower, upper] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    return lower <= x and x <= upper;
  }

  // max({ (lower, upper) | lower <= x <= upper })
  pair<T, T> get(T x) {
    if ( !contains(x) ) return make_pair<T, T>(inf(), inf());
    return *prev(s.lower_bound(make_pair(x + 1, x + 1)));
  }

  bool insert(T x) {
    if ( contains(x) ) return false;
    auto nit = s.lower_bound(make_pair(x + 1, x + 1));
    auto it = prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if ( u == x - 1 and nl == x + 1 ) {
      s.erase(it);
      s.erase(nit);
      s.emplace(l, nu);
    } else if ( u == x - 1 and nl != x + 1 ) {
      s.erase(it);
      s.emplace(l, x);
    } else if ( u != x - 1 and nl == x + 1 ) {
      s.erase(nit);
      s.emplace(x, nu);
    } else if ( u != x - 1 and nl != x + 1 ) {
      s.emplace(x, x);
    }
    return true;
  }

  bool insert(T x, T y) {
    if ( x > y ) swap(x, y);
    bool xflg = contains(x);
    bool yflg = contains(y);
    if ( xflg and yflg ) {
      auto xit = prev(s.lower_bound(make_pair(x + 1, x + 1)));
      auto yit = prev(s.lower_bound(make_pair(y + 1, y + 1)));
      if ( xit == yit ) return false;
      auto [xl, xu] = *xit;
      auto [yl, yu] = *yit;
      s.erase(xit);
      s.erase(yit);
      s.emplace(xl, yu);
    } else if ( xflg and !yflg ) {
      auto xit = prev(s.lower_bound(make_pair(x + 1, x + 1)));
      auto [xl, xu] = *xit;
      s.erase(xit);
      s.emplace(xl, y);
    } else if ( !xflg and yflg ) {
      auto yit = prev(s.lower_bound(make_pair(y + 1, y + 1)));
      auto [yl, yu] = *yit;
      s.erase(yit);
      s.emplace(x, yu);
    } else if ( !xflg and !yflg ) {
      s.emplace(x, y);
    }
    return true;
  }

  bool insert(pair<T, T> p) { return insert(p.first, p.second); }

  // { (l, u) | l <= x <= u } => { (l, x - 1), (x + 1, u) | l <= x <= u }
  bool erase(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    if ( x != l ) s.emplace(l, x - 1);
    if ( x != u ) s.emplace(x + 1, u);
    return true;
  }

  // { (l, u) | l <= x <= u } => { (l, x), (x, u) | l <= x <= u }
  bool cut(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    s.emplace(l, x);
    s.emplace(x, u);
    return true;
  }
};

// ABC217_D
int main() {
  int l, q;
  cin >> l >> q;

  pairset<int> s;

  s.insert(0, l);

  while ( q-- ) {
    int c, x;
    cin >> c >> x;
    if ( c == 1 ) {
      s.cut(x);
    } else {
      auto [lower, upper] = s.get(x);
      cout << upper - lower << endl;
    }
  }
}