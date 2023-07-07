#pragma once

#include "./base.hpp"

#include <vector>

namespace matumoto {
  using mint = atcoder::modint1000000007;
  template <typename ModInt = mint>
  class ModFactorial {
    vector<ModInt> fact, invfact;

    int min_pow2_greater_equal_than(int k) {
      int pow2 = 1;
      while (pow2 < k) {
        pow2 <<= 1;
      }
      return pow2;
    }

  public:
    ModFactorial(): fact(1, 1), invfact(1, 1) {}

    ModInt factorial(int k) {
      if (k < 0)
        return 0;
      if (k < static_cast<int>(fact.size()))
        return fact[k];

      int pow2 = min_pow2_greater_equal_than(k);
      int old_size = fact.size();
      fact.resize(pow2 + 1);

      for (int i = old_size - 1; i < pow2; i++) {
        fact[i + 1] = fact[i] * ModInt(i + 1);
      }
      return fact[k];
    }

    ModInt inv_factorial(int k) {
      if (k < 0)
        return 0;
      if (k < static_cast<int>(invfact.size()))
        return invfact[k];

      int pow2 = min_pow2_greater_equal_than(k);
      int old_size = fact.size();
      invfact.resize(pow2 + 1);

      invfact[pow2] = ModInt(1) / factorial(pow2);
      for (int i = pow2; i > old_size; i--) {
        invfact[i - 1] = invfact[i] * ModInt(i);
      }
      return invfact[k];
    }

    ModInt inv(int k) {
      return ModInt(1) / ModInt(k);
    }

    ModInt permutation(int n, int k) {
      return factorial(n) * inv_factorial(n - k);
    }
    ModInt combination(int n, int k) {
      return factorial(n) * inv_factorial(k) * inv_factorial(n - k);
    }
    ModInt homogeneous(int n, int k) {
      return combination(n + k - 1, k);
    }
  };
} // namespace matumoto