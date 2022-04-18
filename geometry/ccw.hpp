#pragma once

#include "./product.hpp"
#include "./segment.hpp"

namespace geometry_library {
  // 線分と点の関係
  struct CCW {
    constexpr static int CLOCKWISE = -1;
    constexpr static int COUNTER_CLOCKWISE = +1;
    constexpr static int ON_LINE_FRONT = -2;
    constexpr static int ON_LINE_BACK = +2;
    constexpr static int ON_SEGMENT = 0;

    int operator()(const Segment &s, const Point &p) {
      Point origin = s.first;
      Point a = s.second - origin;
      Point b = p - origin;

      if (sign(cross(a, b)) == -1)
        return CLOCKWISE;

      if (sign(cross(a, b)) == +1)
        return COUNTER_CLOCKWISE;

      if (norm(a) < norm(b))
        return ON_LINE_FRONT;

      if (sign(dot(a, b)))
        return ON_LINE_BACK;

      return ON_SEGMENT;
    }
  };
} // namespace geometry_library
