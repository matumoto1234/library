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
  bundledCode: "#line 2 \"math/lucas-combination.hpp\"\n\n#line 2 \"math/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/lucas-combination.hpp\"\n\n#include <vector>\n\
    \nnamespace matumoto {\n  struct LucasCombination {\n    vector<vector<ll>> data;\n\
    \    int MOD;\n    LucasCombination(int MOD_) {\n      MOD = MOD_;\n      data.assign(MOD\
    \ + 1, vector<ll>(MOD + 1, 0));\n      data[0][0] = 1;\n      for (int i = 0;\
    \ i < MOD; i++) {\n        for (int j = 0; j <= i; j++) {\n          data[i +\
    \ 1][j] += data[i][j];\n          data[i + 1][j] %= MOD;\n          data[i + 1][j\
    \ + 1] += data[i][j];\n          data[i + 1][j + 1] %= MOD;\n        }\n     \
    \ }\n    }\n\n    ll query(int n, int r) {\n      ll res = 1;\n      while (n\
    \ > 0) {\n        int ni = n % MOD;\n        int ri = r % MOD;\n        res *=\
    \ data[ni][ri];\n        res %= MOD;\n        n /= MOD;\n        r /= MOD;\n \
    \     }\n      return res;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct LucasCombination {\n    vector<vector<ll>> data;\n    int\
    \ MOD;\n    LucasCombination(int MOD_) {\n      MOD = MOD_;\n      data.assign(MOD\
    \ + 1, vector<ll>(MOD + 1, 0));\n      data[0][0] = 1;\n      for (int i = 0;\
    \ i < MOD; i++) {\n        for (int j = 0; j <= i; j++) {\n          data[i +\
    \ 1][j] += data[i][j];\n          data[i + 1][j] %= MOD;\n          data[i + 1][j\
    \ + 1] += data[i][j];\n          data[i + 1][j + 1] %= MOD;\n        }\n     \
    \ }\n    }\n\n    ll query(int n, int r) {\n      ll res = 1;\n      while (n\
    \ > 0) {\n        int ni = n % MOD;\n        int ri = r % MOD;\n        res *=\
    \ data[ni][ri];\n        res %= MOD;\n        n /= MOD;\n        r /= MOD;\n \
    \     }\n      return res;\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/lucas-combination.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lucas-combination.hpp
layout: document
redirect_from:
- /library/math/lucas-combination.hpp
- /library/math/lucas-combination.hpp.html
title: math/lucas-combination.hpp
---
