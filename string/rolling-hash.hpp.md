---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':heavy_check_mark:'
    path: math/extgcd.hpp
    title: math/extgcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod-inv.hpp
    title: math/mod-inv.hpp
  - icon: ':heavy_check_mark:'
    path: string/base.hpp
    title: string/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/14_B.test.cpp
    title: test/aoj/alds1/14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\n#line 2 \"string/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 2 \"math/mod-inv.hpp\"\
    \n\n#line 2 \"math/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n\
    \  using ll = long long;\n} // namespace matumoto\n#line 2 \"math/extgcd.hpp\"\
    \n\n#line 4 \"math/extgcd.hpp\"\n\nnamespace matumoto {\n  constexpr ll extgcd(ll\
    \ a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n      x = 1;\n      y = 0;\n  \
    \    return a;\n    }\n    ll d = extgcd(b, a % b, y, x);\n    y = y - (a / b)\
    \ * x;\n    return d;\n  }\n} // namespace matumoto\n#line 5 \"math/mod-inv.hpp\"\
    \n\nnamespace matumoto {\n  constexpr ll modinv(ll n, ll mod) {\n    ll x = 0,\
    \ y = 0;\n    extgcd(n, mod, x, y);\n    return (x % mod + mod) % mod;\n  }\n\
    } // namespace matumoto\n#line 5 \"string/rolling-hash.hpp\"\n\n#include <cassert>\n\
    #include <numeric>\n#include <string>\n#include <vector>\n\nnamespace matumoto\
    \ {\n  // recommend { MOD:2^61-1, base:random }\n  template <typename Container,\
    \ long long base = 998244353, long long mod = (1LL << 61) - 1>\n  class RollingHash\
    \ {\n    using i128 = __int128_t;\n    using ll = long long;\n    using ull =\
    \ unsigned long long;\n    static_assert(mod >= 1, \"mod >= 1\");\n    static_assert(gcd(base,\
    \ mod) == 1, \"gcd(base, mod) == 1\");\n\n    static constexpr ll llbase() {\n\
    \      return base;\n    }\n\n    static constexpr ull ullmod() {\n      return\
    \ mod;\n    }\n\n    Container raw_;\n\n    vector<ll> vs_;\n    vector<ull> hash_,\
    \ cumulative_sum_, inv_;\n\n  public:\n    RollingHash(const Container &vs) {\n\
    \      vs_.reserve(vs.size());\n      for (const auto &v: vs) {\n        vs_.emplace_back(v);\n\
    \      }\n      build();\n      raw_ = vs;\n    }\n\n  private:\n    constexpr\
    \ ll mul(ll a, ll b) const {\n      i128 res = a;\n      res *= b;\n      res\
    \ = (res >> 61) + (res & ullmod());\n      if (res >= ullmod()) {\n        res\
    \ -= ullmod();\n      }\n      return ll(res);\n    }\n\n    constexpr ll mod_pow(ll\
    \ a, ll e) const {\n      ll res = 1;\n      while (e > 0) {\n        if (e &\
    \ 1) {\n          res = mul(res, a);\n        }\n        a = mul(a, a);\n    \
    \    e >>= 1;\n      }\n      return res;\n    }\n\n    void build() {\n     \
    \ int n = vs_.size();\n      hash_.assign(n, 0);\n      cumulative_sum_.assign(n\
    \ + 1, 0);\n      inv_.assign(n + 1, 0);\n\n      ull accum_pow = 1;\n      inv_[n]\
    \ = mod_pow(matumoto::modinv(llbase(), ullmod()), n);\n\n      for (int i = 0;\
    \ i < n; i++) {\n        int ri = n - i - 1;\n        inv_[ri] = mul(inv_[ri +\
    \ 1], llbase());\n        hash_[i] = mul(vs_[i], accum_pow);\n\n        ull sum\
    \ = hash_[i] + cumulative_sum_[i];\n        if (sum >= ullmod()) {\n         \
    \ sum -= ullmod();\n        }\n        cumulative_sum_[i + 1] = sum;\n       \
    \ accum_pow = mul(accum_pow, llbase());\n      }\n    }\n\n  public:\n    int\
    \ size() const {\n      return vs_.size();\n    }\n\n    // [l,r)\n    long long\
    \ find(int l, int r) const {\n      ll res = ll(cumulative_sum_[r]) - ll(cumulative_sum_[l]);\n\
    \n      if (res < 0)\n        res += ullmod();\n\n      res = mul(res, inv_[l]);\n\
    \      return (long long)res;\n    }\n\n    long long all() const {\n      return\
    \ find(0, vs_.size());\n    }\n\n    Container raw() const {\n      return raw_;\n\
    \    }\n\n    auto at(int k) const {\n      return raw_.at(k);\n    }\n\n    bool\
    \ operator==(const RollingHash &rhs) const {\n      if (size() != rhs.size())\n\
    \        return false;\n\n      return all() == rhs.all();\n    }\n\n    bool\
    \ operator<(const RollingHash &rhs) const {\n      if (size() != rhs.size())\n\
    \        return false;\n\n      int valid = 1;\n      int invalid = size();\n\
    \      while (abs(valid - invalid) > 1) {\n        int mid = (valid + invalid)\
    \ / 2;\n        if (find(0, mid) == rhs.find(0, mid))\n          valid = mid;\n\
    \        else\n          invalid = mid;\n      }\n\n      int idx = valid + 1;\n\
    \      return raw_.at(idx) < rhs.at(idx);\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"math/mod-inv.hpp\"\n\n\
    #include <cassert>\n#include <numeric>\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  // recommend { MOD:2^61-1, base:random }\n  template\
    \ <typename Container, long long base = 998244353, long long mod = (1LL << 61)\
    \ - 1>\n  class RollingHash {\n    using i128 = __int128_t;\n    using ll = long\
    \ long;\n    using ull = unsigned long long;\n    static_assert(mod >= 1, \"mod\
    \ >= 1\");\n    static_assert(gcd(base, mod) == 1, \"gcd(base, mod) == 1\");\n\
    \n    static constexpr ll llbase() {\n      return base;\n    }\n\n    static\
    \ constexpr ull ullmod() {\n      return mod;\n    }\n\n    Container raw_;\n\n\
    \    vector<ll> vs_;\n    vector<ull> hash_, cumulative_sum_, inv_;\n\n  public:\n\
    \    RollingHash(const Container &vs) {\n      vs_.reserve(vs.size());\n     \
    \ for (const auto &v: vs) {\n        vs_.emplace_back(v);\n      }\n      build();\n\
    \      raw_ = vs;\n    }\n\n  private:\n    constexpr ll mul(ll a, ll b) const\
    \ {\n      i128 res = a;\n      res *= b;\n      res = (res >> 61) + (res & ullmod());\n\
    \      if (res >= ullmod()) {\n        res -= ullmod();\n      }\n      return\
    \ ll(res);\n    }\n\n    constexpr ll mod_pow(ll a, ll e) const {\n      ll res\
    \ = 1;\n      while (e > 0) {\n        if (e & 1) {\n          res = mul(res,\
    \ a);\n        }\n        a = mul(a, a);\n        e >>= 1;\n      }\n      return\
    \ res;\n    }\n\n    void build() {\n      int n = vs_.size();\n      hash_.assign(n,\
    \ 0);\n      cumulative_sum_.assign(n + 1, 0);\n      inv_.assign(n + 1, 0);\n\
    \n      ull accum_pow = 1;\n      inv_[n] = mod_pow(matumoto::modinv(llbase(),\
    \ ullmod()), n);\n\n      for (int i = 0; i < n; i++) {\n        int ri = n -\
    \ i - 1;\n        inv_[ri] = mul(inv_[ri + 1], llbase());\n        hash_[i] =\
    \ mul(vs_[i], accum_pow);\n\n        ull sum = hash_[i] + cumulative_sum_[i];\n\
    \        if (sum >= ullmod()) {\n          sum -= ullmod();\n        }\n     \
    \   cumulative_sum_[i + 1] = sum;\n        accum_pow = mul(accum_pow, llbase());\n\
    \      }\n    }\n\n  public:\n    int size() const {\n      return vs_.size();\n\
    \    }\n\n    // [l,r)\n    long long find(int l, int r) const {\n      ll res\
    \ = ll(cumulative_sum_[r]) - ll(cumulative_sum_[l]);\n\n      if (res < 0)\n \
    \       res += ullmod();\n\n      res = mul(res, inv_[l]);\n      return (long\
    \ long)res;\n    }\n\n    long long all() const {\n      return find(0, vs_.size());\n\
    \    }\n\n    Container raw() const {\n      return raw_;\n    }\n\n    auto at(int\
    \ k) const {\n      return raw_.at(k);\n    }\n\n    bool operator==(const RollingHash\
    \ &rhs) const {\n      if (size() != rhs.size())\n        return false;\n\n  \
    \    return all() == rhs.all();\n    }\n\n    bool operator<(const RollingHash\
    \ &rhs) const {\n      if (size() != rhs.size())\n        return false;\n\n  \
    \    int valid = 1;\n      int invalid = size();\n      while (abs(valid - invalid)\
    \ > 1) {\n        int mid = (valid + invalid) / 2;\n        if (find(0, mid) ==\
    \ rhs.find(0, mid))\n          valid = mid;\n        else\n          invalid =\
    \ mid;\n      }\n\n      int idx = valid + 1;\n      return raw_.at(idx) < rhs.at(idx);\n\
    \    }\n  };\n} // namespace matumoto\n"
  dependsOn:
  - string/base.hpp
  - math/mod-inv.hpp
  - math/base.hpp
  - math/extgcd.hpp
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/14_B.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
