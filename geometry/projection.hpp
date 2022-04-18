#pragma once

#include "./product.hpp"
#include "./segment.hpp"

#include <cassert>

namespace geometry_library {
  Point projection(const Segment &s, const Point &p) {
    Point a = s.first;
    Point b = s.second;
    return a + (b - a) * dot(p - a, b - a) / norm(b - a);
  }
} // namespace geometry_library
