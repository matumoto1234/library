---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/segment-sieve.hpp\"\n\n#line 2 \"math/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/segment-sieve.hpp\"\n\n#include <cassert>\n#include\
    \ <cmath>\n#include <numeric>\n#include <vector>\n\nnamespace matumoto {\n  class\
    \ SegmentSieve {\n    ll l, r, sqrt_r;\n    vector<int> small_sieve;\n    vector<vector<ll>>\
    \ large_sieve;\n    vector<ll> aux; // aux[i] := large_sieve[i] \u306E\u7D20\u56E0\
    \u6570\u306E\u7A4D\n\n  public:\n    SegmentSieve(ll l, ll r): l(l), r(r), sqrt_r(sqrt(r)\
    \ + 1) {\n      small_sieve.resize(sqrt_r);\n      iota(small_sieve.begin(), small_sieve.end(),\
    \ 0);\n      large_sieve.resize(r - l);\n      aux.assign(r - l, 1);\n\n     \
    \ for (ll i = 2; i * i < r; i++) {\n        if (small_sieve[i] < i)\n        \
    \  continue;\n\n        small_sieve[i] = i;\n        for (ll j = i * i; j < sqrt_r;\
    \ j += i) {\n          if (small_sieve[j] == j)\n            small_sieve[j] =\
    \ i;\n        }\n\n        ll begin = (l + i - 1) / i * i;\n\n        for (ll\
    \ j = begin; j < r; j += i) {\n          ll k = j;\n          do {\n         \
    \   // aux[j - l] > sqrt_r ?\n            if (aux[j - l] * aux[j - l] > r)\n \
    \             break;\n\n            large_sieve[j - l].push_back(i);\n       \
    \     aux[j - l] *= i;\n            k /= i;\n          } while (k % i == 0);\n\
    \        }\n      }\n    }\n\n    vector<ll> factor(ll n) {\n      assert(l <=\
    \ n and n < r);\n\n      vector<ll> res = large_sieve[n - l];\n      n /= aux[n\
    \ - l];\n\n      if (n >= sqrt_r) {\n        res.push_back(n);\n        return\
    \ res;\n      }\n\n      while (n > 1) {\n        res.push_back(small_sieve[n]);\n\
    \        n /= small_sieve[n];\n      }\n\n      return res;\n    }\n  };\n}; //\
    \ namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nnamespace matumoto {\n  class SegmentSieve\
    \ {\n    ll l, r, sqrt_r;\n    vector<int> small_sieve;\n    vector<vector<ll>>\
    \ large_sieve;\n    vector<ll> aux; // aux[i] := large_sieve[i] \u306E\u7D20\u56E0\
    \u6570\u306E\u7A4D\n\n  public:\n    SegmentSieve(ll l, ll r): l(l), r(r), sqrt_r(sqrt(r)\
    \ + 1) {\n      small_sieve.resize(sqrt_r);\n      iota(small_sieve.begin(), small_sieve.end(),\
    \ 0);\n      large_sieve.resize(r - l);\n      aux.assign(r - l, 1);\n\n     \
    \ for (ll i = 2; i * i < r; i++) {\n        if (small_sieve[i] < i)\n        \
    \  continue;\n\n        small_sieve[i] = i;\n        for (ll j = i * i; j < sqrt_r;\
    \ j += i) {\n          if (small_sieve[j] == j)\n            small_sieve[j] =\
    \ i;\n        }\n\n        ll begin = (l + i - 1) / i * i;\n\n        for (ll\
    \ j = begin; j < r; j += i) {\n          ll k = j;\n          do {\n         \
    \   // aux[j - l] > sqrt_r ?\n            if (aux[j - l] * aux[j - l] > r)\n \
    \             break;\n\n            large_sieve[j - l].push_back(i);\n       \
    \     aux[j - l] *= i;\n            k /= i;\n          } while (k % i == 0);\n\
    \        }\n      }\n    }\n\n    vector<ll> factor(ll n) {\n      assert(l <=\
    \ n and n < r);\n\n      vector<ll> res = large_sieve[n - l];\n      n /= aux[n\
    \ - l];\n\n      if (n >= sqrt_r) {\n        res.push_back(n);\n        return\
    \ res;\n      }\n\n      while (n > 1) {\n        res.push_back(small_sieve[n]);\n\
    \        n /= small_sieve[n];\n      }\n\n      return res;\n    }\n  };\n}; //\
    \ namespace matumoto"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/segment-sieve.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/segment-sieve.hpp
layout: document
redirect_from:
- /library/math/segment-sieve.hpp
- /library/math/segment-sieve.hpp.html
title: math/segment-sieve.hpp
---
