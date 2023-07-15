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
  bundledCode: "#line 2 \"data-structure/fenwick-tree-2d.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/fenwick-tree-2d.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace matumoto {\n  // 1-indexed\n\
    \  template <typename T>\n  class FenwickTree2D {\n  private:\n    int H, W;\n\
    \    vector<vector<T>> dat;\n\n    // 1<=i<=y 1<=j<=x\n    T internal_sum(int\
    \ y, int x) {\n      T res = 0;\n      for (int i = y; i > 0; i -= (i & -i)) {\n\
    \        for (int j = x; j > 0; j -= (j & -j)) {\n          res += dat[i][j];\n\
    \        }\n      }\n      return res;\n    }\n\n  public:\n    FenwickTree2D()\
    \ {}\n    FenwickTree2D(int H_, int W_) {\n      init(H_, W_);\n    }\n    void\
    \ init(int H_, int W_) {\n      H = H_ + 1;\n      W = W_ + 1;\n      dat.assign(H,\
    \ vector<T>(W, 0));\n    }\n\n    // {h,w} += x\n    void add(int h, int w, T\
    \ x) {\n      assert(1 <= h and h <= H and 1 <= w and w <= W);\n      for (int\
    \ i = h; i < H; i += (i & -i)) {\n        for (int j = w; j < W; j += (j & -j))\
    \ {\n          dat[i][j] += x;\n        }\n      }\n    }\n\n    // [{sy,sx},\
    \ {gy,gx})\n    T sum(int sy, int sx, int gy, int gx) {\n      assert(1 <= sy\
    \ and sy <= H and 1 <= sx and sx <= W and 2 <= gy and gy <= H + 1 and 2 <= gx\
    \ and gx <= W + 1);\n      return internal_sum(gy - 1, gx - 1) - internal_sum(gy\
    \ - 1, sx - 1) - internal_sum(sy - 1, gx - 1) + internal_sum(sy - 1, sx - 1);\n\
    \    }\n\n    T get(int y, int x) {\n      return sum(y, x, y + 1, x + 1);\n \
    \   }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace matumoto {\n  // 1-indexed\n  template <typename T>\n  class FenwickTree2D\
    \ {\n  private:\n    int H, W;\n    vector<vector<T>> dat;\n\n    // 1<=i<=y 1<=j<=x\n\
    \    T internal_sum(int y, int x) {\n      T res = 0;\n      for (int i = y; i\
    \ > 0; i -= (i & -i)) {\n        for (int j = x; j > 0; j -= (j & -j)) {\n   \
    \       res += dat[i][j];\n        }\n      }\n      return res;\n    }\n\n  public:\n\
    \    FenwickTree2D() {}\n    FenwickTree2D(int H_, int W_) {\n      init(H_, W_);\n\
    \    }\n    void init(int H_, int W_) {\n      H = H_ + 1;\n      W = W_ + 1;\n\
    \      dat.assign(H, vector<T>(W, 0));\n    }\n\n    // {h,w} += x\n    void add(int\
    \ h, int w, T x) {\n      assert(1 <= h and h <= H and 1 <= w and w <= W);\n \
    \     for (int i = h; i < H; i += (i & -i)) {\n        for (int j = w; j < W;\
    \ j += (j & -j)) {\n          dat[i][j] += x;\n        }\n      }\n    }\n\n \
    \   // [{sy,sx}, {gy,gx})\n    T sum(int sy, int sx, int gy, int gx) {\n     \
    \ assert(1 <= sy and sy <= H and 1 <= sx and sx <= W and 2 <= gy and gy <= H +\
    \ 1 and 2 <= gx and gx <= W + 1);\n      return internal_sum(gy - 1, gx - 1) -\
    \ internal_sum(gy - 1, sx - 1) - internal_sum(sy - 1, gx - 1) + internal_sum(sy\
    \ - 1, sx - 1);\n    }\n\n    T get(int y, int x) {\n      return sum(y, x, y\
    \ + 1, x + 1);\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/fenwick-tree-2d.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/fenwick-tree-2d.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick-tree-2d.hpp
- /library/data-structure/fenwick-tree-2d.hpp.html
title: data-structure/fenwick-tree-2d.hpp
---
