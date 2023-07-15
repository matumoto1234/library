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
  bundledCode: "#line 2 \"tools/to-array.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/to-array.hpp\"\n\n#include\
    \ <array>\n#include <vector>\n\nnamespace matumoto {\n  template <typename T,\
    \ size_t length>\n  array<T, length> to_array(const vector<T> &vs) {\n    array<T,\
    \ length> res;\n    for (int i = 0; i < (int)length; i++) {\n      res[i] = vs[i];\n\
    \    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <array>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T, size_t length>\n  array<T, length>\
    \ to_array(const vector<T> &vs) {\n    array<T, length> res;\n    for (int i =\
    \ 0; i < (int)length; i++) {\n      res[i] = vs[i];\n    }\n    return res;\n\
    \  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/to-array.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/to-array.hpp
layout: document
redirect_from:
- /library/tools/to-array.hpp
- /library/tools/to-array.hpp.html
title: tools/to-array.hpp
---
