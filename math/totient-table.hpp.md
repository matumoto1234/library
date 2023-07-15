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
  bundledCode: "#line 2 \"math/totient-table.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/totient-table.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  vector<int> totient_table(int n) {\n    vector<int> euler(n +\
    \ 1);\n    for (int i = 0; i <= n; i++) {\n      euler[i] = i;\n    }\n    for\
    \ (int i = 2; i <= n; i++) {\n      if (euler[i] == i) {\n        for (int j =\
    \ i; j <= n; j += i) {\n          euler[j] = euler[j] / i * (i - 1);\n       \
    \ }\n      }\n    }\n    return euler;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  vector<int> totient_table(int n) {\n    vector<int> euler(n +\
    \ 1);\n    for (int i = 0; i <= n; i++) {\n      euler[i] = i;\n    }\n    for\
    \ (int i = 2; i <= n; i++) {\n      if (euler[i] == i) {\n        for (int j =\
    \ i; j <= n; j += i) {\n          euler[j] = euler[j] / i * (i - 1);\n       \
    \ }\n      }\n    }\n    return euler;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/totient-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/totient-table.hpp
layout: document
redirect_from:
- /library/math/totient-table.hpp
- /library/math/totient-table.hpp.html
title: math/totient-table.hpp
---
