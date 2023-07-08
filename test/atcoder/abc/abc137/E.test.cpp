// verification-helper: PROBLEM https://atcoder.jp/contests/abc137/tasks/abc137_e

#include <bits/stdc++.h>
using namespace std;

#include "graph/bellman-ford.hpp"
using namespace matumoto;

using ll = long long;

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<vector<pair<ll, int>>> adj_list(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    a--, b--;

    c -= p;

    adj_list[a].push_back(pair(-c, b));
  }

  auto bf = BellmanFord(adj_list, 0, n - 1);
  if (bf.has_negative_cycle_to_goal()) {
    cout << -1 << endl;
  } else {
    cout << max(0LL, -bf[n - 1]) << endl;
  }
}
