#pragma once

#include "./ccw.hpp"

namespace geometry_library {
  // s1 contains s2
  bool contains_ss(const Segment &s1, const Segment &s2) {
    CCW ccw;
    bool first_on_segment = ccw(s1, s2.first) == CCW::ON_SEGMENT;
    bool second_on_segment = ccw(s1, s2.second) == CCW::ON_SEGMENT;
    return first_on_segment and second_on_segment;
  }
}
