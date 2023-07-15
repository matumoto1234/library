---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':warning:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n\
    #line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n\nnamespace matumoto {\n  using\
    \ namespace std;\n  using Real = double;\n\n  constexpr Real PI = M_PI;\n  constexpr\
    \ Real EPS = 1e-9;\n\n  inline int sign(Real a) {\n    if (a < -EPS)\n      return\
    \ -1;\n    if (a > +EPS)\n      return +1;\n    return 0;\n  }\n\n  inline bool\
    \ equals(Real a, Real b) {\n    return sign(a - b) == 0;\n  }\n} // namespace\
    \ matumoto\n#line 4 \"geometry/point.hpp\"\n\n#include <complex>\n\nnamespace\
    \ matumoto {\n  using Point = complex<Real>;\n\n  istream &operator>>(istream\
    \ &is, Point &p) {\n    Real x, y;\n    is >> x >> y;\n    p = Point(x, y);\n\
    \    return is;\n  }\n\n  ostream &operator<<(ostream &os, const Point &p) {\n\
    \    os << p.real() << \" \" << p.imag();\n    return os;\n  }\n\n  Point operator*(const\
    \ Point &p, const Real &k) {\n    return Point(p.real() * k, p.imag() * k);\n\
    \  }\n\n  Point rotate_cw(const Real &radian, Point p, const Point &origin = Point(0,\
    \ 0)) {\n    p -= origin;\n    Real r = cosl(radian) * p.real() + sinl(-radian)\
    \ * p.imag();\n    Real i = sinl(radian) * p.real() + cosl(-radian) * p.imag();\n\
    \    p = Point(r, i);\n    p += origin;\n    return p;\n  }\n\n  Point rotate_ccw(const\
    \ Real &radian, Point p, const Point &origin = Point(0, 0)) {\n    p -= origin;\n\
    \    Real r = cosl(radian) * p.real() + sinl(-radian) * p.real();\n    Real i\
    \ = sinl(radian) * p.imag() + cosl(-radian) * p.imag();\n    p = Point(r, i);\n\
    \    p += origin;\n    return p;\n  }\n\n  bool equals(const Point &a, const Point\
    \ &b) {\n    return equals(a.real(), b.real()) and equals(a.imag(), b.imag());\n\
    \  }\n} // namespace matumoto\n#line 4 \"geometry/line.hpp\"\n\nnamespace matumoto\
    \ {\n  struct Line {\n    Point a, b;\n\n    Line() = default;\n    Line(const\
    \ Point &a, const Point &b): a(a), b(b) {}\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./point.hpp\"\n\nnamespace matumoto {\n  struct\
    \ Line {\n    Point a, b;\n\n    Line() = default;\n    Line(const Point &a, const\
    \ Point &b): a(a), b(b) {}\n  };\n} // namespace matumoto"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/projection.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/line.hpp
layout: document
redirect_from:
- /library/geometry/line.hpp
- /library/geometry/line.hpp.html
title: geometry/line.hpp
---
