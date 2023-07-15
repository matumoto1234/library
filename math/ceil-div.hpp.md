---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/other/yahoo2019/A.test.cpp
    title: test/atcoder/other/yahoo2019/A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ceil-div.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/ceil-div.hpp\"\n\n#include <cassert>\n\nnamespace matumoto\
    \ {\n  constexpr ll ceil_div(ll n, ll d) {\n    assert(d != 0);\n    return n\
    \ / d + (((n ^ d) >= 0) and (n % d));\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ matumoto {\n  constexpr ll ceil_div(ll n, ll d) {\n    assert(d != 0);\n   \
    \ return n / d + (((n ^ d) >= 0) and (n % d));\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/ceil-div.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/other/yahoo2019/A.test.cpp
documentation_of: math/ceil-div.hpp
layout: document
redirect_from:
- /library/math/ceil-div.hpp
- /library/math/ceil-div.hpp.html
title: math/ceil-div.hpp
---
