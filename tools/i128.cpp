#include <bits/stdc++.h>
using namespace std;

class i128 {
private:
  __int128_t v;

public:
  i128() {}
  i128(const long long &a) { v = a; }
  i128(const string &s) { parse(s); }

  long long long_val() { return (long long)v; }
  __int128_t val() { return v; }
  __int128_t abs() { return v < 0 ? -v : v; }

  void set(const long long &a) { v = a; }

  void parse(const string &s) {
    v = 0;
    for ( char c : s ) {
      if ( isdigit(c) ) v = v * 10 + (c - '0');
    }
    if ( s[0] == '-' ) v *= -1;
  }

  // clang-format off
  i128 operator+(const i128 &a) { return v + a.v; }
  i128 operator-(const i128 &a) { return v - a.v; }
  i128 operator*(const i128 &a) { return v * a.v; }
  i128 operator/(const i128 &a) { return v / a.v; }
  i128 operator%(const i128 &a) { return v % a.v; }
  i128 operator+=(const i128 &a) { v += a.v; return v; }
  i128 operator-=(const i128 &a) { v -= a.v; return v; }
  i128 operator*=(const i128 &a) { v *= a.v; return v; }
  i128 operator/=(const i128 &a) { v /= a.v; return v; }
  i128 operator%=(const i128 &a) { v %= a.v; return v; }

  template <typename T> i128 operator+(const T &a) { i128 res = *this; res.v += a; return res; }
  template <typename T> i128 operator-(const T &a) { i128 res = *this; res.v -= a; return res; }
  template <typename T> i128 operator*(const T &a) { i128 res = *this; res.v *= a; return res; }
  template <typename T> i128 operator/(const T &a) { i128 res = *this; res.v /= a; return res; }
  template <typename T> i128 operator%(const T &a) { i128 res = *this; res.v %= a; return res; }
  template <typename T> i128 operator+=(const T &a) { v += a; return v; }
  template <typename T> i128 operator-=(const T &a) { v -= a; return v; }
  template <typename T> i128 operator*=(const T &a) { v *= a; return v; }
  template <typename T> i128 operator/=(const T &a) { v /= a; return v; }
  template <typename T> i128 operator%=(const T &a) { v %= a; return v; }

  template <typename T> i128 operator-() { i128 res = *this; res.v *= -1; return res; }

  bool operator<(const i128 &a) { return v < a.v; }
  bool operator>(const i128 &a) { return v > a.v; }
  bool operator<=(const i128 &a) { return v <= a.v; }
  bool operator>=(const i128 &a) { return v >= a.v; }
  bool operator==(const i128 &a) { return v == a.v; }
  bool operator!=(const i128 &a) { return v != a.v; }

  template <typename T> bool operator<(const T &a) { return v < a; }
  template <typename T> bool operator>(const T &a) { return v > a; }
  template <typename T> bool operator<=(const T &a) { return v <= a; }
  template <typename T> bool operator>=(const T &a) { return v >= a; }
  template <typename T> bool operator==(const T &a) { return v == a; }
  template <typename T> bool operator!=(const T &a) { return v != a; }
  // clang-format on

  friend istream &operator>>(istream &is, i128 &v) {
    string s;
    is >> s;
    v.parse(s);
    return is;
  }

  friend ostream &operator<<(ostream &os, const i128 &v) {
    if ( !ostream::sentry(os) ) return os;
    char buf[64];
    char *d = end(buf);
    __uint128_t tmp = (v.v < 0 ? -v.v : v.v);

    do {
      d--;
      *d = char(tmp % 10 + '0');
      tmp /= 10;
    } while ( tmp );
    if ( v.v < 0 ) {
      d--;
      *d = '-';
    }
    int len = end(buf) - d;
    if ( os.rdbuf()->sputn(d, len) != len ) { os.setstate(ios_base::badbit); }
    return os;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  i128 n;
  cin >> n;

  n *= 10;

  cout << n << endl;
}