#pragma once

#include "./base.hpp"

#include <cassert>

namespace math_library {
  constexpr ll ceil_div(ll n, ll d) {
    assert(d != 0);
    return n / d + (((n ^ d) >= 0) and (n % d));
  }
} // namespace math_library