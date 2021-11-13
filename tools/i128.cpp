#include <bits/stdc++.h>
using namespace std;

namespace int128 {
  __int128_t parse(const string &s) {
    __int128_t res = 0;
    for (char c: s) {
      if (isdigit(c)) res = res * 10 + (c - '0');
    }
    if (s[0] == '-') res *= -1;
    return res;
  }

  istream &operator>>(istream &is, __int128_t &v) {
    string s;
    is >> s;
    v = parse(s);
    return is;
  }

  ostream &operator<<(ostream &os, const __int128_t &v) {
    if (!ostream::sentry(os)) return os;
    char buf[64];
    char *d = end(buf);
    __uint128_t tmp = (v < 0 ? -v : v);

    do {
      d--;
      *d = char(tmp % 10 + '0');
      tmp /= 10;
    } while (tmp);
    if (v < 0) {
      d--;
      *d = '-';
    }
    int len = end(buf) - d;
    if (os.rdbuf()->sputn(d, len) != len) { os.setstate(ios_base::badbit); }
    return os;
  }

  __int128_t gcd(__int128_t a, __int128_t b) {
    __int128_t tmp;
    while (b > 0) {
      tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }

  __int128_t lcm(__int128_t a, __int128_t b) { return a * b / gcd(a, b); }


  namespace template_internal_math {

    __int128_t extgcd(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      __int128_t d = extgcd(b, a % b, y, x);
      y = y - (a / b) * x;
      return d;
    }

  } // namespace template_internal_math

  __int128_t power(__int128_t a, __int128_t e, __int128_t p = -1) {
    assert(p != 0);
    assert(p >= -1);

    if (e < 0) {
      assert(p != -1 and gcd(a, p) == 1);
      __int128_t x, y;
      template_internal_math::extgcd(a, p, x, y);
      a = (x % p + p) % p;
      e *= -1;
    }

    __int128_t res = 1;
    while (e > 0) {
      if (e & 1) {
        res *= a;
        if (p != -1) res %= p;
      }
      a *= a;
      if (p != -1) a %= p;
      e >>= 1;
    }
    return res;
  }
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