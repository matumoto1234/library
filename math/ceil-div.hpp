#pragma once

namespace math {
  template <typename T>
  T ceil_div(T n, T d) {
    assert(d != 0);
    return n / d + ((n ^ d >= 0) and (n % d));
  }
}