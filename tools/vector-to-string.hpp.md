---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/vector-to-string.hpp\"\n\n#line 2 \"tools/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/vector-to-string.hpp\"\
    \n\n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  template <typename\
    \ T>\n  string vector_to_string(const vector<T> &vs, const string &sep = \" \"\
    ) {\n    stringstream ss;\n    for (int i = 0; i < static_cast<int>(vs.size());\
    \ i++) {\n      if (i)\n        ss << sep;\n      ss << vs[i];\n    }\n    return\
    \ ss.str();\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  string vector_to_string(const\
    \ vector<T> &vs, const string &sep = \" \") {\n    stringstream ss;\n    for (int\
    \ i = 0; i < static_cast<int>(vs.size()); i++) {\n      if (i)\n        ss <<\
    \ sep;\n      ss << vs[i];\n    }\n    return ss.str();\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/vector-to-string.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/vector-to-string.hpp
layout: document
redirect_from:
- /library/tools/vector-to-string.hpp
- /library/tools/vector-to-string.hpp.html
title: tools/vector-to-string.hpp
---
