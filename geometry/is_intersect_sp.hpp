#pragma once

#include "./ccw.hpp"

namespace geometry_library {
  bool is_intersect_sp(const Segment &s, const Point &p) {
    CCW ccw;
    return ccw(s, p) == CCW::ON_SEGMENT;
  }
} // namespace geometry_library
