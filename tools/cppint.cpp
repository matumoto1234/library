#include <bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>

namespace cpp_int {
  namespace mp = boost::multiprecision;

  string to_string(mp::cpp_int a) {
    string res = "";
    if ( a < 0 ) {
      a *= -1;
      res += "-";
    }

    while ( a ) {
      res += static_cast<char>(a % 10 + '0');
      a /= 10;
    }
    return res;
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

  mp::cpp_int power(mp::cpp_int a, mp::cpp_int e, mp::cpp_int p = -1) {
    bool is_mod_power = false;
    if ( p == -1 )
      is_mod_power = true;
    else if ( p <= 1 )
      return 0;

    mp::cpp_int res = 1;
    while ( e > 0 ) {
      if ( e & 1 ) {
        res *= a;
        if ( is_mod_power ) res %= p;
      }
      a *= a;
      if ( is_mod_power ) a %= p;
      e >>= 1;
    }
    return res;
  }
} // namespace cpp_int
using namespace cpp_int;
using cint = boost::multiprecision::cpp_int;