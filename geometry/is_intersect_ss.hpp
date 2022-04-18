#pragma once

#include "./ccw.hpp"

namespace geometry_library {
  bool is_intersect_ss(const Segment &s1, const Segment &s2) {
    CCW ccw;
    bool not_same_area1 = ccw(s1, s2.first) * ccw(s1, s2.second) <= 0;
    bool not_same_area2 = ccw(s1, s2.first) * ccw(s1, s2.second) <= 0;
    return not_same_area1 and not_same_area2;
  }
} // namespace geometry_library
