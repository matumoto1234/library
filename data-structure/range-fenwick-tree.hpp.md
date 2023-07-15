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
  bundledCode: "#line 2 \"data-structure/range-fenwick-tree.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/range-fenwick-tree.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  template <typename T>\n  class\
    \ RangeFenwickTree {\n  private:\n    int n;\n    vector<T> data[2];\n\n    void\
    \ init(int n_) {\n      n = n_ + 1;\n      for (int p = 0; p < 2; p++)\n     \
    \   data[p].assign(n, 0);\n    }\n\n    void internal_add(int p, int i, T x) {\n\
    \      for (int k = i; k < n; k += k & -k) {\n        data[p][k] += x;\n     \
    \ }\n    }\n\n    T internal_sum(int p, int i) {\n      T res = 0;\n      for\
    \ (int k = i; k > 0; k -= k & -k) {\n        res += data[p][k];\n      }\n   \
    \   return res;\n    }\n\n    // [1,r)\n    T sum(int r) {\n      r--;\n     \
    \ return internal_sum(0, r) + internal_sum(1, r) * r;\n    }\n\n  public:\n  \
    \  RangeFenwickTree(int n_) {\n      init(n_);\n    }\n\n    // [l, r)\n    void\
    \ add(int l, int r, T x) {\n      internal_add(0, l, -x * (l - 1));\n      internal_add(0,\
    \ r, x * (r - 1));\n      internal_add(1, l, x);\n      internal_add(1, r, -x);\n\
    \    }\n\n    // [l,r)\n    T sum(int l, int r) {\n      return sum(r) - sum(l);\n\
    \    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  class RangeFenwickTree {\n  private:\n\
    \    int n;\n    vector<T> data[2];\n\n    void init(int n_) {\n      n = n_ +\
    \ 1;\n      for (int p = 0; p < 2; p++)\n        data[p].assign(n, 0);\n    }\n\
    \n    void internal_add(int p, int i, T x) {\n      for (int k = i; k < n; k +=\
    \ k & -k) {\n        data[p][k] += x;\n      }\n    }\n\n    T internal_sum(int\
    \ p, int i) {\n      T res = 0;\n      for (int k = i; k > 0; k -= k & -k) {\n\
    \        res += data[p][k];\n      }\n      return res;\n    }\n\n    // [1,r)\n\
    \    T sum(int r) {\n      r--;\n      return internal_sum(0, r) + internal_sum(1,\
    \ r) * r;\n    }\n\n  public:\n    RangeFenwickTree(int n_) {\n      init(n_);\n\
    \    }\n\n    // [l, r)\n    void add(int l, int r, T x) {\n      internal_add(0,\
    \ l, -x * (l - 1));\n      internal_add(0, r, x * (r - 1));\n      internal_add(1,\
    \ l, x);\n      internal_add(1, r, -x);\n    }\n\n    // [l,r)\n    T sum(int\
    \ l, int r) {\n      return sum(r) - sum(l);\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/range-fenwick-tree.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/range-fenwick-tree.hpp
layout: document
redirect_from:
- /library/data-structure/range-fenwick-tree.hpp
- /library/data-structure/range-fenwick-tree.hpp.html
title: data-structure/range-fenwick-tree.hpp
---
