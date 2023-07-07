#pragma once

#include <cmath>

namespace matumoto {
  using namespace std;
  using Real = double;

  constexpr Real PI = M_PI;
  constexpr Real EPS = 1e-9;

  inline int sign(Real a) {
    if (a < -EPS)
      return -1;
    if (a > +EPS)
      return +1;
    return 0;
  }

  inline bool equals(Real a, Real b) {
    return sign(a - b) == 0;
  }
} // namespace matumoto