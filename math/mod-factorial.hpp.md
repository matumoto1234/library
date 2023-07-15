---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/5_B.test.cpp
    title: test/aoj/dpl/5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/5_D.test.cpp
    title: test/aoj/dpl/5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/5_E.test.cpp
    title: test/aoj/dpl/5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/5_F.test.cpp
    title: test/aoj/dpl/5_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod-factorial.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/mod-factorial.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  using mint = atcoder::modint1000000007;\n  template <typename\
    \ ModInt = mint>\n  class ModFactorial {\n    vector<ModInt> fact, invfact;\n\n\
    \    int min_pow2_greater_equal_than(int k) {\n      int pow2 = 1;\n      while\
    \ (pow2 < k) {\n        pow2 <<= 1;\n      }\n      return pow2;\n    }\n\n  public:\n\
    \    ModFactorial(): fact(1, 1), invfact(1, 1) {}\n\n    ModInt factorial(int\
    \ k) {\n      if (k < 0)\n        return 0;\n      if (k < static_cast<int>(fact.size()))\n\
    \        return fact[k];\n\n      int pow2 = min_pow2_greater_equal_than(k);\n\
    \      int old_size = fact.size();\n      fact.resize(pow2 + 1);\n\n      for\
    \ (int i = old_size - 1; i < pow2; i++) {\n        fact[i + 1] = fact[i] * ModInt(i\
    \ + 1);\n      }\n      return fact[k];\n    }\n\n    ModInt inv_factorial(int\
    \ k) {\n      if (k < 0)\n        return 0;\n      if (k < static_cast<int>(invfact.size()))\n\
    \        return invfact[k];\n\n      int pow2 = min_pow2_greater_equal_than(k);\n\
    \      int old_size = fact.size();\n      invfact.resize(pow2 + 1);\n\n      invfact[pow2]\
    \ = ModInt(1) / factorial(pow2);\n      for (int i = pow2; i > old_size; i--)\
    \ {\n        invfact[i - 1] = invfact[i] * ModInt(i);\n      }\n      return invfact[k];\n\
    \    }\n\n    ModInt inv(int k) {\n      return ModInt(1) / ModInt(k);\n    }\n\
    \n    ModInt permutation(int n, int k) {\n      return factorial(n) * inv_factorial(n\
    \ - k);\n    }\n    ModInt combination(int n, int k) {\n      return factorial(n)\
    \ * inv_factorial(k) * inv_factorial(n - k);\n    }\n    ModInt homogeneous(int\
    \ n, int k) {\n      return combination(n + k - 1, k);\n    }\n  };\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  using mint = atcoder::modint1000000007;\n  template <typename\
    \ ModInt = mint>\n  class ModFactorial {\n    vector<ModInt> fact, invfact;\n\n\
    \    int min_pow2_greater_equal_than(int k) {\n      int pow2 = 1;\n      while\
    \ (pow2 < k) {\n        pow2 <<= 1;\n      }\n      return pow2;\n    }\n\n  public:\n\
    \    ModFactorial(): fact(1, 1), invfact(1, 1) {}\n\n    ModInt factorial(int\
    \ k) {\n      if (k < 0)\n        return 0;\n      if (k < static_cast<int>(fact.size()))\n\
    \        return fact[k];\n\n      int pow2 = min_pow2_greater_equal_than(k);\n\
    \      int old_size = fact.size();\n      fact.resize(pow2 + 1);\n\n      for\
    \ (int i = old_size - 1; i < pow2; i++) {\n        fact[i + 1] = fact[i] * ModInt(i\
    \ + 1);\n      }\n      return fact[k];\n    }\n\n    ModInt inv_factorial(int\
    \ k) {\n      if (k < 0)\n        return 0;\n      if (k < static_cast<int>(invfact.size()))\n\
    \        return invfact[k];\n\n      int pow2 = min_pow2_greater_equal_than(k);\n\
    \      int old_size = fact.size();\n      invfact.resize(pow2 + 1);\n\n      invfact[pow2]\
    \ = ModInt(1) / factorial(pow2);\n      for (int i = pow2; i > old_size; i--)\
    \ {\n        invfact[i - 1] = invfact[i] * ModInt(i);\n      }\n      return invfact[k];\n\
    \    }\n\n    ModInt inv(int k) {\n      return ModInt(1) / ModInt(k);\n    }\n\
    \n    ModInt permutation(int n, int k) {\n      return factorial(n) * inv_factorial(n\
    \ - k);\n    }\n    ModInt combination(int n, int k) {\n      return factorial(n)\
    \ * inv_factorial(k) * inv_factorial(n - k);\n    }\n    ModInt homogeneous(int\
    \ n, int k) {\n      return combination(n + k - 1, k);\n    }\n  };\n} // namespace\
    \ matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/mod-factorial.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dpl/5_B.test.cpp
  - test/aoj/dpl/5_F.test.cpp
  - test/aoj/dpl/5_E.test.cpp
  - test/aoj/dpl/5_D.test.cpp
documentation_of: math/mod-factorial.hpp
layout: document
redirect_from:
- /library/math/mod-factorial.hpp
- /library/math/mod-factorial.hpp.html
title: math/mod-factorial.hpp
---
