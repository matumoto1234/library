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
  bundledCode: "#line 2 \"data-structure/dynamic-segment-tree.hpp\"\n\n#line 2 \"\
    data-structure/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n}\n\
    #line 4 \"data-structure/dynamic-segment-tree.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nnamespace matumoto {\n  template <typename T, T (*op)(T, T), T (*e)()>\n\
    \  class DynamicSegmentTree {\n  private:\n    using ll = long long;\n    struct\
    \ node {\n      node *left, *right;\n      T v;\n\n      node(): left(nullptr),\
    \ right(nullptr), v(e()) {}\n    };\n\n    ll n;\n\n    T prod(ll a, ll b, node\
    \ *now, ll l, ll r) {\n      if (a <= l and r <= b) {\n        return now->v;\n\
    \      }\n      if (r <= a or b <= l) {\n        return e();\n      }\n\n    \
    \  T lv = e(), rv = e();\n      if (now->left)\n        lv = prod(a, b, now->left,\
    \ l, (l + r) / 2);\n      if (now->right)\n        rv = prod(a, b, now->right,\
    \ (l + r) / 2, r);\n      return op(lv, rv);\n    }\n\n    void debug_dfs(node\
    \ *now, string spaces) {\n      if (now->right) {\n        debug_dfs(now->right,\
    \ spaces + \"   \");\n      }\n      cerr << spaces << now->v << \"\\n\";\n  \
    \    if (now->left) {\n        debug_dfs(now->left, spaces + \"   \");\n     \
    \ }\n    }\n\n  public:\n    node *root;\n    DynamicSegmentTree(ll n_) {\n  \
    \    n = 1;\n      while (n < n_) {\n        n *= 2;\n      }\n      root = new\
    \ node();\n    }\n\n    void add(ll k, T x) {\n      node *now = root;\n     \
    \ ll l = 0, r = n;\n      now->v = op(now->v, x);\n      while (r - l > 1) {\n\
    \        ll m = (l + r) / 2;\n        if (k < m) {\n          if (!now->left)\n\
    \            now->left = new node();\n          now = now->left;\n          r\
    \ = m;\n        } else {\n          if (!now->right)\n            now->right =\
    \ new node();\n          now = now->right;\n          l = m;\n        }\n    \
    \    now->v = op(now->v, x);\n      }\n    }\n\n    void debug() {\n      debug_dfs(root,\
    \ \"\");\n    }\n\n    T prod(ll l, ll r) {\n      return prod(l, r, root, 0,\
    \ n);\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nnamespace matumoto {\n  template <typename T, T (*op)(T, T), T (*e)()>\n\
    \  class DynamicSegmentTree {\n  private:\n    using ll = long long;\n    struct\
    \ node {\n      node *left, *right;\n      T v;\n\n      node(): left(nullptr),\
    \ right(nullptr), v(e()) {}\n    };\n\n    ll n;\n\n    T prod(ll a, ll b, node\
    \ *now, ll l, ll r) {\n      if (a <= l and r <= b) {\n        return now->v;\n\
    \      }\n      if (r <= a or b <= l) {\n        return e();\n      }\n\n    \
    \  T lv = e(), rv = e();\n      if (now->left)\n        lv = prod(a, b, now->left,\
    \ l, (l + r) / 2);\n      if (now->right)\n        rv = prod(a, b, now->right,\
    \ (l + r) / 2, r);\n      return op(lv, rv);\n    }\n\n    void debug_dfs(node\
    \ *now, string spaces) {\n      if (now->right) {\n        debug_dfs(now->right,\
    \ spaces + \"   \");\n      }\n      cerr << spaces << now->v << \"\\n\";\n  \
    \    if (now->left) {\n        debug_dfs(now->left, spaces + \"   \");\n     \
    \ }\n    }\n\n  public:\n    node *root;\n    DynamicSegmentTree(ll n_) {\n  \
    \    n = 1;\n      while (n < n_) {\n        n *= 2;\n      }\n      root = new\
    \ node();\n    }\n\n    void add(ll k, T x) {\n      node *now = root;\n     \
    \ ll l = 0, r = n;\n      now->v = op(now->v, x);\n      while (r - l > 1) {\n\
    \        ll m = (l + r) / 2;\n        if (k < m) {\n          if (!now->left)\n\
    \            now->left = new node();\n          now = now->left;\n          r\
    \ = m;\n        } else {\n          if (!now->right)\n            now->right =\
    \ new node();\n          now = now->right;\n          l = m;\n        }\n    \
    \    now->v = op(now->v, x);\n      }\n    }\n\n    void debug() {\n      debug_dfs(root,\
    \ \"\");\n    }\n\n    T prod(ll l, ll r) {\n      return prod(l, r, root, 0,\
    \ n);\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-segment-tree.hpp
- /library/data-structure/dynamic-segment-tree.hpp.html
title: data-structure/dynamic-segment-tree.hpp
---
