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
  bundledCode: "#line 2 \"tools/compress.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/compress.hpp\"\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace matumoto {\n  // verify:ABC036_C\n\
    \  template <typename T>\n  struct Compress {\n    vector<T> xs;\n    Compress()\
    \ {}\n    Compress(int N): xs(N, 0) {}\n    Compress(const vector<T> &vs): xs(vs)\
    \ {}\n\n    void set(int i, T x) {\n      xs[i] = x;\n    }\n\n    void set(const\
    \ vector<T> &vs) {\n      for (int i = 0; i < min<int>(xs.size(), vs.size());\
    \ i++) {\n        xs[i] = vs[i];\n      }\n    }\n\n    void add(T x) {\n    \
    \  xs.emplace_back(x);\n    }\n\n    void add(const vector<T> &vs) {\n      for\
    \ (const T &x: vs) {\n        xs.emplace_back(x);\n      }\n    }\n\n    Compress<T>\
    \ build() {\n      sort(xs.begin(), xs.end());\n      xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n      return *this;\n    }\n\n    vector<T> get(const\
    \ vector<T> &vs) const {\n      vector<T> res = vs;\n      for (T &x: res) {\n\
    \        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n      }\n   \
    \   return res;\n    }\n\n    int get(T k) const {\n      return lower_bound(xs.begin(),\
    \ xs.end(), k) - xs.begin();\n    }\n\n    const T &operator[](int k) const {\n\
    \      return xs[k];\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  // verify:ABC036_C\n  template <typename\
    \ T>\n  struct Compress {\n    vector<T> xs;\n    Compress() {}\n    Compress(int\
    \ N): xs(N, 0) {}\n    Compress(const vector<T> &vs): xs(vs) {}\n\n    void set(int\
    \ i, T x) {\n      xs[i] = x;\n    }\n\n    void set(const vector<T> &vs) {\n\
    \      for (int i = 0; i < min<int>(xs.size(), vs.size()); i++) {\n        xs[i]\
    \ = vs[i];\n      }\n    }\n\n    void add(T x) {\n      xs.emplace_back(x);\n\
    \    }\n\n    void add(const vector<T> &vs) {\n      for (const T &x: vs) {\n\
    \        xs.emplace_back(x);\n      }\n    }\n\n    Compress<T> build() {\n  \
    \    sort(xs.begin(), xs.end());\n      xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n      return *this;\n    }\n\n    vector<T> get(const vector<T>\
    \ &vs) const {\n      vector<T> res = vs;\n      for (T &x: res) {\n        x\
    \ = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n      }\n      return\
    \ res;\n    }\n\n    int get(T k) const {\n      return lower_bound(xs.begin(),\
    \ xs.end(), k) - xs.begin();\n    }\n\n    const T &operator[](int k) const {\n\
    \      return xs[k];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/compress.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/compress.hpp
layout: document
redirect_from:
- /library/tools/compress.hpp
- /library/tools/compress.hpp.html
title: tools/compress.hpp
---
