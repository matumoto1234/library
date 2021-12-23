#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_v"
#include <bits/stdc++.h>
using namespace std;

#include "dp/re-rooting-dp.hpp"
using namespace dp;

using ll = long long;
ll m;

ll op(ll a, ll b) {
  return (a * b) % m;
}

ll e() {
  return 1;
}

ll add_node(ll result, int node) {
  return result + 1;
}

int main() {
  ll n;
  cin >> n >> m;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  ReRootingDP<ll, add_node, op, e> dp(n);

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;

    x--, y--;

    dp.add_edge(x, y, 1);
    dp.add_edge(y, x, 1);
  }

  dp.build();

  for (int i = 0; i < n; i++) {
    // 余分に add_node した(存在しない親に対して自分を含めた結果を返している)のがあるので、その分を -1
    ll ans = dp[i] - 1;
    ans %= m;
    cout << ans << endl;
  }
}
