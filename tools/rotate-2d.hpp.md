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
  bundledCode: "#line 2 \"tools/rotate-2d.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/rotate-2d.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  template <typename ArrayType>\n\
    \  vector<ArrayType> rotate_cw(const vector<ArrayType> &s) {\n    int h = s.size(),\
    \ w = s[0].size();\n    vector<ArrayType> res(w);\n    for (int i = 0; i < w;\
    \ i++) {\n      for (int j = 0; j < h; j++) {\n        res[i].push_back(s[h -\
    \ 1 - j][i]);\n      }\n    }\n    return res;\n  }\n\n  template <typename ArrayType>\n\
    \  vector<ArrayType> rotate_ccw(const vector<ArrayType> &s) {\n    int h = s.size(),\
    \ w = s[0].size();\n    vector<ArrayType> res(w);\n    for (int i = 0; i < w;\
    \ i++) {\n      for (int j = 0; j < h; j++) {\n        res[i].push_back(s[j][w\
    \ - 1 - i]);\n      }\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename ArrayType>\n  vector<ArrayType> rotate_cw(const\
    \ vector<ArrayType> &s) {\n    int h = s.size(), w = s[0].size();\n    vector<ArrayType>\
    \ res(w);\n    for (int i = 0; i < w; i++) {\n      for (int j = 0; j < h; j++)\
    \ {\n        res[i].push_back(s[h - 1 - j][i]);\n      }\n    }\n    return res;\n\
    \  }\n\n  template <typename ArrayType>\n  vector<ArrayType> rotate_ccw(const\
    \ vector<ArrayType> &s) {\n    int h = s.size(), w = s[0].size();\n    vector<ArrayType>\
    \ res(w);\n    for (int i = 0; i < w; i++) {\n      for (int j = 0; j < h; j++)\
    \ {\n        res[i].push_back(s[j][w - 1 - i]);\n      }\n    }\n    return res;\n\
    \  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/rotate-2d.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/rotate-2d.hpp
layout: document
redirect_from:
- /library/tools/rotate-2d.hpp
- /library/tools/rotate-2d.hpp.html
title: tools/rotate-2d.hpp
---
