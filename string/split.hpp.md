---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/base.hpp
    title: string/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/split.hpp\"\n\n#line 2 \"string/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"string/split.hpp\"\n\n#include\
    \ <string>\n#include <vector>\n\nnamespace matumoto {\n  vector<string> split(const\
    \ string &str, const string &sep, const int &max_split = INT32_MAX) {\n    vector<string>\
    \ res;\n    string t = \"\";\n    int cnt_split = 0;\n    for (auto c: str) {\n\
    \      if (sep.find(c) == string::npos or cnt_split >= max_split) {\n        t\
    \ += c;\n        continue;\n      }\n      res.emplace_back(t);\n      t = \"\"\
    ;\n      cnt_split++;\n    }\n    if (t != \"\")\n      res.emplace_back(t);\n\
    \    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  vector<string> split(const string &str, const string\
    \ &sep, const int &max_split = INT32_MAX) {\n    vector<string> res;\n    string\
    \ t = \"\";\n    int cnt_split = 0;\n    for (auto c: str) {\n      if (sep.find(c)\
    \ == string::npos or cnt_split >= max_split) {\n        t += c;\n        continue;\n\
    \      }\n      res.emplace_back(t);\n      t = \"\";\n      cnt_split++;\n  \
    \  }\n    if (t != \"\")\n      res.emplace_back(t);\n    return res;\n  }\n}\
    \ // namespace matumoto"
  dependsOn:
  - string/base.hpp
  isVerificationFile: false
  path: string/split.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/split.hpp
layout: document
redirect_from:
- /library/string/split.hpp
- /library/string/split.hpp.html
title: string/split.hpp
---
