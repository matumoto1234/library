---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/mex-set.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/mex-set.hpp\"\
    \n\n#include <set>\n\nnamespace matumoto {\n  // verify:hhkb2020_C\n  template\
    \ <typename T = long long>\n  struct MexSet {\n    set<pair<T, T>> s;\n\n    T\
    \ inf() {\n      return numeric_limits<T>::max() / 2;\n    }\n\n    MexSet() {\n\
    \      s.emplace(inf(), inf());\n      s.emplace(-inf(), -inf());\n    }\n\n \
    \   bool contains(T x) const {\n      auto [lower, upper] = *prev(s.lower_bound(pair(x\
    \ + 1, x + 1)));\n      return lower <= x and x <= upper;\n    }\n\n    bool insert(T\
    \ x) {\n      if (contains(x))\n        return false;\n      auto nit = s.lower_bound(pair(x\
    \ + 1, x + 1));\n      auto it = prev(nit);\n      auto [l, u] = *it;\n      auto\
    \ [nl, nu] = *nit;\n      if (u == x - 1) {\n        if (nl == x + 1) {\n    \
    \      s.erase(it);\n          s.erase(nit);\n          s.emplace(l, nu);\n  \
    \      } else {\n          s.erase(it);\n          s.emplace(l, x);\n        }\n\
    \      } else {\n        if (nl == x + 1) {\n          s.erase(nit);\n       \
    \   s.emplace(x, nu);\n        } else {\n          s.emplace(x, x);\n        }\n\
    \      }\n      return true;\n    }\n\n    bool erase(T x) {\n      if (!contains(x))\n\
    \        return false;\n      auto it = prev(s.lower_bound(pair(x + 1, x + 1)));\n\
    \      auto [l, u] = *it;\n      s.erase(it);\n      if (x != l)\n        s.emplace(l,\
    \ x - 1);\n      if (x != u)\n        s.emplace(x + 1, u);\n      return true;\n\
    \    }\n\n    T mex(T x = 0) const {\n      auto [l, u] = *prev(s.lower_bound(pair(x\
    \ + 1, x + 1)));\n      if (l <= x and x <= u) {\n        return u + 1;\n    \
    \  } else {\n        return x;\n      }\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <set>\n\nnamespace matumoto\
    \ {\n  // verify:hhkb2020_C\n  template <typename T = long long>\n  struct MexSet\
    \ {\n    set<pair<T, T>> s;\n\n    T inf() {\n      return numeric_limits<T>::max()\
    \ / 2;\n    }\n\n    MexSet() {\n      s.emplace(inf(), inf());\n      s.emplace(-inf(),\
    \ -inf());\n    }\n\n    bool contains(T x) const {\n      auto [lower, upper]\
    \ = *prev(s.lower_bound(pair(x + 1, x + 1)));\n      return lower <= x and x <=\
    \ upper;\n    }\n\n    bool insert(T x) {\n      if (contains(x))\n        return\
    \ false;\n      auto nit = s.lower_bound(pair(x + 1, x + 1));\n      auto it =\
    \ prev(nit);\n      auto [l, u] = *it;\n      auto [nl, nu] = *nit;\n      if\
    \ (u == x - 1) {\n        if (nl == x + 1) {\n          s.erase(it);\n       \
    \   s.erase(nit);\n          s.emplace(l, nu);\n        } else {\n          s.erase(it);\n\
    \          s.emplace(l, x);\n        }\n      } else {\n        if (nl == x +\
    \ 1) {\n          s.erase(nit);\n          s.emplace(x, nu);\n        } else {\n\
    \          s.emplace(x, x);\n        }\n      }\n      return true;\n    }\n\n\
    \    bool erase(T x) {\n      if (!contains(x))\n        return false;\n     \
    \ auto it = prev(s.lower_bound(pair(x + 1, x + 1)));\n      auto [l, u] = *it;\n\
    \      s.erase(it);\n      if (x != l)\n        s.emplace(l, x - 1);\n      if\
    \ (x != u)\n        s.emplace(x + 1, u);\n      return true;\n    }\n\n    T mex(T\
    \ x = 0) const {\n      auto [l, u] = *prev(s.lower_bound(pair(x + 1, x + 1)));\n\
    \      if (l <= x and x <= u) {\n        return u + 1;\n      } else {\n     \
    \   return x;\n      }\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/mex-set.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/mex-set.hpp
layout: document
redirect_from:
- /library/data-structure/mex-set.hpp
- /library/data-structure/mex-set.hpp.html
title: data-structure/mex-set.hpp
---
