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
  bundledCode: "#line 2 \"data-structure/cumulative-sum-2d.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/cumulative-sum-2d.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  template <typename T>\n  struct\
    \ CumulativeSum2D {\n    vector<vector<T>> data;\n    CumulativeSum2D(int H, int\
    \ W): data(H + 1, vector<T>(W + 1, 0)) {}\n    CumulativeSum2D(const vector<vector<T>>\
    \ &vs): data(vs) {}\n\n    void set(int y, int x, T v) {\n      data[y + 1][x\
    \ + 1] = v;\n    }\n\n    void build() {\n      for (int i = 1; i < static_cast<int>(data.size());\
    \ i++) {\n        for (int j = 1; j < static_cast<int>(data[i].size()); j++) {\n\
    \          data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n\
    \        }\n      }\n    }\n\n    // [ (sy,sx), (gy,gx) )\n    T query(int sy,\
    \ int sx, int gy, int gx) {\n      return data[gy][gx] - data[gy][sx] - data[sy][gx]\
    \ + data[sy][sx];\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  struct CumulativeSum2D {\n    vector<vector<T>>\
    \ data;\n    CumulativeSum2D(int H, int W): data(H + 1, vector<T>(W + 1, 0)) {}\n\
    \    CumulativeSum2D(const vector<vector<T>> &vs): data(vs) {}\n\n    void set(int\
    \ y, int x, T v) {\n      data[y + 1][x + 1] = v;\n    }\n\n    void build() {\n\
    \      for (int i = 1; i < static_cast<int>(data.size()); i++) {\n        for\
    \ (int j = 1; j < static_cast<int>(data[i].size()); j++) {\n          data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n        }\n      }\n\
    \    }\n\n    // [ (sy,sx), (gy,gx) )\n    T query(int sy, int sx, int gy, int\
    \ gx) {\n      return data[gy][gx] - data[gy][sx] - data[sy][gx] + data[sy][sx];\n\
    \    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cumulative-sum-2d.hpp
layout: document
redirect_from:
- /library/data-structure/cumulative-sum-2d.hpp
- /library/data-structure/cumulative-sum-2d.hpp.html
title: data-structure/cumulative-sum-2d.hpp
---
