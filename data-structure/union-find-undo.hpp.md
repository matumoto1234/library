---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc/abc214/D.test.cpp
    title: test/atcoder/abc/abc214/D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/union-find-undo.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/union-find-undo.hpp\"\
    \n\n#include <numeric>\n#include <stack>\n#include <tuple>\n#include <vector>\n\
    \nnamespace matumoto {\n  // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\n  class UnionFindUndo\
    \ {\n  private:\n    // number of vertices\n    int n_;\n\n    vector<int> sizes_,\
    \ parents_;\n\n    // <index, parent(index), size(index)>\n    stack<tuple<int,\
    \ int, int>> history_;\n\n  public:\n    UnionFindUndo(int N): sizes_(N, 1), parents_(N)\
    \ {\n      iota(parents_.begin(), parents_.end(), 0);\n    }\n\n    // \u6839\uFF08\
    \u305D\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u8B58\u5225\u756A\u53F7\uFF09\n   \
    \ int root(int x) {\n      if (x == parents_[x])\n        return x;\n      return\
    \ root(parents_[x]);\n    }\n\n    int size(int x) {\n      return sizes_[root(x)];\n\
    \    }\n\n    bool same(int x, int y) {\n      return root(x) == root(y);\n  \
    \  }\n\n    // size(x) < size(y): -1\n    // not merged:         0\n    // size(x)\
    \ > size(y): +1\n    int merge(int x, int y) {\n      x = root(x);\n      y =\
    \ root(y);\n      if (x == y)\n        return 0;\n\n      int result = +1;\n \
    \     if (sizes_[x] < sizes_[y]) {\n        swap(x, y);\n        result = -1;\n\
    \      }\n\n      history_.emplace(tuple(x, parents_[x], sizes_[x]));\n      history_.emplace(tuple(y,\
    \ parents_[y], sizes_[y]));\n      sizes_[x] += sizes_[y];\n      parents_[y]\
    \ = x;\n      return result;\n    }\n\n    bool undo() {\n      if (history_.empty())\n\
    \        return false;\n\n      auto [x, x_parent, x_size] = history_.top();\n\
    \      history_.pop();\n      auto [y, y_parent, y_size] = history_.top();\n \
    \     history_.pop();\n\n      parents_[x] = x_parent;\n      sizes_[x] = x_size;\n\
    \      parents_[y] = y_parent;\n      sizes_[y] = y_size;\n      return true;\n\
    \    }\n\n    void clear_history() {\n      while (not history_.empty()) {\n \
    \       history_.pop();\n      }\n    }\n\n    void all_undo() {\n      while\
    \ (undo()) {}\n    }\n\n    // \u0398(N log(N))\n    vector<vector<int>> groups()\
    \ {\n      vector<vector<int>> grps(n_);\n      for (int i = 0; i < n_; i++) {\n\
    \        grps[root(i)].emplace_back(i);\n      }\n\n      vector<vector<int>>\
    \ res;\n      for (int i = 0; i < n_; i++) {\n        if (grps[i].empty())\n \
    \         continue;\n        res.emplace_back(grps[i]);\n      }\n      return\
    \ res;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <numeric>\n#include <stack>\n\
    #include <tuple>\n#include <vector>\n\nnamespace matumoto {\n  // \u7D4C\u8DEF\
    \u5727\u7E2E\u306A\u3057\n  class UnionFindUndo {\n  private:\n    // number of\
    \ vertices\n    int n_;\n\n    vector<int> sizes_, parents_;\n\n    // <index,\
    \ parent(index), size(index)>\n    stack<tuple<int, int, int>> history_;\n\n \
    \ public:\n    UnionFindUndo(int N): sizes_(N, 1), parents_(N) {\n      iota(parents_.begin(),\
    \ parents_.end(), 0);\n    }\n\n    // \u6839\uFF08\u305D\u306E\u30B0\u30EB\u30FC\
    \u30D7\u306E\u8B58\u5225\u756A\u53F7\uFF09\n    int root(int x) {\n      if (x\
    \ == parents_[x])\n        return x;\n      return root(parents_[x]);\n    }\n\
    \n    int size(int x) {\n      return sizes_[root(x)];\n    }\n\n    bool same(int\
    \ x, int y) {\n      return root(x) == root(y);\n    }\n\n    // size(x) < size(y):\
    \ -1\n    // not merged:         0\n    // size(x) > size(y): +1\n    int merge(int\
    \ x, int y) {\n      x = root(x);\n      y = root(y);\n      if (x == y)\n   \
    \     return 0;\n\n      int result = +1;\n      if (sizes_[x] < sizes_[y]) {\n\
    \        swap(x, y);\n        result = -1;\n      }\n\n      history_.emplace(tuple(x,\
    \ parents_[x], sizes_[x]));\n      history_.emplace(tuple(y, parents_[y], sizes_[y]));\n\
    \      sizes_[x] += sizes_[y];\n      parents_[y] = x;\n      return result;\n\
    \    }\n\n    bool undo() {\n      if (history_.empty())\n        return false;\n\
    \n      auto [x, x_parent, x_size] = history_.top();\n      history_.pop();\n\
    \      auto [y, y_parent, y_size] = history_.top();\n      history_.pop();\n\n\
    \      parents_[x] = x_parent;\n      sizes_[x] = x_size;\n      parents_[y] =\
    \ y_parent;\n      sizes_[y] = y_size;\n      return true;\n    }\n\n    void\
    \ clear_history() {\n      while (not history_.empty()) {\n        history_.pop();\n\
    \      }\n    }\n\n    void all_undo() {\n      while (undo()) {}\n    }\n\n \
    \   // \u0398(N log(N))\n    vector<vector<int>> groups() {\n      vector<vector<int>>\
    \ grps(n_);\n      for (int i = 0; i < n_; i++) {\n        grps[root(i)].emplace_back(i);\n\
    \      }\n\n      vector<vector<int>> res;\n      for (int i = 0; i < n_; i++)\
    \ {\n        if (grps[i].empty())\n          continue;\n        res.emplace_back(grps[i]);\n\
    \      }\n      return res;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/union-find-undo.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc/abc214/D.test.cpp
documentation_of: data-structure/union-find-undo.hpp
layout: document
redirect_from:
- /library/data-structure/union-find-undo.hpp
- /library/data-structure/union-find-undo.hpp.html
title: data-structure/union-find-undo.hpp
---
