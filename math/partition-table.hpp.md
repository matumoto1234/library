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
  bundledCode: "#line 2 \"math/partition-table.hpp\"\n\n#line 2 \"math/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 4 \"math/partition-table.hpp\"\n\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  vector<vector<T>> PartitionTable(int\
    \ n, int k) {\n    vector<vector<T>> dp(n + 1, vector<T>(k + 1));\n    dp[0][0]\
    \ = 1;\n    for (int i = 0; i <= n; i++) {\n      for (int j = 1; j <= k; j++)\
    \ {\n        if (i - j >= 0)\n          dp[i][j] = dp[i][j - 1] + dp[i - j][j];\n\
    \        else\n          dp[i][j] = dp[i][j - 1];\n      }\n    }\n    return\
    \ dp;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  vector<vector<T>> PartitionTable(int\
    \ n, int k) {\n    vector<vector<T>> dp(n + 1, vector<T>(k + 1));\n    dp[0][0]\
    \ = 1;\n    for (int i = 0; i <= n; i++) {\n      for (int j = 1; j <= k; j++)\
    \ {\n        if (i - j >= 0)\n          dp[i][j] = dp[i][j - 1] + dp[i - j][j];\n\
    \        else\n          dp[i][j] = dp[i][j - 1];\n      }\n    }\n    return\
    \ dp;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/partition-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/partition-table.hpp
layout: document
redirect_from:
- /library/math/partition-table.hpp
- /library/math/partition-table.hpp.html
title: math/partition-table.hpp
---
