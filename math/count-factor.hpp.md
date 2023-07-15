---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/alternative-totient-table.hpp
    title: math/alternative-totient-table.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/count-factor.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/count-factor.hpp\"\n\n#include <cstdint>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  vector<int> count_factor(int N) {\n    constexpr\
    \ int INF = INT32_MAX / 2;\n    vector<int> table(N + 1, 0);\n\n    for (int i\
    \ = 2; i <= N; i++) {\n      if (table[i])\n        continue;\n      table[i]\
    \ = 1;\n      for (int j = 2 * i; j <= N; j += i) {\n        if (j % (i * i) ==\
    \ 0)\n          table[j] = -INF;\n        else\n          table[j]++;\n      }\n\
    \    }\n    return table;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cstdint>\n#include <vector>\n\
    \nnamespace matumoto {\n  vector<int> count_factor(int N) {\n    constexpr int\
    \ INF = INT32_MAX / 2;\n    vector<int> table(N + 1, 0);\n\n    for (int i = 2;\
    \ i <= N; i++) {\n      if (table[i])\n        continue;\n      table[i] = 1;\n\
    \      for (int j = 2 * i; j <= N; j += i) {\n        if (j % (i * i) == 0)\n\
    \          table[j] = -INF;\n        else\n          table[j]++;\n      }\n  \
    \  }\n    return table;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/count-factor.hpp
  requiredBy:
  - math/alternative-totient-table.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/count-factor.hpp
layout: document
redirect_from:
- /library/math/count-factor.hpp
- /library/math/count-factor.hpp.html
title: math/count-factor.hpp
---
