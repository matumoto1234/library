#pragma once

#include "./point.hpp"

namespace matumoto {
  struct Line {
    Point a, b;

    Line() = default;
    Line(const Point &a, const Point &b): a(a), b(b) {}
  };
} // namespace matumoto