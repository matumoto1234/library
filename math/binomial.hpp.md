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
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/binomial.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll binomial(ll n, ll r) {\n    ll res = 1;\n    for (ll i = 0; i < r; i++) {\n\
    \      res *= n - i;\n      res /= i + 1;\n    }\n    return res;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll binomial(ll n, ll r) {\n    ll res = 1;\n    for (ll i = 0; i < r; i++) {\n\
    \      res *= n - i;\n      res /= i + 1;\n    }\n    return res;\n  }\n} // namespace\
    \ matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: math/binomial.hpp
---
