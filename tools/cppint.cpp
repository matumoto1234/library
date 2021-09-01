#include <bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>

namespace cpp_int {
  namespace mp = boost::multiprecision;
  mp::cpp_int parse(const string &s) {
    mp::cpp_int res = 0;
    for ( char c : s ) {
      if ( isdigit(c) ) res = res * 10 + (c - '0');
    }
    if ( s[0] == '-' ) res *= -1;
    return res;
  }

  istream &operator>>(istream &is, mp::cpp_int &v) {
    string s;
    is >> s;
    v = parse(s);
    return is;
  }

  ostream &operator<<(ostream &os, const mp::cpp_int &v) {
    if ( !ostream::sentry(os) ) return os;
    char buf[64];
    char *d = end(buf);
    mp::cpp_int tmp = (v < 0 ? -v : v);

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

  mp::cpp_int gcd(mp::cpp_int a, mp::cpp_int b) {
    mp::cpp_int tmp;
    while ( b > 0 ) {
      tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }

  mp::cpp_int lcm(mp::cpp_int a, mp::cpp_int b) { return a * b / gcd(a, b); }
} // namespace cpp_int
using namespace cpp_int;
using cint = boost::multiprecision::cpp_int;