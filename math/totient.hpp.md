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
  bundledCode: "#line 2 \"math/totient.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/totient.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll totient(ll n) {\n    ll res = n;\n    for (ll i = 2; i * i <= n; i++) {\n\
    \      if (n % i == 0) {\n        res -= res / i;\n        while (n % i == 0)\n\
    \          n /= i;\n      }\n    }\n    if (n > 1)\n      res -= res / n;\n  \
    \  return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ ll totient(ll n) {\n    ll res = n;\n    for (ll i = 2; i * i <= n; i++) {\n\
    \      if (n % i == 0) {\n        res -= res / i;\n        while (n % i == 0)\n\
    \          n /= i;\n      }\n    }\n    if (n > 1)\n      res -= res / n;\n  \
    \  return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/totient.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/totient.hpp
layout: document
redirect_from:
- /library/math/totient.hpp
- /library/math/totient.hpp.html
title: math/totient.hpp
---
