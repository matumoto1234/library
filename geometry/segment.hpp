#pragma once

#include "./base.hpp"
#include "./point.hpp"

namespace geometry_library {
  struct Segment {
    Point first, second;

    Segment() = default;
    Segment(Point first, Point second): first(first), second(second) {}
  };
} // namespace geometry_library
