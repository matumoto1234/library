#pragma once

#include "./point.hpp"

namespace library_geometry {
  struct Line {
    Point a, b;

    Line() = default;
    Line(const Point &a, const Point &b): a(a), b(b) {}
  };
} // namespace library_geometry