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
  bundledCode: "#line 2 \"math/to-base.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/to-base.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \nnamespace matumoto {\n  // decimal n -> b-ary\n  template <typename T>\n  vector<T>\
    \ to_base(T n, T b) {\n    if (n == 0 or b <= 1)\n      return vector<T>{ 0 };\n\
    \    vector<T> res;\n    for (; n > 0; n /= b) {\n      res.emplace_back(n % b);\n\
    \    }\n    reverse(res.begin(), res.end());\n    return res;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  // decimal n -> b-ary\n  template <typename\
    \ T>\n  vector<T> to_base(T n, T b) {\n    if (n == 0 or b <= 1)\n      return\
    \ vector<T>{ 0 };\n    vector<T> res;\n    for (; n > 0; n /= b) {\n      res.emplace_back(n\
    \ % b);\n    }\n    reverse(res.begin(), res.end());\n    return res;\n  }\n}\
    \ // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/to-base.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/to-base.hpp
layout: document
redirect_from:
- /library/math/to-base.hpp
- /library/math/to-base.hpp.html
title: math/to-base.hpp
---
