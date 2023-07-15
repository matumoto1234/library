---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/base.hpp
    title: dp/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/longest-common-subsequence.hpp\"\n\n#line 2 \"dp/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"dp/longest-common-subsequence.hpp\"\
    \n\n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  // verify:EDPC_F\n\
    \  template <typename T>\n  struct LongestCommonSubsequence {\n    vector<T> s,\
    \ t;\n    int h, w;\n    vector<vector<int>> dp;\n    LongestCommonSubsequence(vector<T>\
    \ _s, vector<T> _t): s(_s), t(_t) {\n      h = _s.size();\n      w = _t.size();\n\
    \    }\n    LongestCommonSubsequence(string _s, string _t) {\n      h = _s.size(),\
    \ w = _t.size();\n      for (int i = 0; i < h; i++)\n        s.emplace_back(_s[i]);\n\
    \      for (int i = 0; i < w; i++)\n        t.emplace_back(_t[i]);\n    }\n\n\
    \    int build() {\n      dp.assign(h + 1, vector<int>(w + 1, 0));\n      for\
    \ (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n         \
    \ if (s[i] == t[j]) {\n            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]\
    \ + 1);\n            continue;\n          }\n          dp[i + 1][j] = max(dp[i\
    \ + 1][j], dp[i][j]);\n          dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);\n\
    \        }\n      }\n      return dp[h][w];\n    }\n\n    vector<T> restore()\
    \ {\n      vector<T> res;\n      int i = h, j = w;\n      while (i > 0 and j >\
    \ 0) {\n        if (s[i - 1] == t[j - 1]) {\n          res.emplace_back(s[i -\
    \ 1]);\n          i--;\n          j--;\n          continue;\n        }\n     \
    \   if (dp[i - 1][j] > dp[i][j - 1])\n          i--;\n        else\n         \
    \ j--;\n      }\n      reverse(res.begin(), res.end());\n      return res;\n \
    \   }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  // verify:EDPC_F\n  template <typename T>\n  struct\
    \ LongestCommonSubsequence {\n    vector<T> s, t;\n    int h, w;\n    vector<vector<int>>\
    \ dp;\n    LongestCommonSubsequence(vector<T> _s, vector<T> _t): s(_s), t(_t)\
    \ {\n      h = _s.size();\n      w = _t.size();\n    }\n    LongestCommonSubsequence(string\
    \ _s, string _t) {\n      h = _s.size(), w = _t.size();\n      for (int i = 0;\
    \ i < h; i++)\n        s.emplace_back(_s[i]);\n      for (int i = 0; i < w; i++)\n\
    \        t.emplace_back(_t[i]);\n    }\n\n    int build() {\n      dp.assign(h\
    \ + 1, vector<int>(w + 1, 0));\n      for (int i = 0; i < h; i++) {\n        for\
    \ (int j = 0; j < w; j++) {\n          if (s[i] == t[j]) {\n            dp[i +\
    \ 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n            continue;\n  \
    \        }\n          dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);\n          dp[i][j\
    \ + 1] = max(dp[i][j + 1], dp[i][j]);\n        }\n      }\n      return dp[h][w];\n\
    \    }\n\n    vector<T> restore() {\n      vector<T> res;\n      int i = h, j\
    \ = w;\n      while (i > 0 and j > 0) {\n        if (s[i - 1] == t[j - 1]) {\n\
    \          res.emplace_back(s[i - 1]);\n          i--;\n          j--;\n     \
    \     continue;\n        }\n        if (dp[i - 1][j] > dp[i][j - 1])\n       \
    \   i--;\n        else\n          j--;\n      }\n      reverse(res.begin(), res.end());\n\
    \      return res;\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - dp/base.hpp
  isVerificationFile: false
  path: dp/longest-common-subsequence.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/longest-common-subsequence.hpp
layout: document
redirect_from:
- /library/dp/longest-common-subsequence.hpp
- /library/dp/longest-common-subsequence.hpp.html
title: dp/longest-common-subsequence.hpp
---
