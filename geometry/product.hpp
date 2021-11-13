#pragma once

#include "./base.hpp"
#include "./point.hpp"

namespace geometry {
  Real cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real(); }

  Real dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }
} // namespace geometry