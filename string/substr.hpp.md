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
  bundledCode: "#line 2 \"string/substr.hpp\"\n\n#line 2 \"string/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"string/substr.hpp\"\n\n#include\
    \ <string>\n\nnamespace matumoto {\n  string substr(const string &s, int l, int\
    \ r) {\n    string res = \"\";\n    for (int i = l; i < r; i++) {\n      res +=\
    \ s[i];\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n\nnamespace\
    \ matumoto {\n  string substr(const string &s, int l, int r) {\n    string res\
    \ = \"\";\n    for (int i = l; i < r; i++) {\n      res += s[i];\n    }\n    return\
    \ res;\n  }\n} // namespace matumoto"
  dependsOn:
  - string/base.hpp
  isVerificationFile: false
  path: string/substr.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/substr.hpp
layout: document
redirect_from:
- /library/string/substr.hpp
- /library/string/substr.hpp.html
title: string/substr.hpp
---
