#pragma once

#include "./base.hpp"

#include <atcoder/modint.hpp>
#include <vector>

namespace math {
  using mint = atcoder::modint1000000007;
  class ModFactorial {
    vector<mint> fact, invfact;

  public:
    ModFactorial(int N): fact(N + 1), invfact(N + 1) {
      fact[0] = 1;
      for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i;
      invfact[N] = 1 / fact[N];
      for (int i = N - 1; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1);
    }

    mint factorial(int k) { return fact[k]; }
    mint inv_factorial(int k) { return invfact[k]; }
    mint inv(int k) { return mint(k).inv(); }

    mint permutation(int n, int k) { return fact[n] * invfact[n - k]; }
    mint combination(int n, int k) { return fact[n] * invfact[k] * invfact[n - k]; }
    mint homogeneous(int n, int k) { return combination(n + k - 1, k); }
  };
} // namespace math