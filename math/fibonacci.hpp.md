---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fibonacci.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/fibonacci.hpp\"\n\n#include <vector>\n\n// WIP\n\n\
    namespace matumoto {\n  template <typename T>\n  struct matrix {\n    vector<vector<T>>\
    \ dat;\n\n    matrix(int r, int c): dat(r, vector<T>(c, 0)) {}\n    matrix(vector<vector<T>>\
    \ _dat): dat(_dat) {}\n\n    size_t size() const {\n      return dat.size();\n\
    \    }\n    bool empty() const {\n      return dat.empty();\n    }\n  };\n\n \
    \ long long fibonacci(long long n) {\n    long long f0 = 1, f1 = 1;\n    // {(1,1),(1,0)}\n\
    \n\n    // if ( p <= 1 ) return 0;\n    // if ( p == 0 ) p = numeric_limits<T>::max();\n\
    \    // T res = 1;\n    // while ( e > 0 ) {\n    //   if ( e & 1 ) res = (res\
    \ * a) % p;\n    //   a = (a * a) % p;\n    //   e >>= 1;\n    // }\n    // return\
    \ res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\n// WIP\n\n\
    namespace matumoto {\n  template <typename T>\n  struct matrix {\n    vector<vector<T>>\
    \ dat;\n\n    matrix(int r, int c): dat(r, vector<T>(c, 0)) {}\n    matrix(vector<vector<T>>\
    \ _dat): dat(_dat) {}\n\n    size_t size() const {\n      return dat.size();\n\
    \    }\n    bool empty() const {\n      return dat.empty();\n    }\n  };\n\n \
    \ long long fibonacci(long long n) {\n    long long f0 = 1, f1 = 1;\n    // {(1,1),(1,0)}\n\
    \n\n    // if ( p <= 1 ) return 0;\n    // if ( p == 0 ) p = numeric_limits<T>::max();\n\
    \    // T res = 1;\n    // while ( e > 0 ) {\n    //   if ( e & 1 ) res = (res\
    \ * a) % p;\n    //   a = (a * a) % p;\n    //   e >>= 1;\n    // }\n    // return\
    \ res;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/fibonacci.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fibonacci.hpp
layout: document
redirect_from:
- /library/math/fibonacci.hpp
- /library/math/fibonacci.hpp.html
title: math/fibonacci.hpp
---
