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
  bundledCode: "#line 2 \"data-structure/weighted-union-find.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/weighted-union-find.hpp\"\
    \n\n#include <numeric>\n#include <vector>\n\nnamespace matumoto {\n  template\
    \ <typename T>\n  struct WeightedUnionFind {\n    vector<int> par;\n    vector<int>\
    \ siz;\n    vector<T> w;\n    WeightedUnionFind(int N): par(N), siz(N, 1), w(N,\
    \ 0) {\n      iota(par.begin(), par.end(), 0);\n    }\n\n    int size(int x) {\n\
    \      return siz[x];\n    }\n\n    T diff(int x, int y) {\n      return weight(y)\
    \ - weight(x);\n    }\n\n    bool issame(int x, int y) {\n      return root(x)\
    \ == root(y);\n    }\n\n    void unite(int x, int y, T z) {\n      z += weight(x);\n\
    \      z -= weight(y);\n      x = root(x);\n      y = root(y);\n      if (x ==\
    \ y)\n        return;\n      if (x < y) {\n        swap(x, y);\n        z = -z;\n\
    \      }\n      siz[x] += siz[y];\n      par[y] = x;\n      w[y] = z;\n    }\n\
    \n    int root(int x) {\n      if (x == par[x])\n        return x;\n      int\
    \ rx = root(par[x]);\n      w[x] += w[par[x]];\n      par[x] = rx;\n      return\
    \ rx;\n    }\n\n    T weight(int x) {\n      root(x);\n      return w[x];\n  \
    \  }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <numeric>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  struct WeightedUnionFind {\n\
    \    vector<int> par;\n    vector<int> siz;\n    vector<T> w;\n    WeightedUnionFind(int\
    \ N): par(N), siz(N, 1), w(N, 0) {\n      iota(par.begin(), par.end(), 0);\n \
    \   }\n\n    int size(int x) {\n      return siz[x];\n    }\n\n    T diff(int\
    \ x, int y) {\n      return weight(y) - weight(x);\n    }\n\n    bool issame(int\
    \ x, int y) {\n      return root(x) == root(y);\n    }\n\n    void unite(int x,\
    \ int y, T z) {\n      z += weight(x);\n      z -= weight(y);\n      x = root(x);\n\
    \      y = root(y);\n      if (x == y)\n        return;\n      if (x < y) {\n\
    \        swap(x, y);\n        z = -z;\n      }\n      siz[x] += siz[y];\n    \
    \  par[y] = x;\n      w[y] = z;\n    }\n\n    int root(int x) {\n      if (x ==\
    \ par[x])\n        return x;\n      int rx = root(par[x]);\n      w[x] += w[par[x]];\n\
    \      par[x] = rx;\n      return rx;\n    }\n\n    T weight(int x) {\n      root(x);\n\
    \      return w[x];\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/weighted-union-find.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/weighted-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/weighted-union-find.hpp
- /library/data-structure/weighted-union-find.hpp.html
title: data-structure/weighted-union-find.hpp
---
