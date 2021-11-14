#include "./base.hpp"

#include <vector>

namespace math {
  template <typename T>
  vector<T> factorize(T n) {
    vector<T> res;
    for (long long i = 2; i * i <= n; i++) {
      while (n % i == 0) {
        res.emplace_back(i);
        n /= i;
      }
    }
    if (n > 1) res.emplace_back(n);
    return res;
  }
} // namespace math