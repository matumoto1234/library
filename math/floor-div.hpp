#pragma once

namespace library_math {
  template <typename T>
  constexpr T floor_div(T n, T d) {
    assert(d != 0);
    return n / d - (((n ^ d) < 0) and (n % d));
  }
} // namespace library_math