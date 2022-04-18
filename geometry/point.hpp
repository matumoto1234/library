#pragma once

#include "./base.hpp"

#include <complex>

namespace geometry_library {
  using Point = complex<Real>;

  istream &operator>>(istream &is, Point &p) {
    Real x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
  }

  ostream &operator<<(ostream &os, const Point &p) {
    os << p.real() << " " << p.imag();
    return os;
  }

  Point operator*(const Point &p, const Real &k) {
    return Point(p.real() * k, p.imag() * k);
  }

  Point rotate_ccw(const Point &p, const Real &radian, const Point center = Point(0, 0)) {
    Point np(p - center);
    Real r = cos(radian) * np.real() + sin(-radian) * np.imag();
    Real i = sin(radian) * np.real() + cos(-radian) * np.imag();

    Point rotated = Point(r, i);
    return rotated + center;
  }

  bool equals(const Point &a, const Point &b) {
    return equals(a.real(), b.real()) and equals(a.imag(), b.imag());
  }
} // namespace geometry_library