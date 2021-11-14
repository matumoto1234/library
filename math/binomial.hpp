#pragma once

namespace math {
  template <typename T>
  T binomial(T n, T r) {
    T res = 1;
    for (T i = 0; i < r; i++) {
      res *= n - i;
      res /= i + 1;
    }
    return res;
  }
} // namespace math