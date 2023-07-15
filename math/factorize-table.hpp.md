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
  bundledCode: "#line 2 \"math/factorize-table.hpp\"\n\n#line 2 \"math/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/factorize-table.hpp\"\n\n#include <vector>\n\
    \nnamespace matumoto {\n  struct FactorizeTable {\n    vector<int> ps;\n    FactorizeTable(int\
    \ N): ps(N + 1, 1) {}\n\n    void build() {\n      int N = ps.size();\n      for\
    \ (ll i = 2; i <= N; i++) {\n        if (ps[i] != 1)\n          continue;\n  \
    \      ps[i] = i;\n        for (ll j = i * i; j <= N; j += i) {\n          if\
    \ (ps[j] != 1)\n            continue;\n          ps[j] = i;\n        }\n     \
    \ }\n    }\n\n    vector<int> factorize(int x) {\n      vector<int> res;\n   \
    \   while (ps[x] != 1) {\n        res.push_back(ps[x]);\n        x /= ps[x];\n\
    \      }\n      return res;\n    }\n\n    bool is_prime(int k) {\n      if (k\
    \ <= 1)\n        return false;\n      return ps[k] == k;\n    }\n\n    int operator[](int\
    \ i) {\n      return ps[i];\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct FactorizeTable {\n    vector<int> ps;\n    FactorizeTable(int\
    \ N): ps(N + 1, 1) {}\n\n    void build() {\n      int N = ps.size();\n      for\
    \ (ll i = 2; i <= N; i++) {\n        if (ps[i] != 1)\n          continue;\n  \
    \      ps[i] = i;\n        for (ll j = i * i; j <= N; j += i) {\n          if\
    \ (ps[j] != 1)\n            continue;\n          ps[j] = i;\n        }\n     \
    \ }\n    }\n\n    vector<int> factorize(int x) {\n      vector<int> res;\n   \
    \   while (ps[x] != 1) {\n        res.push_back(ps[x]);\n        x /= ps[x];\n\
    \      }\n      return res;\n    }\n\n    bool is_prime(int k) {\n      if (k\
    \ <= 1)\n        return false;\n      return ps[k] == k;\n    }\n\n    int operator[](int\
    \ i) {\n      return ps[i];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/factorize-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize-table.hpp
layout: document
redirect_from:
- /library/math/factorize-table.hpp
- /library/math/factorize-table.hpp.html
title: math/factorize-table.hpp
---
