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
  bundledCode: "#line 2 \"data-structure/splay-tree.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/splay-tree.hpp\"\
    \n\n#include <vector>\n\nnamespace matumoto {\n  template <typename T, T (*op)(T,\
    \ T) = nullptr>\n  struct SplayTree {\n    struct node {\n      node *left, *right,\
    \ *parent;\n      int size;\n      T calc_value, value;\n\n      node(): left(nullptr),\
    \ right(nullptr), parent(nullptr), size(1) {}\n\n      // \u56DE\u8EE2\n     \
    \ void rotate() {\n        node *pp, *p, *c;\n        p = this->parent;\n    \
    \    pp = p->parent;\n\n        if (p->left == this) {\n          c = this->right;\n\
    \          this->right = p;\n          p->left = c;\n        } else {\n      \
    \    c = this->left;\n          this->left = p;\n          p->right = c;\n   \
    \     }\n\n        if (pp and pp->left == p)\n          pp->left = this;\n   \
    \     if (pp and pp->right == p)\n          pp->right = this;\n        this->parent\
    \ = pp;\n        p->parent = this;\n        if (c)\n          c->parent = p;\n\
    \n        p->update();\n        this->update();\n      }\n\n      // \u6839:0,\
    \ \u5DE6:1, \u53F3:-1\n      int state() {\n        if (!this->parent)\n     \
    \     return 0;\n        if (this->parent->left == this)\n          return 1;\n\
    \        if (this->parent->right == this)\n          return -1;\n        return\
    \ 0;\n      }\n\n      // \u6839\u306B\u306A\u308B\u307E\u3067\u56DE\u8EE2\n \
    \     void splay() {\n        while (this->state() != 0) {\n          // \u89AA\
    \u304C\u6839\n          if (this->parent->state() == 0) {\n            this->rotate();\n\
    \          } else if (this->state() == this->parent->state()) {\n            this->parent->rotate();\n\
    \            this->rotate();\n          } else {\n            this->rotate();\n\
    \            this->rotate();\n          }\n        }\n      }\n\n      // \u5DE6\
    \u53F3\u306E\u5B50\u306B\u5BFE\u3057\u3066\u64CD\u4F5C\n      void update() {\n\
    \        this->size = 1;\n        this->calc_value = value;\n        if (this->left)\
    \ {\n          this->size += left->size;\n          if (op)\n            this->calc_value\
    \ = op(this->calc_value, this->left->calc_value);\n        }\n        if (this->right)\
    \ {\n          this->size += right->size;\n          if (op)\n            this->calc_value\
    \ = op(this->calc_value, this->right->calc_value);\n        }\n      }\n    };\n\
    \n    node *_root;\n    vector<node> nodes;\n    SplayTree(int n): nodes(n) {\n\
    \      for (int i = 0; i < n - 1; i++) {\n        nodes[i].parent = &nodes[i +\
    \ 1];\n        nodes[i + 1].left = &nodes[i];\n        nodes[i + 1].update();\n\
    \      }\n      _root = &nodes[n - 1];\n    }\n\n    T &operator[](int idx) {\n\
    \      get(idx, _root);\n      _root->update();\n      return _root->value;\n\
    \    }\n\n    node *&root() {\n      return _root;\n    }\n\n    // root\u306E\
    \u5DE6\u304B\u3089\u306Eidx\u756A\u76EE\u306E\u9802\u70B9\u3092\u6839\u306B\u3057\
    \u3066\u8FD4\u3059\n    node *get(int idx, node *root) {\n      node *now = root;\n\
    \      while (true) {\n        int lsize = now->left ? now->left->size : 0;\n\
    \        if (idx < lsize)\n          now = now->left;\n        if (idx == lsize)\
    \ {\n          now->splay();\n          break;\n        }\n        if (idx > lsize)\
    \ {\n          now = now->right;\n          idx = idx - lsize - 1;\n        }\n\
    \      }\n      _root = now;\n      return now;\n    }\n\n    // lroot\u3068rroot\u3092\
    \u30DE\u30FC\u30B8\n    node *merge(node *lroot, node *rroot) {\n      if (!lroot)\n\
    \        return rroot;\n      if (!rroot)\n        return lroot;\n      lroot\
    \ = get(lroot->size - 1, lroot);\n      lroot->right = rroot;\n      rroot->parent\
    \ = lroot;\n      lroot->update();\n      return lroot;\n    }\n\n    // [0,n)\
    \ -> [0,idx),[idx,n)\n    pair<node *, node *> split(int idx, node *root) {\n\
    \      if (idx == 0)\n        return { nullptr, root };\n      if (idx == root->size)\n\
    \        return { root, nullptr };\n\n      root = get(idx, root);\n      node\
    \ *lroot, *rroot;\n      lroot = root->left;\n      rroot = root;\n      rroot->left\
    \ = nullptr;\n      lroot->parent = nullptr;\n      rroot->update();\n      return\
    \ { lroot, rroot };\n    }\n\n    node *insert(int idx, node *tmp, node *root)\
    \ {\n      auto trees = split(idx, root);\n      node *lroot = trees.first;\n\
    \      node *rroot = trees.second;\n      return merge(merge(lroot, tmp), rroot);\n\
    \    }\n\n    pair<node *, node *> erase(int idx, node *root) {\n      root =\
    \ get(idx, root);\n      node *lroot = root->left;\n      node *rroot = root->right;\n\
    \      if (lroot)\n        lroot->parent = nullptr;\n      if (rroot)\n      \
    \  rroot->parent = nullptr;\n      root->left = nullptr;\n      root->right =\
    \ nullptr;\n      root->update();\n      return { merge(lroot, rroot), root };\n\
    \    }\n\n    node *shift(int l, int r, node *root) {\n      auto temp = erase(r,\
    \ root);\n      root = temp.first;\n      node *node = temp.second;\n      return\
    \ insert(l, node, root);\n    }\n\n    pair<node *, int> prod(int l, int r, node\
    \ *root) {\n      node *lroot, *croot, *rroot;\n      auto temp = split(r + 1,\
    \ root);\n      rroot = temp.second;\n      temp = split(l, temp.first);\n   \
    \   lroot = temp.first;\n      croot = temp.second;\n      int ans = croot->calc_value;\n\
    \      return { merge(merge(lroot, croot), rroot), ans };\n    }\n  };\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\nnamespace\
    \ matumoto {\n  template <typename T, T (*op)(T, T) = nullptr>\n  struct SplayTree\
    \ {\n    struct node {\n      node *left, *right, *parent;\n      int size;\n\
    \      T calc_value, value;\n\n      node(): left(nullptr), right(nullptr), parent(nullptr),\
    \ size(1) {}\n\n      // \u56DE\u8EE2\n      void rotate() {\n        node *pp,\
    \ *p, *c;\n        p = this->parent;\n        pp = p->parent;\n\n        if (p->left\
    \ == this) {\n          c = this->right;\n          this->right = p;\n       \
    \   p->left = c;\n        } else {\n          c = this->left;\n          this->left\
    \ = p;\n          p->right = c;\n        }\n\n        if (pp and pp->left == p)\n\
    \          pp->left = this;\n        if (pp and pp->right == p)\n          pp->right\
    \ = this;\n        this->parent = pp;\n        p->parent = this;\n        if (c)\n\
    \          c->parent = p;\n\n        p->update();\n        this->update();\n \
    \     }\n\n      // \u6839:0, \u5DE6:1, \u53F3:-1\n      int state() {\n     \
    \   if (!this->parent)\n          return 0;\n        if (this->parent->left ==\
    \ this)\n          return 1;\n        if (this->parent->right == this)\n     \
    \     return -1;\n        return 0;\n      }\n\n      // \u6839\u306B\u306A\u308B\
    \u307E\u3067\u56DE\u8EE2\n      void splay() {\n        while (this->state() !=\
    \ 0) {\n          // \u89AA\u304C\u6839\n          if (this->parent->state() ==\
    \ 0) {\n            this->rotate();\n          } else if (this->state() == this->parent->state())\
    \ {\n            this->parent->rotate();\n            this->rotate();\n      \
    \    } else {\n            this->rotate();\n            this->rotate();\n    \
    \      }\n        }\n      }\n\n      // \u5DE6\u53F3\u306E\u5B50\u306B\u5BFE\u3057\
    \u3066\u64CD\u4F5C\n      void update() {\n        this->size = 1;\n        this->calc_value\
    \ = value;\n        if (this->left) {\n          this->size += left->size;\n \
    \         if (op)\n            this->calc_value = op(this->calc_value, this->left->calc_value);\n\
    \        }\n        if (this->right) {\n          this->size += right->size;\n\
    \          if (op)\n            this->calc_value = op(this->calc_value, this->right->calc_value);\n\
    \        }\n      }\n    };\n\n    node *_root;\n    vector<node> nodes;\n   \
    \ SplayTree(int n): nodes(n) {\n      for (int i = 0; i < n - 1; i++) {\n    \
    \    nodes[i].parent = &nodes[i + 1];\n        nodes[i + 1].left = &nodes[i];\n\
    \        nodes[i + 1].update();\n      }\n      _root = &nodes[n - 1];\n    }\n\
    \n    T &operator[](int idx) {\n      get(idx, _root);\n      _root->update();\n\
    \      return _root->value;\n    }\n\n    node *&root() {\n      return _root;\n\
    \    }\n\n    // root\u306E\u5DE6\u304B\u3089\u306Eidx\u756A\u76EE\u306E\u9802\
    \u70B9\u3092\u6839\u306B\u3057\u3066\u8FD4\u3059\n    node *get(int idx, node\
    \ *root) {\n      node *now = root;\n      while (true) {\n        int lsize =\
    \ now->left ? now->left->size : 0;\n        if (idx < lsize)\n          now =\
    \ now->left;\n        if (idx == lsize) {\n          now->splay();\n         \
    \ break;\n        }\n        if (idx > lsize) {\n          now = now->right;\n\
    \          idx = idx - lsize - 1;\n        }\n      }\n      _root = now;\n  \
    \    return now;\n    }\n\n    // lroot\u3068rroot\u3092\u30DE\u30FC\u30B8\n \
    \   node *merge(node *lroot, node *rroot) {\n      if (!lroot)\n        return\
    \ rroot;\n      if (!rroot)\n        return lroot;\n      lroot = get(lroot->size\
    \ - 1, lroot);\n      lroot->right = rroot;\n      rroot->parent = lroot;\n  \
    \    lroot->update();\n      return lroot;\n    }\n\n    // [0,n) -> [0,idx),[idx,n)\n\
    \    pair<node *, node *> split(int idx, node *root) {\n      if (idx == 0)\n\
    \        return { nullptr, root };\n      if (idx == root->size)\n        return\
    \ { root, nullptr };\n\n      root = get(idx, root);\n      node *lroot, *rroot;\n\
    \      lroot = root->left;\n      rroot = root;\n      rroot->left = nullptr;\n\
    \      lroot->parent = nullptr;\n      rroot->update();\n      return { lroot,\
    \ rroot };\n    }\n\n    node *insert(int idx, node *tmp, node *root) {\n    \
    \  auto trees = split(idx, root);\n      node *lroot = trees.first;\n      node\
    \ *rroot = trees.second;\n      return merge(merge(lroot, tmp), rroot);\n    }\n\
    \n    pair<node *, node *> erase(int idx, node *root) {\n      root = get(idx,\
    \ root);\n      node *lroot = root->left;\n      node *rroot = root->right;\n\
    \      if (lroot)\n        lroot->parent = nullptr;\n      if (rroot)\n      \
    \  rroot->parent = nullptr;\n      root->left = nullptr;\n      root->right =\
    \ nullptr;\n      root->update();\n      return { merge(lroot, rroot), root };\n\
    \    }\n\n    node *shift(int l, int r, node *root) {\n      auto temp = erase(r,\
    \ root);\n      root = temp.first;\n      node *node = temp.second;\n      return\
    \ insert(l, node, root);\n    }\n\n    pair<node *, int> prod(int l, int r, node\
    \ *root) {\n      node *lroot, *croot, *rroot;\n      auto temp = split(r + 1,\
    \ root);\n      rroot = temp.second;\n      temp = split(l, temp.first);\n   \
    \   lroot = temp.first;\n      croot = temp.second;\n      int ans = croot->calc_value;\n\
    \      return { merge(merge(lroot, croot), rroot), ans };\n    }\n  };\n} // namespace\
    \ matumoto"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/splay-tree.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/splay-tree.hpp
layout: document
redirect_from:
- /library/data-structure/splay-tree.hpp
- /library/data-structure/splay-tree.hpp.html
title: data-structure/splay-tree.hpp
---
