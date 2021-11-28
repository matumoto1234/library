#pragma once

#include "./base.hpp"

#include <cassert>
#include <iostream>
#include <utility>

namespace tools {
  template <int m>
  class ModInt {
    unsigned int v;

    static constexpr unsigned int umod() { return m; }

    void static_assertions() const { static_assert(1 <= m); }

    long long extgcd(long long a, long long b, long long &x, long long &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      long long d = extgcd(b, a % b, y, x);
      y -= a / b * x;
      return d;
    }

    // pair(g, x), g = gcd(v, umod()), vx = g (mod umod())
    pair<long long, long long> gcd_inv() const {
      long long x, y;
      long long d = extgcd(v, umod(), x, y);
      return pair(d, x);
    }

  public:
    ModInt(): v(0) { static_assertions(); }
    ModInt(long long x) {
      static_assertions();
      v = x % umod();
    }

    unsigned int val() const { return v; }

    ModInt &operator++() {
      v++;
      if (v == umod()) v = 0;
      return *this;
    }

    ModInt &operator--() {
      if (v == 0) v = umod();
      v--;
      return *this;
    }

    ModInt operator++([[maybe_unused]] int unused) {
      ModInt old = *this;
      ++*this;
      return old;
    }

    ModInt operator--([[maybe_unused]] int unused) {
      ModInt old = *this;
      --*this;
      return old;
    }

    ModInt &operator+=(const ModInt &rhs) {
      v += rhs.v;
      if (v >= umod()) v -= umod();
      return *this;
    }

    ModInt &operator-=(const ModInt &rhs) {
      v -= rhs.v;
      if (v >= umod()) v += umod();
      return *this;
    }

    ModInt &operator*=(const ModInt &rhs) {
      unsigned long long z = v;
      z *= rhs.v;
      v = z % umod();
      return *this;
    }

    ModInt operator/=(const ModInt &rhs) { return *this = *this * rhs.inv(); }

    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt() - *this; }

    ModInt pow(long long n) const {
      assert(0 <= n);
      ModInt x = *this, res = 1;
      while (n) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
      }
      return res;
    }

    ModInt inv() const {
      const auto &[g, x] = gcd_inv();
      assert(g == 1);
      return x;
    }

    friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) += rhs; }

    friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) -= rhs; }

    friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) *= rhs; }

    friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) /= rhs; }

    friend bool operator==(const ModInt &lhs, const ModInt &rhs) { return lhs.v == rhs.v; }

    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) { return lhs.v != rhs.v; }

    friend istream &operator>>(istream &is, ModInt &rhs) {
      long long temp;
      cin >> temp;
      rhs = ModInt(temp);
      return is;
    }

    friend ostream &operator<<(ostream &os, const ModInt &rhs) {
      os << rhs.val();
      return os;
    }
  };
} // namespace tools