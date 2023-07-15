---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/other/edpc/H.test.cpp
    title: test/atcoder/other/edpc/H.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/mod-int.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/mod-int.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <optional>\n#include <utility>\n\n\
    namespace matumoto {\n  template <int m>\n  class ModInt {\n    using ll = long\
    \ long;\n    using ull = unsigned long long;\n    static_assert(1 <= m);\n\n \
    \   unsigned int v_;\n    bool has_nullval_;\n\n    static constexpr unsigned\
    \ int umod() {\n      return m;\n    }\n\n    constexpr ll extgcd(ll a, ll b,\
    \ ll &x, ll &y) {\n      if (b == 0) {\n        x = 1;\n        y = 0;\n     \
    \   return a;\n      }\n      ll d = extgcd(b, a % b, y, x);\n      y -= a / b\
    \ * x;\n      return d;\n    }\n\n    // gcd_inv:()|-> pair(g, x). g := gcd(v,\
    \ umod()). vx = g (mod umod())\n    constexpr pair<ll, ll> gcd_inv() const {\n\
    \      ll x = 0, y = 0;\n      ll d = extgcd(v_, umod(), x, y);\n      return\
    \ pair(d, x);\n    }\n\n  public:\n    using nullval_t = nullopt_t;\n    static\
    \ constexpr nullval_t nullval = nullopt;\n\n    constexpr ModInt() noexcept: v_(0),\
    \ has_nullval_(false) {}\n    constexpr ModInt(nullval_t x): v_(0), has_nullval_(true)\
    \ {}\n    ModInt(ll x): has_nullval_(false) {\n      if (abs(x) >= umod())\n \
    \       x %= umod();\n\n      if (x < 0)\n        x += umod();\n\n      v_ = x;\n\
    \    }\n\n    constexpr bool has_nullval() const noexcept {\n      return has_nullval_;\n\
    \    }\n\n    constexpr unsigned int val() const noexcept {\n      return v_;\n\
    \    }\n\n    constexpr ModInt &operator++() noexcept {\n      v_++;\n      if\
    \ (v_ == umod())\n        v_ = 0;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt &operator--() noexcept {\n      if (v_ == 0)\n        v_ = umod();\n\
    \      v_--;\n      return *this;\n    }\n\n    constexpr ModInt operator++([[maybe_unused]]\
    \ int unused) noexcept {\n      ModInt old = *this;\n      ++*this;\n      return\
    \ old;\n    }\n\n    constexpr ModInt operator--([[maybe_unused]] int unused)\
    \ noexcept {\n      ModInt old = *this;\n      --*this;\n      return old;\n \
    \   }\n\n    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {\n    \
    \  v_ += rhs.v_;\n      if (v_ >= umod())\n        v_ -= umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n      v_ -= rhs.v_;\n      if (v_ < 0)\n        v_ += umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator*=(const ModInt &rhs) noexcept\
    \ {\n      ull z = v_;\n      z *= rhs.v_;\n      v_ = z % umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt operator/=(const ModInt &rhs) {\n    \
    \  assert(rhs.v_ != 0);\n      return *this = *this * rhs.inv();\n    }\n\n  \
    \  constexpr ModInt operator+() const noexcept {\n      return *this;\n    }\n\
    \    constexpr ModInt operator-() const noexcept {\n      return ModInt() - *this;\n\
    \    }\n\n    constexpr ModInt pow(ll n) const {\n      // x = base \u306E 2\u3079\
    \u304D\u4E57\n      ModInt x = /* base = */ *this, res = 1;\n      if (n < 0)\
    \ {\n        const auto &[gcd, inverse] = gcd_inv();\n        assert(gcd == 1);\n\
    \        x = inverse;\n        n *= -1;\n      }\n      while (n) {\n        if\
    \ (n & 1)\n          res *= x;\n        x *= x;\n        n >>= 1;\n      }\n \
    \     return res;\n    }\n\n    constexpr ModInt inv() const {\n      const auto\
    \ &[gcd, inverse] = gcd_inv();\n      assert(gcd == 1);\n      return inverse;\n\
    \    }\n\n    constexpr friend ModInt operator+(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return ModInt(lhs) += rhs;\n    }\n\n    constexpr friend\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept {\n      return\
    \ ModInt(lhs) -= rhs;\n    }\n\n    constexpr friend ModInt operator*(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept {\n      return ModInt(lhs) *= rhs;\n    }\n\
    \n    constexpr friend ModInt operator/(const ModInt &lhs, const ModInt &rhs)\
    \ {\n      return ModInt(lhs) /= rhs;\n    }\n\n    constexpr friend bool operator==(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept {\n      return lhs.v_ == rhs.v_;\n\
    \    }\n\n    constexpr friend bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return lhs.v_ != rhs.v_;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &rhs) {\n      ll temp;\n      is >> temp;\n\
    \      rhs = ModInt(temp);\n      return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &rhs) {\n      os << rhs.val();\n      return os;\n    }\n\
    \  };\n\n  using ModInt1000000007 = ModInt<1000000007>;\n  using ModInt998244353\
    \ = ModInt<998244353>;\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <optional>\n#include <utility>\n\nnamespace matumoto {\n  template <int\
    \ m>\n  class ModInt {\n    using ll = long long;\n    using ull = unsigned long\
    \ long;\n    static_assert(1 <= m);\n\n    unsigned int v_;\n    bool has_nullval_;\n\
    \n    static constexpr unsigned int umod() {\n      return m;\n    }\n\n    constexpr\
    \ ll extgcd(ll a, ll b, ll &x, ll &y) {\n      if (b == 0) {\n        x = 1;\n\
    \        y = 0;\n        return a;\n      }\n      ll d = extgcd(b, a % b, y,\
    \ x);\n      y -= a / b * x;\n      return d;\n    }\n\n    // gcd_inv:()|-> pair(g,\
    \ x). g := gcd(v, umod()). vx = g (mod umod())\n    constexpr pair<ll, ll> gcd_inv()\
    \ const {\n      ll x = 0, y = 0;\n      ll d = extgcd(v_, umod(), x, y);\n  \
    \    return pair(d, x);\n    }\n\n  public:\n    using nullval_t = nullopt_t;\n\
    \    static constexpr nullval_t nullval = nullopt;\n\n    constexpr ModInt() noexcept:\
    \ v_(0), has_nullval_(false) {}\n    constexpr ModInt(nullval_t x): v_(0), has_nullval_(true)\
    \ {}\n    ModInt(ll x): has_nullval_(false) {\n      if (abs(x) >= umod())\n \
    \       x %= umod();\n\n      if (x < 0)\n        x += umod();\n\n      v_ = x;\n\
    \    }\n\n    constexpr bool has_nullval() const noexcept {\n      return has_nullval_;\n\
    \    }\n\n    constexpr unsigned int val() const noexcept {\n      return v_;\n\
    \    }\n\n    constexpr ModInt &operator++() noexcept {\n      v_++;\n      if\
    \ (v_ == umod())\n        v_ = 0;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt &operator--() noexcept {\n      if (v_ == 0)\n        v_ = umod();\n\
    \      v_--;\n      return *this;\n    }\n\n    constexpr ModInt operator++([[maybe_unused]]\
    \ int unused) noexcept {\n      ModInt old = *this;\n      ++*this;\n      return\
    \ old;\n    }\n\n    constexpr ModInt operator--([[maybe_unused]] int unused)\
    \ noexcept {\n      ModInt old = *this;\n      --*this;\n      return old;\n \
    \   }\n\n    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {\n    \
    \  v_ += rhs.v_;\n      if (v_ >= umod())\n        v_ -= umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n      v_ -= rhs.v_;\n      if (v_ < 0)\n        v_ += umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator*=(const ModInt &rhs) noexcept\
    \ {\n      ull z = v_;\n      z *= rhs.v_;\n      v_ = z % umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt operator/=(const ModInt &rhs) {\n    \
    \  assert(rhs.v_ != 0);\n      return *this = *this * rhs.inv();\n    }\n\n  \
    \  constexpr ModInt operator+() const noexcept {\n      return *this;\n    }\n\
    \    constexpr ModInt operator-() const noexcept {\n      return ModInt() - *this;\n\
    \    }\n\n    constexpr ModInt pow(ll n) const {\n      // x = base \u306E 2\u3079\
    \u304D\u4E57\n      ModInt x = /* base = */ *this, res = 1;\n      if (n < 0)\
    \ {\n        const auto &[gcd, inverse] = gcd_inv();\n        assert(gcd == 1);\n\
    \        x = inverse;\n        n *= -1;\n      }\n      while (n) {\n        if\
    \ (n & 1)\n          res *= x;\n        x *= x;\n        n >>= 1;\n      }\n \
    \     return res;\n    }\n\n    constexpr ModInt inv() const {\n      const auto\
    \ &[gcd, inverse] = gcd_inv();\n      assert(gcd == 1);\n      return inverse;\n\
    \    }\n\n    constexpr friend ModInt operator+(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return ModInt(lhs) += rhs;\n    }\n\n    constexpr friend\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept {\n      return\
    \ ModInt(lhs) -= rhs;\n    }\n\n    constexpr friend ModInt operator*(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept {\n      return ModInt(lhs) *= rhs;\n    }\n\
    \n    constexpr friend ModInt operator/(const ModInt &lhs, const ModInt &rhs)\
    \ {\n      return ModInt(lhs) /= rhs;\n    }\n\n    constexpr friend bool operator==(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept {\n      return lhs.v_ == rhs.v_;\n\
    \    }\n\n    constexpr friend bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return lhs.v_ != rhs.v_;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &rhs) {\n      ll temp;\n      is >> temp;\n\
    \      rhs = ModInt(temp);\n      return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &rhs) {\n      os << rhs.val();\n      return os;\n    }\n\
    \  };\n\n  using ModInt1000000007 = ModInt<1000000007>;\n  using ModInt998244353\
    \ = ModInt<998244353>;\n} // namespace matumoto\n"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/mod-int.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/other/edpc/H.test.cpp
documentation_of: tools/mod-int.hpp
layout: document
redirect_from:
- /library/tools/mod-int.hpp
- /library/tools/mod-int.hpp.html
title: tools/mod-int.hpp
---
