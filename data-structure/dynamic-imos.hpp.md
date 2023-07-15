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
  bundledCode: "#line 2 \"data-structure/dynamic-imos.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/dynamic-imos.hpp\"\
    \n\n#include <tuple>\n#include <vector>\n\nnamespace matumoto {\n  template <typename\
    \ T>\n  struct DynamicImos {\n    vector<T> xs, imos;\n    vector<tuple<T, T,\
    \ T>> intervals;\n\n    DynamicImos() {}\n\n    // [l, r)\n    void add(T l, T\
    \ r, T v) {\n      intervals.emplace_back(l, r, v);\n      xs.emplace_back(l);\n\
    \      xs.emplace_back(r);\n    }\n\n    void build() {\n      sort(xs.begin(),\
    \ xs.end());\n      xs.erase(unique(xs.begin(), xs.end()), xs.end());\n      imos.assign(xs.size(),\
    \ 0);\n\n      for (auto [l, r, v]: intervals) {\n        l = lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        r = lower_bound(xs.begin(), xs.end(), r)\
    \ - xs.begin();\n        imos[l] += v;\n        imos[r] -= v;\n      }\n\n   \
    \   for (int i = 1; i < static_cast<int>(imos.size()); i++) {\n        imos[i]\
    \ += imos[i - 1];\n      }\n    }\n\n    // vector<[l,r), value>\n    vector<pair<pair<T,\
    \ T>, T>> interval_values() {\n      vector<pair<pair<T, T>, T>> res(xs.size()\
    \ - 1);\n      for (int i = 0; i < static_cast<int>(xs.size()) - 1; i++) {\n \
    \       T l = xs[i];\n        T r = xs[i + 1];\n        T v = imos[i];\n     \
    \   res[i] = pair(pair(l, r), v);\n      }\n      return res;\n    }\n  };\n}\
    \ // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <tuple>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  struct DynamicImos {\n    vector<T>\
    \ xs, imos;\n    vector<tuple<T, T, T>> intervals;\n\n    DynamicImos() {}\n\n\
    \    // [l, r)\n    void add(T l, T r, T v) {\n      intervals.emplace_back(l,\
    \ r, v);\n      xs.emplace_back(l);\n      xs.emplace_back(r);\n    }\n\n    void\
    \ build() {\n      sort(xs.begin(), xs.end());\n      xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n      imos.assign(xs.size(), 0);\n\n      for (auto [l,\
    \ r, v]: intervals) {\n        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();\n\
    \        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();\n        imos[l]\
    \ += v;\n        imos[r] -= v;\n      }\n\n      for (int i = 1; i < static_cast<int>(imos.size());\
    \ i++) {\n        imos[i] += imos[i - 1];\n      }\n    }\n\n    // vector<[l,r),\
    \ value>\n    vector<pair<pair<T, T>, T>> interval_values() {\n      vector<pair<pair<T,\
    \ T>, T>> res(xs.size() - 1);\n      for (int i = 0; i < static_cast<int>(xs.size())\
    \ - 1; i++) {\n        T l = xs[i];\n        T r = xs[i + 1];\n        T v = imos[i];\n\
    \        res[i] = pair(pair(l, r), v);\n      }\n      return res;\n    }\n  };\n\
    } // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/dynamic-imos.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-imos.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-imos.hpp
- /library/data-structure/dynamic-imos.hpp.html
title: data-structure/dynamic-imos.hpp
---
