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
  bundledCode: "#line 2 \"string/join.hpp\"\n\n#line 2 \"string/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"string/join.hpp\"\n\n#include\
    \ <string>\n#include <vector>\n\nnamespace matumoto {\n  string join(const vector<string>\
    \ &strs, const string &sep) {\n    string res = \"\";\n    for (int i = 0; i <\
    \ static_cast<int>(strs.size()); i++) {\n      if (i)\n        res += sep;\n \
    \     res += strs[i];\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  string join(const vector<string> &strs, const string\
    \ &sep) {\n    string res = \"\";\n    for (int i = 0; i < static_cast<int>(strs.size());\
    \ i++) {\n      if (i)\n        res += sep;\n      res += strs[i];\n    }\n  \
    \  return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - string/base.hpp
  isVerificationFile: false
  path: string/join.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/join.hpp
layout: document
redirect_from:
- /library/string/join.hpp
- /library/string/join.hpp.html
title: string/join.hpp
---
