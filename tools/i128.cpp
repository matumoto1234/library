#include <bits/stdc++.h>
using namespace std;

namespace int128 {
  __int128_t parse(const string &s) {
    __int128_t res = 0;
    for ( char c : s ) {
      if ( isdigit(c) ) res = res * 10 + (c - '0');
    }
    if ( s[0] == '-' ) res *= -1;
    return res;
  }

  istream &operator>>(istream &is, __int128_t &v) {
    string s;
    is >> s;
    v = parse(s);
    return is;
  }

  ostream &operator<<(ostream &os, const __int128_t &v) {
    if ( !ostream::sentry(os) ) return os;
    char buf[64];
    char *d = end(buf);
    __uint128_t tmp = (v < 0 ? -v : v);

    do {
      d--;
      *d = char(tmp % 10 + '0');
      tmp /= 10;
    } while ( tmp );
    if ( v < 0 ) {
      d--;
      *d = '-';
    }
    int len = end(buf) - d;
    if ( os.rdbuf()->sputn(d, len) != len ) { os.setstate(ios_base::badbit); }
    return os;
  }

  __int128_t gcd(__int128_t a, __int128_t b) {
    __int128_t tmp;
    while ( b > 0 ) {
      tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }

  __int128_t lcm(__int128_t a, __int128_t b) { return a * b / gcd(a, b); }
} // namespace int128
using namespace int128;
using i128 = __int128_t;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  i128 n;
  cin >> n;

  n *= 10;

  cout << n << endl;
}