---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':heavy_check_mark:'
    path: math/extgcd.hpp
    title: math/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 2 \"math/extgcd.hpp\"\n\n#line 4 \"math/extgcd.hpp\"\n\nnamespace\
    \ matumoto {\n  constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b ==\
    \ 0) {\n      x = 1;\n      y = 0;\n      return a;\n    }\n    ll d = extgcd(b,\
    \ a % b, y, x);\n    y = y - (a / b) * x;\n    return d;\n  }\n} // namespace\
    \ matumoto\n#line 5 \"math/power.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    \nnamespace matumoto {\n  // verify:AOJ_NTL_1_B\n  constexpr ll power(ll a, ll\
    \ e, ll p = -1) {\n    assert(p != 0);\n    assert(p >= -1);\n\n    if (e < 0)\
    \ {\n      assert(p != -1 and gcd(a, p) == 1);\n      ll x, y;\n      extgcd(a,\
    \ p, x, y);\n      a = (x % p + p) % p;\n      e *= -1;\n    }\n\n    ll res =\
    \ 1;\n    while (e > 0) {\n      if (e & 1) {\n        res *= a;\n        if (p\
    \ != -1)\n          res %= p;\n      }\n      a *= a;\n      if (p != -1)\n  \
    \      a %= p;\n      e >>= 1;\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./extgcd.hpp\"\n\n#include\
    \ <cassert>\n#include <numeric>\n\nnamespace matumoto {\n  // verify:AOJ_NTL_1_B\n\
    \  constexpr ll power(ll a, ll e, ll p = -1) {\n    assert(p != 0);\n    assert(p\
    \ >= -1);\n\n    if (e < 0) {\n      assert(p != -1 and gcd(a, p) == 1);\n   \
    \   ll x, y;\n      extgcd(a, p, x, y);\n      a = (x % p + p) % p;\n      e *=\
    \ -1;\n    }\n\n    ll res = 1;\n    while (e > 0) {\n      if (e & 1) {\n   \
    \     res *= a;\n        if (p != -1)\n          res %= p;\n      }\n      a *=\
    \ a;\n      if (p != -1)\n        a %= p;\n      e >>= 1;\n    }\n    return res;\n\
    \  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  - math/extgcd.hpp
  isVerificationFile: false
  path: math/power.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
