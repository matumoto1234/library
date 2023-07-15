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
  bundledCode: "#line 2 \"math/divisor-table.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/divisor-table.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct DivisorTable {\n    vector<int> smallest_ps;\n    DivisorTable(int\
    \ N): smallest_ps(N + 1, 1) {}\n\n    void build() {\n      int N = smallest_ps.size();\n\
    \      for (long long i = 2; i <= N; i++) {\n        if (smallest_ps[i] != 1)\n\
    \          continue;\n        smallest_ps[i] = i;\n        for (long long j =\
    \ i * i; j <= N; j += i) {\n          if (smallest_ps[j] != 1)\n            continue;\n\
    \          smallest_ps[j] = i;\n        }\n      }\n    }\n\n    // M := count({\
    \ p = prime, p|x })\n    // O(M2^M log x)\n    vector<int> divisor(int x) {\n\
    \      vector<int> ps;\n      while (smallest_ps[x] != 1) {\n        ps.push_back(smallest_ps[x]);\n\
    \        x /= smallest_ps[x];\n      }\n      int m = ps.size();\n      vector<int>\
    \ ds(1 << m);\n      for (int i = 0; i < (1 << m); i++) {\n        int prod =\
    \ 1;\n        for (int j = 0; j < m; j++) {\n          if (i >> j & 1)\n     \
    \       prod *= ps[j];\n        }\n        ds[i] = prod;\n      }\n      return\
    \ ds;\n    }\n\n    bool is_prime(int k) {\n      if (k <= 1)\n        return\
    \ false;\n      return smallest_ps[k] == k;\n    }\n\n    int operator[](int i)\
    \ {\n      return smallest_ps[i];\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct DivisorTable {\n    vector<int> smallest_ps;\n    DivisorTable(int\
    \ N): smallest_ps(N + 1, 1) {}\n\n    void build() {\n      int N = smallest_ps.size();\n\
    \      for (long long i = 2; i <= N; i++) {\n        if (smallest_ps[i] != 1)\n\
    \          continue;\n        smallest_ps[i] = i;\n        for (long long j =\
    \ i * i; j <= N; j += i) {\n          if (smallest_ps[j] != 1)\n            continue;\n\
    \          smallest_ps[j] = i;\n        }\n      }\n    }\n\n    // M := count({\
    \ p = prime, p|x })\n    // O(M2^M log x)\n    vector<int> divisor(int x) {\n\
    \      vector<int> ps;\n      while (smallest_ps[x] != 1) {\n        ps.push_back(smallest_ps[x]);\n\
    \        x /= smallest_ps[x];\n      }\n      int m = ps.size();\n      vector<int>\
    \ ds(1 << m);\n      for (int i = 0; i < (1 << m); i++) {\n        int prod =\
    \ 1;\n        for (int j = 0; j < m; j++) {\n          if (i >> j & 1)\n     \
    \       prod *= ps[j];\n        }\n        ds[i] = prod;\n      }\n      return\
    \ ds;\n    }\n\n    bool is_prime(int k) {\n      if (k <= 1)\n        return\
    \ false;\n      return smallest_ps[k] == k;\n    }\n\n    int operator[](int i)\
    \ {\n      return smallest_ps[i];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/divisor-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor-table.hpp
layout: document
redirect_from:
- /library/math/divisor-table.hpp
- /library/math/divisor-table.hpp.html
title: math/divisor-table.hpp
---
