---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/floor-div.hpp\"\n\nnamespace matumoto {\n  template\
    \ <typename T>\n  constexpr T floor_div(T n, T d) {\n    assert(d != 0);\n   \
    \ return n / d - (((n ^ d) < 0) and (n % d));\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\nnamespace matumoto {\n  template <typename T>\n  constexpr\
    \ T floor_div(T n, T d) {\n    assert(d != 0);\n    return n / d - (((n ^ d) <\
    \ 0) and (n % d));\n  }\n} // namespace matumoto"
  dependsOn: []
  isVerificationFile: false
  path: math/floor-div.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor-div.hpp
layout: document
redirect_from:
- /library/math/floor-div.hpp
- /library/math/floor-div.hpp.html
title: math/floor-div.hpp
---
