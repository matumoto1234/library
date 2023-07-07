// verification-helper: PROBLEM https://atcoder.jp/contests/abc228/tasks/abc228_d

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/interval-set.hpp"

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q;
  cin >> q;

  matumoto::IntervalSet s;

  constexpr ll mod = 1 << 20;
  vector<ll> a(mod, -1);

  while (q--) {
    int t;
    ll x;
    cin >> t >> x;

    ll mx = x % mod;

    if (t == 1) {
      if (not s.contains(mx)) {
        a[mx] = x;
        s.insert(mx);
        continue;
      }

      auto [l, r] = *s.find(mx);
      if (r != mod) {
        a[r] = x;
        s.insert(r);
        continue;
      }

      if (s.contains(0)) {
        auto [zero, rr] = *s.find(0);
        assert(zero == 0);

        a[rr] = x;
        s.insert(rr);
      } else {
        a[0] = x;
        s.insert(0);
      }
    } else if (t == 2) {
      cout << a[mx] << "\n";
    }
  }
}
