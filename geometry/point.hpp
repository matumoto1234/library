#pragma once

#include <complex>

#include "./base.hpp"

namespace geometry {
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

  Point operator*(const Point &p, const Real &k) { return Point(p.real() * k, p.imag() * k); }

  Point rotate_cw(const Real &radian, Point p, const Point &origin = Point(0, 0)) {
    p -= origin;
    Real r = cosl(radian) * p.real() + sinl(-radian) * p.imag();
    Real i = sinl(radian) * p.real() + cosl(-radian) * p.imag();
    p = Point(r, i);
    p += origin;
    return p;
  }

  Point rotate_ccw(const Real &radian, Point p, const Point &origin = Point(0, 0)) {
    p -= origin;
    Real r = cosl(radian) * p.real() + sinl(-radian) * p.real();
    Real i = sinl(radian) * p.imag() + cosl(-radian) * p.imag();
    p = Point(r, i);
    p += origin;
    return p;
  }

  bool equals(const Point &a, const Point &b) { return equals(a.real(), b.real()) and equals(a.imag(), b.imag()); }
} // namespace geometry