---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':warning:'
    path: math/count-factor.hpp
    title: math/count-factor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/alternative-totient-table.hpp\"\n\n#line 2 \"math/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n  using ll = long long;\n} //\
    \ namespace matumoto\n#line 2 \"math/count-factor.hpp\"\n\n#line 4 \"math/count-factor.hpp\"\
    \n\n#include <cstdint>\n#include <vector>\n\nnamespace matumoto {\n  vector<int>\
    \ count_factor(int N) {\n    constexpr int INF = INT32_MAX / 2;\n    vector<int>\
    \ table(N + 1, 0);\n\n    for (int i = 2; i <= N; i++) {\n      if (table[i])\n\
    \        continue;\n      table[i] = 1;\n      for (int j = 2 * i; j <= N; j +=\
    \ i) {\n        if (j % (i * i) == 0)\n          table[j] = -INF;\n        else\n\
    \          table[j]++;\n      }\n    }\n    return table;\n  }\n} // namespace\
    \ matumoto\n#line 5 \"math/alternative-totient-table.hpp\"\n\n#line 7 \"math/alternative-totient-table.hpp\"\
    \n\nnamespace matumoto {\n  // \u0398(NloglogN)\n  vector<int> alternative_totient_table(int\
    \ N) {\n    vector<int> table = count_factor(N);\n\n    vector<int> alt(N + 1,\
    \ 0);\n    alt[1] = N;\n    for (int i = 2; i <= N; i++) {\n      alt[i] = N -\
    \ i;\n    }\n\n    for (int i = 2; i <= N; i++) {\n      if (table[i] < 0)\n \
    \       continue;\n\n      for (int j = i; j < N; j += i) {\n        if (table[i]\
    \ % 2) {\n          alt[j] -= (N - j) / i;\n        } else {\n          alt[j]\
    \ += (N - j) / i;\n        }\n      }\n    }\n    return alt;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./count-factor.hpp\"\n\
    \n#include <vector>\n\nnamespace matumoto {\n  // \u0398(NloglogN)\n  vector<int>\
    \ alternative_totient_table(int N) {\n    vector<int> table = count_factor(N);\n\
    \n    vector<int> alt(N + 1, 0);\n    alt[1] = N;\n    for (int i = 2; i <= N;\
    \ i++) {\n      alt[i] = N - i;\n    }\n\n    for (int i = 2; i <= N; i++) {\n\
    \      if (table[i] < 0)\n        continue;\n\n      for (int j = i; j < N; j\
    \ += i) {\n        if (table[i] % 2) {\n          alt[j] -= (N - j) / i;\n   \
    \     } else {\n          alt[j] += (N - j) / i;\n        }\n      }\n    }\n\
    \    return alt;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  - math/count-factor.hpp
  isVerificationFile: false
  path: math/alternative-totient-table.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/alternative-totient-table.hpp
layout: document
redirect_from:
- /library/math/alternative-totient-table.hpp
- /library/math/alternative-totient-table.hpp.html
title: math/alternative-totient-table.hpp
---
