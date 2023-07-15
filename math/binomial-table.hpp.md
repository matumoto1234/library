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
  bundledCode: "#line 2 \"math/binomial-table.hpp\"\n\n#line 2 \"math/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/binomial-table.hpp\"\n\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  struct BinomialTable {\n  \
    \  vector<vector<T>> data;\n    BinomialTable(int N) {\n      data.assign(N +\
    \ 1, vector<T>(N + 1, 0));\n      data[0][0] = 1;\n      for (int i = 0; i < N;\
    \ i++) {\n        for (int j = 0; j <= i; j++) {\n          data[i + 1][j] +=\
    \ data[i][j];\n          data[i + 1][j + 1] += data[i][j];\n        }\n      }\n\
    \    }\n\n    T query(int n, int r) {\n      return data[n][r];\n    }\n  };\n\
    } // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  struct BinomialTable {\n    vector<vector<T>>\
    \ data;\n    BinomialTable(int N) {\n      data.assign(N + 1, vector<T>(N + 1,\
    \ 0));\n      data[0][0] = 1;\n      for (int i = 0; i < N; i++) {\n        for\
    \ (int j = 0; j <= i; j++) {\n          data[i + 1][j] += data[i][j];\n      \
    \    data[i + 1][j + 1] += data[i][j];\n        }\n      }\n    }\n\n    T query(int\
    \ n, int r) {\n      return data[n][r];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/binomial-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial-table.hpp
layout: document
redirect_from:
- /library/math/binomial-table.hpp
- /library/math/binomial-table.hpp.html
title: math/binomial-table.hpp
---
