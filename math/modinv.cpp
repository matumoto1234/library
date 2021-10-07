#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extgcd(b, a % b, y, x);
  y = y - (a / b) * x;
  return d;
}

ll modinv(ll n, ll mod) {
  ll x, y;
  extgcd(n, mod, x, y);
  return (x % mod + mod) % mod;
}

int main() {
  ll n;
  cin >> n;

  assert(n >= 0);

  constexpr int mod = 1e9 + 7;

  {
    ll inv = modinv(n, mod);
    ll result = (inv * n) % mod;

    assert(result == 1);
    cout << result << endl;
  }

  {
    ll inv = modinv(n, mod);
    inv = (inv * inv) % mod;

    ll result = (n * n) % mod;
    result = (result * inv) % mod;

    assert(result == 1);
    cout << result << endl;
  }
}