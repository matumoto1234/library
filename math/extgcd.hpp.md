---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/mod-inv.hpp
    title: math/mod-inv.hpp
  - icon: ':warning:'
    path: math/power.hpp
    title: math/power.hpp
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
  bundledCode: "#line 2 \"math/extgcd.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/extgcd.hpp\"\n\nnamespace matumoto {\n  constexpr ll\
    \ extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n      x = 1;\n      y\
    \ = 0;\n      return a;\n    }\n    ll d = extgcd(b, a % b, y, x);\n    y = y\
    \ - (a / b) * x;\n    return d;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n      x = 1;\n   \
    \   y = 0;\n      return a;\n    }\n    ll d = extgcd(b, a % b, y, x);\n    y\
    \ = y - (a / b) * x;\n    return d;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy:
  - string/rolling-hash.hpp
  - math/mod-inv.hpp
  - math/power.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/14_B.test.cpp
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: math/extgcd.hpp
---
