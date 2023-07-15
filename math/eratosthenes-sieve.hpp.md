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
  bundledCode: "#line 2 \"math/eratosthenes-sieve.hpp\"\n\n#line 2 \"math/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/eratosthenes-sieve.hpp\"\n\n#include <vector>\n\
    \nnamespace matumoto {\n  struct EratosthenesSieve {\n    vector<bool> prime_table;\n\
    \n    EratosthenesSieve() {}\n    EratosthenesSieve(int N): prime_table(N + 1,\
    \ true) {\n      prime_table[0] = prime_table[1] = false;\n    }\n\n    void build()\
    \ {\n      int n = prime_table.size();\n      for (ll i = 2; i * i < n; i++) {\n\
    \        if (!prime_table[i])\n          continue;\n        for (ll j = i * i;\
    \ j < n; j += i) {\n          prime_table[j] = false;\n        }\n      }\n  \
    \  }\n\n    bool operator[](int k) {\n      return prime_table[k];\n    }\n  };\n\
    } // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct EratosthenesSieve {\n    vector<bool> prime_table;\n\n\
    \    EratosthenesSieve() {}\n    EratosthenesSieve(int N): prime_table(N + 1,\
    \ true) {\n      prime_table[0] = prime_table[1] = false;\n    }\n\n    void build()\
    \ {\n      int n = prime_table.size();\n      for (ll i = 2; i * i < n; i++) {\n\
    \        if (!prime_table[i])\n          continue;\n        for (ll j = i * i;\
    \ j < n; j += i) {\n          prime_table[j] = false;\n        }\n      }\n  \
    \  }\n\n    bool operator[](int k) {\n      return prime_table[k];\n    }\n  };\n\
    } // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/eratosthenes-sieve.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/eratosthenes-sieve.hpp
layout: document
redirect_from:
- /library/math/eratosthenes-sieve.hpp
- /library/math/eratosthenes-sieve.hpp.html
title: math/eratosthenes-sieve.hpp
---
