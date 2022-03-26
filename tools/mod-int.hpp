#pragma once

#include "./base.hpp"

#include <cassert>
#include <iostream>
#include <optional>
#include <utility>

namespace tools {
  template <int m>
  class ModInt {
    using ll = long long;
    using ull = unsigned long long;
    static_assert(1 <= m);

    unsigned int v_;
    bool has_nullval_;

    static constexpr unsigned int umod() {
      return m;
    }

    constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      ll d = extgcd(b, a % b, y, x);
      y -= a / b * x;
      return d;
    }

    // gcd_inv:()|-> pair(g, x). g := gcd(v, umod()). vx = g (mod umod())
    constexpr pair<ll, ll> gcd_inv() const {
      ll x = 0, y = 0;
      ll d = extgcd(v_, umod(), x, y);
      return pair(d, x);
    }

  public:
    using nullval_t = nullopt_t;
    static constexpr nullval_t nullval = nullopt;

    constexpr ModInt() noexcept: v_(0), has_nullval_(false) {}
    constexpr ModInt(nullval_t x): v_(0), has_nullval_(true) {}
    ModInt(ll x): has_nullval_(false) {
      if (abs(x) >= umod())
        x %= umod();

      if (x < 0)
        x += umod();

      v_ = x;
    }

    constexpr bool has_nullval() const noexcept {
      return has_nullval_;
    }

    constexpr unsigned int val() const noexcept {
      return v_;
    }

    constexpr ModInt &operator++() noexcept {
      v_++;
      if (v_ == umod())
        v_ = 0;
      return *this;
    }

    constexpr ModInt &operator--() noexcept {
      if (v_ == 0)
        v_ = umod();
      v_--;
      return *this;
    }

    constexpr ModInt operator++([[maybe_unused]] int unused) noexcept {
      ModInt old = *this;
      ++*this;
      return old;
    }

    constexpr ModInt operator--([[maybe_unused]] int unused) noexcept {
      ModInt old = *this;
      --*this;
      return old;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {
      v_ += rhs.v_;
      if (v_ >= umod())
        v_ -= umod();
      return *this;
    }

    constexpr ModInt &operator-=(const ModInt &rhs) noexcept {
      v_ -= rhs.v_;
      if (v_ < 0)
        v_ += umod();
      return *this;
    }

    constexpr ModInt &operator*=(const ModInt &rhs) noexcept {
      ull z = v_;
      z *= rhs.v_;
      v_ = z % umod();
      return *this;
    }

    constexpr ModInt operator/=(const ModInt &rhs) {
      assert(rhs.v_ != 0);
      return *this = *this * rhs.inv();
    }

    constexpr ModInt operator+() const noexcept {
      return *this;
    }
    constexpr ModInt operator-() const noexcept {
      return ModInt() - *this;
    }

    constexpr ModInt pow(ll n) const {
      // x = base の 2べき乗
      ModInt x = /* base = */ *this, res = 1;
      if (n < 0) {
        const auto &[gcd, inverse] = gcd_inv();
        assert(gcd == 1);
        x = inverse;
        n *= -1;
      }
      while (n) {
        if (n & 1)
          res *= x;
        x *= x;
        n >>= 1;
      }
      return res;
    }

    constexpr ModInt inv() const {
      const auto &[gcd, inverse] = gcd_inv();
      assert(gcd == 1);
      return inverse;
    }

    constexpr friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) += rhs;
    }

    constexpr friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) -= rhs;
    }

    constexpr friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) *= rhs;
    }

    constexpr friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
      return ModInt(lhs) /= rhs;
    }

    constexpr friend bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept {
      return lhs.v_ == rhs.v_;
    }

    constexpr friend bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept {
      return lhs.v_ != rhs.v_;
    }

    friend istream &operator>>(istream &is, ModInt &rhs) {
      ll temp;
      cin >> temp;
      rhs = ModInt(temp);
      return is;
    }

    friend ostream &operator<<(ostream &os, const ModInt &rhs) {
      os << rhs.val();
      return os;
    }
  };

  using ModInt1000000007 = ModInt<1000000007>;
  using ModInt998244353 = ModInt<998244353>;
} // namespace tools
