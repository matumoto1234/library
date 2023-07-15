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
  bundledCode: "#line 2 \"tools/sliced.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/sliced.hpp\"\n\n#include\
    \ <cassert>\n#include <cstdint>\n#include <string>\n#include <vector>\n\nnamespace\
    \ matumoto {\n  struct Sliced {\n    static constexpr int init = INT32_MAX;\n\
    \    Sliced() {}\n\n    template <typename T>\n    vector<T> operator()(const\
    \ vector<T> &v, int l, int r = init, int stride = init) {\n      assert(stride\
    \ != 0);\n      if (r == init)\n        r = v.size();\n      if (stride == init)\n\
    \        stride = 1;\n      vector<T> res;\n      int start = (stride > 0 ? l\
    \ : r - 1);\n      for (int i = start; (stride > 0 ? i < r : i >= l); i += stride)\
    \ {\n        if (i >= 0) {\n          res.emplace_back(v[i]);\n        } else\
    \ {\n          res.emplace_back(v.end()[i]);\n        }\n      }\n      return\
    \ res;\n    }\n\n    string operator()(const string &s, int l, int r = init, int\
    \ stride = init) {\n      assert(stride != 0);\n      if (r == init)\n       \
    \ r = s.size();\n      if (stride == init)\n        stride = 1;\n      string\
    \ res;\n      int start = (stride > 0 ? l : r - 1);\n      for (int i = start;\
    \ (stride > 0 ? i < r : i >= l); i += stride) {\n        if (i >= 0) {\n     \
    \     res.push_back(s[i]);\n        } else {\n          res.push_back(s.end()[i]);\n\
    \        }\n      }\n      return res;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <string>\n#include <vector>\n\nnamespace matumoto {\n  struct Sliced\
    \ {\n    static constexpr int init = INT32_MAX;\n    Sliced() {}\n\n    template\
    \ <typename T>\n    vector<T> operator()(const vector<T> &v, int l, int r = init,\
    \ int stride = init) {\n      assert(stride != 0);\n      if (r == init)\n   \
    \     r = v.size();\n      if (stride == init)\n        stride = 1;\n      vector<T>\
    \ res;\n      int start = (stride > 0 ? l : r - 1);\n      for (int i = start;\
    \ (stride > 0 ? i < r : i >= l); i += stride) {\n        if (i >= 0) {\n     \
    \     res.emplace_back(v[i]);\n        } else {\n          res.emplace_back(v.end()[i]);\n\
    \        }\n      }\n      return res;\n    }\n\n    string operator()(const string\
    \ &s, int l, int r = init, int stride = init) {\n      assert(stride != 0);\n\
    \      if (r == init)\n        r = s.size();\n      if (stride == init)\n    \
    \    stride = 1;\n      string res;\n      int start = (stride > 0 ? l : r - 1);\n\
    \      for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {\n   \
    \     if (i >= 0) {\n          res.push_back(s[i]);\n        } else {\n      \
    \    res.push_back(s.end()[i]);\n        }\n      }\n      return res;\n    }\n\
    \  };\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/sliced.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/sliced.hpp
layout: document
redirect_from:
- /library/tools/sliced.hpp
- /library/tools/sliced.hpp.html
title: tools/sliced.hpp
---
