#pragma once

#include "./base.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <string>

namespace matumoto {
  namespace cpp_int_helper {
    namespace mp = boost::multiprecision;

    string to_string(mp::cpp_int a) {
      string res = "";
      if (a < 0) {
        a *= -1;
        res += "-";
      }

      while (a) {
        res += static_cast<char>(a % 10 + '0');
        a /= 10;
      }
      return res;
    }

    mp::cpp_int gcd(mp::cpp_int a, mp::cpp_int b) {
      mp::cpp_int tmp;
      while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
      }
      return a;
    }

    mp::cpp_int lcm(mp::cpp_int a, mp::cpp_int b) {
      return a * b / gcd(a, b);
    }

    namespace power_helper {

      mp::cpp_int extgcd(mp::cpp_int a, mp::cpp_int b, mp::cpp_int &x, mp::cpp_int &y) {
        if (b == 0) {
          x = 1;
          y = 0;
          return a;
        }
        mp::cpp_int d = extgcd(b, a % b, y, x);
        y = y - (a / b) * x;
        return d;
      }

    } // namespace power_helper

    mp::cpp_int power(mp::cpp_int a, mp::cpp_int e, mp::cpp_int p = -1) {
      assert(p != 0);
      assert(p >= -1);

      if (e < 0) {
        assert(p != -1 and gcd(a, p) == 1);
        mp::cpp_int x, y;
        power_helper::extgcd(a, p, x, y);
        a = (x % p + p) % p;
        e *= -1;
      }

      mp::cpp_int res = 1;
      while (e > 0) {
        if (e & 1) {
          res *= a;
          if (p != -1)
            res %= p;
        }
        a *= a;
        if (p != -1)
          a %= p;
        e >>= 1;
      }
      return res;
    }

  } // namespace cpp_int_helper
  using namespace cpp_int_helper;
  using cint = boost::multiprecision::cpp_int;
} // namespace matumoto