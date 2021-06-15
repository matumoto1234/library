#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> prime_factor(T n) {
  vector<T> res;
  for ( long long i = 2; i * i <= n; i++ ) {
    while ( n % i == 0 ) {
      res.emplace_back(i);
      n /= i;
    }
  }
  if ( n > 1 ) res.emplace_back(n);
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;

  using ll = long long;
  for ( int i = 0; i < q; i++ ) {
    ll n;
    cin >> n;
    vector<ll> ps = prime_factor(n);
    cout << ps.size();
    for ( const auto &p : ps ) {
      cout << ' ' << p;
    }
    cout << '\n';
  }
}