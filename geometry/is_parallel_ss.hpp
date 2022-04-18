#pragma once

#include "./product.hpp"
#include "./segment.hpp"

namespace geometry_library {
  bool is_parallel_ss(const Segment &s1, const Segment &s2) {
    Point vec1 = s1.second - s1.first;
    Point vec2 = s2.second - s2.first;
    return equals(cross(vec1, vec2), 0);
  }
} // namespace geometry_library
