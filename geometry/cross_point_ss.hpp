#pragma once

#include "./contains_ss.hpp"
#include "./is_intersect_ss.hpp"
#include "./is_parallel_ss.hpp"

#include <vector>

namespace geometry_library {
  vector<Point> cross_point_ss(const Segment &s1, const Segment &s2) {
    if (not is_intersect_ss(s1, s2)) {
      return {};
    }

    if (contains_ss(s1, s2)) {
      return { s2.first, s2.second };
    }

    if (contains_ss(s2, s1)) {
      return { s1.first, s1.second };
    }

    if (is_parallel_ss(s1, s2)) {
      return {};
    }

    Point a = s1.first, b = s1.second;
    Point c = s2.first, d = s2.second;
    Real seg_ratio = cross(a - c, d - c) / cross(b - a, d - c);
    return { a + seg_ratio * (b - a) };
  }
} // namespace geometry_library

