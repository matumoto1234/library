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
  bundledCode: "#line 2 \"math/is-prime.hpp\"\n\nnamespace matumoto {\n  constexpr\
    \ bool is_prime(int n) {\n    if (n <= 1)\n      return false;\n    for (int i\
    \ = 2; i * i <= n; i++) {\n      if (n % i == 0)\n        return false;\n    }\n\
    \    return true;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\nnamespace matumoto {\n  constexpr bool is_prime(int n) {\n\
    \    if (n <= 1)\n      return false;\n    for (int i = 2; i * i <= n; i++) {\n\
    \      if (n % i == 0)\n        return false;\n    }\n    return true;\n  }\n\
    } // namespace matumoto"
  dependsOn: []
  isVerificationFile: false
  path: math/is-prime.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is-prime.hpp
layout: document
redirect_from:
- /library/math/is-prime.hpp
- /library/math/is-prime.hpp.html
title: math/is-prime.hpp
---
