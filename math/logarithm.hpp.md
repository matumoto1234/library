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
  bundledCode: "#line 2 \"math/logarithm.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/logarithm.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ matumoto {\n  constexpr int logarithm(ll base, ll n) {\n    assert(base != 0);\n\
    \    int cnt = 0;\n    while (n % base == 0) {\n      n /= base;\n      cnt++;\n\
    \    }\n    return cnt;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ matumoto {\n  constexpr int logarithm(ll base, ll n) {\n    assert(base != 0);\n\
    \    int cnt = 0;\n    while (n % base == 0) {\n      n /= base;\n      cnt++;\n\
    \    }\n    return cnt;\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/logarithm.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/logarithm.hpp
layout: document
redirect_from:
- /library/math/logarithm.hpp
- /library/math/logarithm.hpp.html
title: math/logarithm.hpp
---
