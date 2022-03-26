#pragma once

namespace math_library {
  template <typename T>
  constexpr T floor_div(T n, T d) {
    assert(d != 0);
    return n / d - (((n ^ d) < 0) and (n % d));
  }
} // namespace math_library