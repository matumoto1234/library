// verification-helper: PROBLEM https://atcoder.jp/contests/abc061/tasks/abc061_d
// verification-helper: IGNORE

#include <bits/stdc++.h>
using namespace std;

#include "graph/bellman-ford.hpp"
using namespace matumoto;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<ll, int>>> adj_list(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    a--;
    b--;

    adj_list[a].emplace_back(-c, b);
  }

  auto bf = BellmanFord<ll>(adj_list, 0, n - 1);
  if (bf.has_negative_cycle()) {
    cout << "inf" << endl;
  } else {
    cout << -bf[n - 1] << endl;
  }
}
