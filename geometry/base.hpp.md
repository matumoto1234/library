---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':warning:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':warning:'
    path: geometry/product.hpp
    title: geometry/product.hpp
  - icon: ':warning:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n\nnamespace matumoto\
    \ {\n  using namespace std;\n  using Real = double;\n\n  constexpr Real PI = M_PI;\n\
    \  constexpr Real EPS = 1e-9;\n\n  inline int sign(Real a) {\n    if (a < -EPS)\n\
    \      return -1;\n    if (a > +EPS)\n      return +1;\n    return 0;\n  }\n\n\
    \  inline bool equals(Real a, Real b) {\n    return sign(a - b) == 0;\n  }\n}\
    \ // namespace matumoto\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace matumoto {\n  using namespace\
    \ std;\n  using Real = double;\n\n  constexpr Real PI = M_PI;\n  constexpr Real\
    \ EPS = 1e-9;\n\n  inline int sign(Real a) {\n    if (a < -EPS)\n      return\
    \ -1;\n    if (a > +EPS)\n      return +1;\n    return 0;\n  }\n\n  inline bool\
    \ equals(Real a, Real b) {\n    return sign(a - b) == 0;\n  }\n} // namespace\
    \ matumoto"
  dependsOn: []
  isVerificationFile: false
  path: geometry/base.hpp
  requiredBy:
  - geometry/product.hpp
  - geometry/point.hpp
  - geometry/line.hpp
  - geometry/projection.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/base.hpp
layout: document
redirect_from:
- /library/geometry/base.hpp
- /library/geometry/base.hpp.html
title: geometry/base.hpp
---
