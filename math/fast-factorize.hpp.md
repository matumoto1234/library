---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fast-factorize.hpp\"\n\n#line 2 \"math/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/fast-factorize.hpp\"\n\n#include <atcoder/modint>\n\
    #include <cstdint>\n#include <cstdlib>\n#include <vector>\n\nnamespace matumoto\
    \ {\n  namespace inner {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    using i64 = int64_t;\n    using u128 = __uint128_t;\n\n    u64 gcd_impl(u64\
    \ n, u64 m) {\n      constexpr u64 K = 5;\n      for (int i = 0; i < 80; ++i)\
    \ {\n        u64 t = n - m;\n        u64 s = n - m * K;\n        bool q = t <\
    \ m;\n        bool p = t < m * K;\n        n = q ? m : t;\n        m = q ? t :\
    \ m;\n        if (m == 0)\n          return n;\n        n = p ? n : s;\n     \
    \ }\n      return gcd_impl(m, n % m);\n    }\n\n    u64 gcd_pre(u64 n, u64 m)\
    \ {\n      for (int i = 0; i < 4; ++i) {\n        u64 t = n - m;\n        bool\
    \ q = t < m;\n        n = q ? m : t;\n        m = q ? t : m;\n        if (m ==\
    \ 0)\n          return n;\n      }\n      return gcd_impl(n, m);\n    }\n\n  \
    \  u64 gcd_fast(u64 n, u64 m) {\n      return n > m ? gcd_pre(n, m) : gcd_pre(m,\
    \ n);\n    }\n\n    struct modint64 {\n      using u64 = uint64_t;\n\n    public:\n\
    \      static u64 mod;\n      static u64 r, n2;\n      static void set_mod(u64\
    \ m) {\n        mod = m;\n        n2 = -u128(m) % m;\n        r = get_r();\n \
    \       assert(r * mod == 1);\n      }\n      modint64(): a(0) {}\n      modint64(const\
    \ i64 &b): a(reduce((u128(b) + mod) * n2)) {}\n\n      modint64 &operator+=(const\
    \ modint64 &b) {\n        if (i64(a += b.a - 2 * mod) < 0)\n          a += 2 *\
    \ mod;\n        return *this;\n      }\n\n      modint64 &operator-=(const modint64\
    \ &b) {\n        if (i64(a -= b.a) < 0)\n          a += 2 * mod;\n        return\
    \ *this;\n      }\n\n      modint64 &operator*=(const modint64 &b) {\n       \
    \ a = reduce(u128(a) * b.a);\n        return *this;\n      }\n\n      modint64\
    \ &operator/=(const modint64 &b) {\n        *this *= b.inverse();\n        return\
    \ *this;\n      }\n\n      modint64 operator+(const modint64 &b) const {\n   \
    \     return modint64(*this) += b;\n      }\n      modint64 operator-(const modint64\
    \ &b) const {\n        return modint64(*this) -= b;\n      }\n      modint64 operator*(const\
    \ modint64 &b) const {\n        return modint64(*this) *= b;\n      }\n      modint64\
    \ operator/(const modint64 &b) const {\n        return modint64(*this) /= b;\n\
    \      }\n\n      modint64 pow(u128 n) const {\n        modint64 ret(1), mul(*this);\n\
    \        while (n > 0) {\n          if (n & 1)\n            ret *= mul;\n    \
    \      mul *= mul;\n          n >>= 1;\n        }\n        return ret;\n     \
    \ }\n\n      modint64 inverse() const {\n        return pow(mod - 2);\n      }\n\
    \n      u64 val() const {\n        u64 ret = reduce(a);\n        return ret >=\
    \ mod ? ret - mod : ret;\n      }\n\n      static u64 get_mod() {\n        return\
    \ mod;\n      }\n\n    private:\n      u64 a;\n\n      static u64 get_r() {\n\
    \        u64 ret = mod;\n        for (int i = 0; i < 5; i++)\n          ret *=\
    \ 2 - mod * ret;\n        return ret;\n      }\n\n      static u64 reduce(const\
    \ u128 &b) {\n        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n     \
    \ }\n    };\n    typename modint64::u64 modint64::mod, modint64::r, modint64::n2;\n\
    \n    u64 rnd() {\n      static u64 x = 10150724397891781847ull;\n      x ^= x\
    \ << 7;\n      return x ^= x >> 9;\n    }\n\n    bool is_prime(const u64 n) {\n\
    \      if (~n & 1)\n        return n == 2;\n      if (n < (1ll << 30))\n     \
    \   return atcoder::internal::is_prime_constexpr(n);\n      u64 d = n - 1;\n \
    \     while (~d & 1)\n        d >>= 1;\n      if (modint64::get_mod() != n)\n\
    \        modint64::set_mod(n);\n      for (const u64 a: { 2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022 }) {\n        if (n <= a)\n          break;\n  \
    \      modint64 t = d, y = modint64(a).pow(d);\n        while (t.val() != n -\
    \ 1 and y.val() != 1 and y.val() != n - 1) {\n          y *= y;\n          t *=\
    \ 2;\n        }\n        if (y.val() != n - 1 and ~t.val() & 1)\n          return\
    \ false;\n      }\n      return true;\n    }\n\n    u64 pollard_rho(const u64\
    \ n) {\n      if (~n & 1)\n        return 2;\n      if (is_prime(n))\n       \
    \ return n;\n      if (modint64::get_mod() != n)\n        modint64::set_mod(n);\n\
    \      modint64 R, one = 1;\n      auto f = [&](modint64 x) {\n        return\
    \ x * x + R;\n      };\n      auto rng = [&]() {\n        return rnd() % (n -\
    \ 2) + 2;\n      };\n      for (;;) {\n        modint64 x, y(rng()), ys, q = one;\n\
    \        R = rng();\n        u64 g = 1;\n        constexpr int m = 128;\n    \
    \    for (int r = 1; g == 1; r <<= 1) {\n          x = y;\n          for (int\
    \ i = 0; i < r; i++)\n            y = f(y);\n          for (int k = 0; g == 1\
    \ and k < r; k += m) {\n            ys = y;\n            for (int i = 0; i < m\
    \ and i < r - k; i++)\n              q *= x - (y = f(y));\n            g = gcd_fast(q.val(),\
    \ n);\n          }\n        }\n        if (g == n)\n          do\n           \
    \ g = gcd_fast((x - (ys = f(ys))).val(), n);\n          while (g == 1);\n    \
    \    if (g != n)\n          return g;\n      }\n      exit(1);\n    }\n\n    std::vector<u64>\
    \ factorize(const u64 n) {\n      if (n == 1)\n        return {};\n      if (is_prime(n))\n\
    \        return { n };\n      auto d = pollard_rho(n);\n      auto res = factorize(d);\n\
    \      auto sub = factorize(n / d);\n      std::copy(sub.begin(), sub.end(), std::back_inserter(res));\n\
    \      return res;\n    }\n\n  }; // namespace inner\n  using inner::is_prime;\n\
    \n  template <typename ll>\n  std::vector<ll> fast_factorize(const ll n) {\n \
    \   auto tmp = inner::factorize(n);\n    std::vector<ll> res{ tmp.begin(), tmp.end()\
    \ };\n    std::sort(res.begin(), res.end());\n    return res;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <atcoder/modint>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <vector>\n\nnamespace matumoto {\n \
    \ namespace inner {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n  \
    \  using i64 = int64_t;\n    using u128 = __uint128_t;\n\n    u64 gcd_impl(u64\
    \ n, u64 m) {\n      constexpr u64 K = 5;\n      for (int i = 0; i < 80; ++i)\
    \ {\n        u64 t = n - m;\n        u64 s = n - m * K;\n        bool q = t <\
    \ m;\n        bool p = t < m * K;\n        n = q ? m : t;\n        m = q ? t :\
    \ m;\n        if (m == 0)\n          return n;\n        n = p ? n : s;\n     \
    \ }\n      return gcd_impl(m, n % m);\n    }\n\n    u64 gcd_pre(u64 n, u64 m)\
    \ {\n      for (int i = 0; i < 4; ++i) {\n        u64 t = n - m;\n        bool\
    \ q = t < m;\n        n = q ? m : t;\n        m = q ? t : m;\n        if (m ==\
    \ 0)\n          return n;\n      }\n      return gcd_impl(n, m);\n    }\n\n  \
    \  u64 gcd_fast(u64 n, u64 m) {\n      return n > m ? gcd_pre(n, m) : gcd_pre(m,\
    \ n);\n    }\n\n    struct modint64 {\n      using u64 = uint64_t;\n\n    public:\n\
    \      static u64 mod;\n      static u64 r, n2;\n      static void set_mod(u64\
    \ m) {\n        mod = m;\n        n2 = -u128(m) % m;\n        r = get_r();\n \
    \       assert(r * mod == 1);\n      }\n      modint64(): a(0) {}\n      modint64(const\
    \ i64 &b): a(reduce((u128(b) + mod) * n2)) {}\n\n      modint64 &operator+=(const\
    \ modint64 &b) {\n        if (i64(a += b.a - 2 * mod) < 0)\n          a += 2 *\
    \ mod;\n        return *this;\n      }\n\n      modint64 &operator-=(const modint64\
    \ &b) {\n        if (i64(a -= b.a) < 0)\n          a += 2 * mod;\n        return\
    \ *this;\n      }\n\n      modint64 &operator*=(const modint64 &b) {\n       \
    \ a = reduce(u128(a) * b.a);\n        return *this;\n      }\n\n      modint64\
    \ &operator/=(const modint64 &b) {\n        *this *= b.inverse();\n        return\
    \ *this;\n      }\n\n      modint64 operator+(const modint64 &b) const {\n   \
    \     return modint64(*this) += b;\n      }\n      modint64 operator-(const modint64\
    \ &b) const {\n        return modint64(*this) -= b;\n      }\n      modint64 operator*(const\
    \ modint64 &b) const {\n        return modint64(*this) *= b;\n      }\n      modint64\
    \ operator/(const modint64 &b) const {\n        return modint64(*this) /= b;\n\
    \      }\n\n      modint64 pow(u128 n) const {\n        modint64 ret(1), mul(*this);\n\
    \        while (n > 0) {\n          if (n & 1)\n            ret *= mul;\n    \
    \      mul *= mul;\n          n >>= 1;\n        }\n        return ret;\n     \
    \ }\n\n      modint64 inverse() const {\n        return pow(mod - 2);\n      }\n\
    \n      u64 val() const {\n        u64 ret = reduce(a);\n        return ret >=\
    \ mod ? ret - mod : ret;\n      }\n\n      static u64 get_mod() {\n        return\
    \ mod;\n      }\n\n    private:\n      u64 a;\n\n      static u64 get_r() {\n\
    \        u64 ret = mod;\n        for (int i = 0; i < 5; i++)\n          ret *=\
    \ 2 - mod * ret;\n        return ret;\n      }\n\n      static u64 reduce(const\
    \ u128 &b) {\n        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n     \
    \ }\n    };\n    typename modint64::u64 modint64::mod, modint64::r, modint64::n2;\n\
    \n    u64 rnd() {\n      static u64 x = 10150724397891781847ull;\n      x ^= x\
    \ << 7;\n      return x ^= x >> 9;\n    }\n\n    bool is_prime(const u64 n) {\n\
    \      if (~n & 1)\n        return n == 2;\n      if (n < (1ll << 30))\n     \
    \   return atcoder::internal::is_prime_constexpr(n);\n      u64 d = n - 1;\n \
    \     while (~d & 1)\n        d >>= 1;\n      if (modint64::get_mod() != n)\n\
    \        modint64::set_mod(n);\n      for (const u64 a: { 2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022 }) {\n        if (n <= a)\n          break;\n  \
    \      modint64 t = d, y = modint64(a).pow(d);\n        while (t.val() != n -\
    \ 1 and y.val() != 1 and y.val() != n - 1) {\n          y *= y;\n          t *=\
    \ 2;\n        }\n        if (y.val() != n - 1 and ~t.val() & 1)\n          return\
    \ false;\n      }\n      return true;\n    }\n\n    u64 pollard_rho(const u64\
    \ n) {\n      if (~n & 1)\n        return 2;\n      if (is_prime(n))\n       \
    \ return n;\n      if (modint64::get_mod() != n)\n        modint64::set_mod(n);\n\
    \      modint64 R, one = 1;\n      auto f = [&](modint64 x) {\n        return\
    \ x * x + R;\n      };\n      auto rng = [&]() {\n        return rnd() % (n -\
    \ 2) + 2;\n      };\n      for (;;) {\n        modint64 x, y(rng()), ys, q = one;\n\
    \        R = rng();\n        u64 g = 1;\n        constexpr int m = 128;\n    \
    \    for (int r = 1; g == 1; r <<= 1) {\n          x = y;\n          for (int\
    \ i = 0; i < r; i++)\n            y = f(y);\n          for (int k = 0; g == 1\
    \ and k < r; k += m) {\n            ys = y;\n            for (int i = 0; i < m\
    \ and i < r - k; i++)\n              q *= x - (y = f(y));\n            g = gcd_fast(q.val(),\
    \ n);\n          }\n        }\n        if (g == n)\n          do\n           \
    \ g = gcd_fast((x - (ys = f(ys))).val(), n);\n          while (g == 1);\n    \
    \    if (g != n)\n          return g;\n      }\n      exit(1);\n    }\n\n    std::vector<u64>\
    \ factorize(const u64 n) {\n      if (n == 1)\n        return {};\n      if (is_prime(n))\n\
    \        return { n };\n      auto d = pollard_rho(n);\n      auto res = factorize(d);\n\
    \      auto sub = factorize(n / d);\n      std::copy(sub.begin(), sub.end(), std::back_inserter(res));\n\
    \      return res;\n    }\n\n  }; // namespace inner\n  using inner::is_prime;\n\
    \n  template <typename ll>\n  std::vector<ll> fast_factorize(const ll n) {\n \
    \   auto tmp = inner::factorize(n);\n    std::vector<ll> res{ tmp.begin(), tmp.end()\
    \ };\n    std::sort(res.begin(), res.end());\n    return res;\n  }\n} // namespace\
    \ matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/fast-factorize.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast-factorize.hpp
layout: document
redirect_from:
- /library/math/fast-factorize.hpp
- /library/math/fast-factorize.hpp.html
title: math/fast-factorize.hpp
---
