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
  bundledCode: "#line 2 \"math/convert-base.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/convert-base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  // from-ary n -> to-ary n\n  template <typename T>\n  vector<T>\
    \ convert_base(vector<T> n, T from, T to) {\n    auto to_base = [&](T n, T b)\
    \ {\n      if (n == 0 or b <= 1)\n        return vector<T>{ 0 };\n      vector<T>\
    \ res;\n      for (; n > 0; n /= b) {\n        res.emplace_back(n % b);\n    \
    \  }\n      reverse(res.begin(), res.end());\n      return res;\n    };\n\n  \
    \  auto to_decimal = [&](vector<T> n, T b) {\n      T res = 0, x = 1;\n      for\
    \ (int i = n.size() - 1; i >= 0; i--, x *= b) {\n        res += x * (n[i]);\n\
    \      }\n      return res;\n    };\n\n    T temp = to_decimal(n, from);\n   \
    \ return to_base(temp, to);\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  // from-ary n -> to-ary n\n  template <typename T>\n  vector<T>\
    \ convert_base(vector<T> n, T from, T to) {\n    auto to_base = [&](T n, T b)\
    \ {\n      if (n == 0 or b <= 1)\n        return vector<T>{ 0 };\n      vector<T>\
    \ res;\n      for (; n > 0; n /= b) {\n        res.emplace_back(n % b);\n    \
    \  }\n      reverse(res.begin(), res.end());\n      return res;\n    };\n\n  \
    \  auto to_decimal = [&](vector<T> n, T b) {\n      T res = 0, x = 1;\n      for\
    \ (int i = n.size() - 1; i >= 0; i--, x *= b) {\n        res += x * (n[i]);\n\
    \      }\n      return res;\n    };\n\n    T temp = to_decimal(n, from);\n   \
    \ return to_base(temp, to);\n  }\n} // namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/convert-base.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convert-base.hpp
layout: document
redirect_from:
- /library/math/convert-base.hpp
- /library/math/convert-base.hpp.html
title: math/convert-base.hpp
---
