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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/divisor.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \nnamespace matumoto {\n  vector<ll> divisor(ll n) {\n    vector<ll> res;\n  \
    \  for (ll i = 1; i * i <= n; i++) {\n      if (n % i == 0) {\n        res.emplace_back(i);\n\
    \        if (i * i != n)\n          res.emplace_back(n / i);\n      }\n    }\n\
    \    sort(res.begin(), res.end());\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  vector<ll> divisor(ll n) {\n    vector<ll>\
    \ res;\n    for (ll i = 1; i * i <= n; i++) {\n      if (n % i == 0) {\n     \
    \   res.emplace_back(i);\n        if (i * i != n)\n          res.emplace_back(n\
    \ / i);\n      }\n    }\n    sort(res.begin(), res.end());\n    return res;\n\
    \  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: math/divisor.hpp
---
