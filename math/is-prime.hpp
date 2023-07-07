#pragma once

namespace matumoto {
  constexpr bool is_prime(int n) {
    if (n <= 1)
      return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
} // namespace matumoto