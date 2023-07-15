---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/alternative-totient.hpp\"\n\n#line 2 \"math/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 2 \"math/factorize.hpp\"\n\n#include <vector>\n\n\
    namespace matumoto {\n  vector<ll> factorize(ll n) {\n    vector<ll> res;\n  \
    \  for (ll i = 2; i * i <= n; i++) {\n      while (n % i == 0) {\n        res.emplace_back(i);\n\
    \        n /= i;\n      }\n    }\n    if (n > 1)\n      res.emplace_back(n);\n\
    \    return res;\n  }\n} // namespace matumoto\n#line 5 \"math/alternative-totient.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"math/alternative-totient.hpp\"\n\nnamespace\
    \ matumoto {\n  long long alternative_totient(long long x, long long n) {\n  \
    \  if (x == 1)\n      return n;\n    auto ps = factorize(x);\n    ps.erase(unique(ps.begin(),\
    \ ps.end()), ps.end());\n    int k = ps.size();\n    long long res = n - x;\n\
    \    for (int i = 1; i < (1 << k); i++) {\n      long long prod = 1;\n      int\
    \ cnt = 0;\n      for (int j = 0; j < k; j++) {\n        if (i >> j & 1) {\n \
    \         prod *= ps[j];\n          cnt++;\n        }\n      }\n      if (cnt\
    \ % 2) {\n        res += (n - x) / prod;\n      } else {\n        res -= (n -\
    \ x) / prod;\n      }\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./factorize.hpp\"\n\n\
    #include <algorithm>\n#include <vector>\n\nnamespace matumoto {\n  long long alternative_totient(long\
    \ long x, long long n) {\n    if (x == 1)\n      return n;\n    auto ps = factorize(x);\n\
    \    ps.erase(unique(ps.begin(), ps.end()), ps.end());\n    int k = ps.size();\n\
    \    long long res = n - x;\n    for (int i = 1; i < (1 << k); i++) {\n      long\
    \ long prod = 1;\n      int cnt = 0;\n      for (int j = 0; j < k; j++) {\n  \
    \      if (i >> j & 1) {\n          prod *= ps[j];\n          cnt++;\n       \
    \ }\n      }\n      if (cnt % 2) {\n        res += (n - x) / prod;\n      } else\
    \ {\n        res -= (n - x) / prod;\n      }\n    }\n    return res;\n  }\n} //\
    \ namespace matumoto\n"
  dependsOn:
  - math/base.hpp
  - math/factorize.hpp
  isVerificationFile: false
  path: math/alternative-totient.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/alternative-totient.hpp
layout: document
redirect_from:
- /library/math/alternative-totient.hpp
- /library/math/alternative-totient.hpp.html
title: math/alternative-totient.hpp
---
