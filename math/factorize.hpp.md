---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/alternative-totient.hpp
    title: math/alternative-totient.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/base.hpp\"\n\nnamespace matumoto {\n  using namespace\
    \ std;\n  using ll = long long;\n} // namespace matumoto\n#line 2 \"math/factorize.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  vector<ll> factorize(ll n) {\n\
    \    vector<ll> res;\n    for (ll i = 2; i * i <= n; i++) {\n      while (n %\
    \ i == 0) {\n        res.emplace_back(i);\n        n /= i;\n      }\n    }\n \
    \   if (n > 1)\n      res.emplace_back(n);\n    return res;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace matumoto {\n  vector<ll>\
    \ factorize(ll n) {\n    vector<ll> res;\n    for (ll i = 2; i * i <= n; i++)\
    \ {\n      while (n % i == 0) {\n        res.emplace_back(i);\n        n /= i;\n\
    \      }\n    }\n    if (n > 1)\n      res.emplace_back(n);\n    return res;\n\
    \  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - math/alternative-totient.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
