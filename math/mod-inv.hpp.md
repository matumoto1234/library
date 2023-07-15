---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':heavy_check_mark:'
    path: math/extgcd.hpp
    title: math/extgcd.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: string/rolling-hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/14_B.test.cpp
    title: test/aoj/alds1/14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod-inv.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 2 \"math/extgcd.hpp\"\n\n#line 4 \"math/extgcd.hpp\"\n\nnamespace\
    \ matumoto {\n  constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b ==\
    \ 0) {\n      x = 1;\n      y = 0;\n      return a;\n    }\n    ll d = extgcd(b,\
    \ a % b, y, x);\n    y = y - (a / b) * x;\n    return d;\n  }\n} // namespace\
    \ matumoto\n#line 5 \"math/mod-inv.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll modinv(ll n, ll mod) {\n    ll x = 0, y = 0;\n    extgcd(n, mod, x, y);\n\
    \    return (x % mod + mod) % mod;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./extgcd.hpp\"\n\nnamespace\
    \ matumoto {\n  constexpr ll modinv(ll n, ll mod) {\n    ll x = 0, y = 0;\n  \
    \  extgcd(n, mod, x, y);\n    return (x % mod + mod) % mod;\n  }\n} // namespace\
    \ matumoto"
  dependsOn:
  - math/base.hpp
  - math/extgcd.hpp
  isVerificationFile: false
  path: math/mod-inv.hpp
  requiredBy:
  - string/rolling-hash.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/14_B.test.cpp
documentation_of: math/mod-inv.hpp
layout: document
redirect_from:
- /library/math/mod-inv.hpp
- /library/math/mod-inv.hpp.html
title: math/mod-inv.hpp
---
