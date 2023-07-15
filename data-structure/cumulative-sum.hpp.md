---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cumulative-sum.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/cumulative-sum.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  template <typename T>\n  struct\
    \ CumulativeSum {\n    vector<T> data;\n    CumulativeSum(int n): data(n + 1,\
    \ 0) {}\n    CumulativeSum(int n, T x): data(n + 1, x) {}\n\n    void set(int\
    \ k, T x) {\n      data[k + 1] = x;\n    }\n\n    void add(int k, T x) {\n   \
    \   data[k + 1] = x;\n    }\n\n    T get(int k) {\n      return data[k + 1];\n\
    \    }\n\n    void build() {\n      for (int i = 0; i < static_cast<int>(data.size())\
    \ - 1; i++) {\n        data[i + 1] += data[i];\n      }\n    }\n\n    // [l,r)\n\
    \    T query(int l, int r) {\n      return data[r] - data[l];\n    }\n  };\n}\
    \ // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  struct CumulativeSum {\n    vector<T>\
    \ data;\n    CumulativeSum(int n): data(n + 1, 0) {}\n    CumulativeSum(int n,\
    \ T x): data(n + 1, x) {}\n\n    void set(int k, T x) {\n      data[k + 1] = x;\n\
    \    }\n\n    void add(int k, T x) {\n      data[k + 1] = x;\n    }\n\n    T get(int\
    \ k) {\n      return data[k + 1];\n    }\n\n    void build() {\n      for (int\
    \ i = 0; i < static_cast<int>(data.size()) - 1; i++) {\n        data[i + 1] +=\
    \ data[i];\n      }\n    }\n\n    // [l,r)\n    T query(int l, int r) {\n    \
    \  return data[r] - data[l];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cumulative-sum.hpp
layout: document
redirect_from:
- /library/data-structure/cumulative-sum.hpp
- /library/data-structure/cumulative-sum.hpp.html
title: data-structure/cumulative-sum.hpp
---
