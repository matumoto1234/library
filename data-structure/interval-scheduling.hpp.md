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
    links:
    - https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
  bundledCode: "#line 2 \"data-structure/interval-scheduling.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/interval-scheduling.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  // verify:https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b\n\
    \  template <typename T>\n  class IntervalScheduling {\n    vector<pair<T, T>>\
    \ intervals_;\n    vector<bool> used;\n\n  public:\n    IntervalScheduling() {}\n\
    \n    void add_interval(T l, T r) {\n      intervals_.emplace_back(l, r);\n  \
    \  }\n\n    int inf() {\n      return numeric_limits<int>::max() / 2;\n    }\n\
    \n    void build() {\n      used.assign(intervals_.size(), false);\n\n      sort(intervals_.begin(),\
    \ intervals_.end(), [](pair<T, T> a, pair<T, T> b) {\n        if (a.second !=\
    \ b.second)\n          return a.second < b.second;\n        return a.first < b.first;\n\
    \      });\n\n      int last = -inf();\n      for (size_t i = 0; i < intervals_.size();\
    \ i++) {\n        auto [l, r] = intervals_[i];\n\n        if (last <= l) {\n \
    \         used[i] = true;\n          last = r;\n        }\n      }\n    }\n\n\
    \    bool is_used(int k) {\n      return used[k];\n    }\n\n    vector<pair<T,\
    \ T>> intervals() {\n      vector<pair<T, T>> res;\n      for (size_t i = 0; i\
    \ < intervals_.size(); i++) {\n        if (!used[i])\n          continue;\n  \
    \      res.emplace_back(intervals_[i]);\n      }\n      return res;\n    }\n \
    \ };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  // verify:https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b\n\
    \  template <typename T>\n  class IntervalScheduling {\n    vector<pair<T, T>>\
    \ intervals_;\n    vector<bool> used;\n\n  public:\n    IntervalScheduling() {}\n\
    \n    void add_interval(T l, T r) {\n      intervals_.emplace_back(l, r);\n  \
    \  }\n\n    int inf() {\n      return numeric_limits<int>::max() / 2;\n    }\n\
    \n    void build() {\n      used.assign(intervals_.size(), false);\n\n      sort(intervals_.begin(),\
    \ intervals_.end(), [](pair<T, T> a, pair<T, T> b) {\n        if (a.second !=\
    \ b.second)\n          return a.second < b.second;\n        return a.first < b.first;\n\
    \      });\n\n      int last = -inf();\n      for (size_t i = 0; i < intervals_.size();\
    \ i++) {\n        auto [l, r] = intervals_[i];\n\n        if (last <= l) {\n \
    \         used[i] = true;\n          last = r;\n        }\n      }\n    }\n\n\
    \    bool is_used(int k) {\n      return used[k];\n    }\n\n    vector<pair<T,\
    \ T>> intervals() {\n      vector<pair<T, T>> res;\n      for (size_t i = 0; i\
    \ < intervals_.size(); i++) {\n        if (!used[i])\n          continue;\n  \
    \      res.emplace_back(intervals_[i]);\n      }\n      return res;\n    }\n \
    \ };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/interval-scheduling.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/interval-scheduling.hpp
layout: document
redirect_from:
- /library/data-structure/interval-scheduling.hpp
- /library/data-structure/interval-scheduling.hpp.html
title: data-structure/interval-scheduling.hpp
---
