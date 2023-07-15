---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"graph/tree.hpp\"\n\n#include\
    \ <vector>\n\n// WIP\n\nnamespace matumoto {\n  // path_query    : op,e,inv\n\
    \  // subtree_query : op,e\n  // op   : T, T -> T (operation)\n  // e    : void\
    \ -> T (identity element)\n  // inv  : T    -> T (inverse element)\n  // T is\
    \ weight type and value type\n  template <typename T, T (*op)(T, T), T (*e)(),\
    \ T (*inv)(T)>\n  class WeightedTree {\n  private:\n    struct SparseTable {\n\
    \      vector<vector<pair<int, int>>> st;\n      vector<int> lookup;\n\n     \
    \ SparseTable() {}\n\n      void build(const vector<pair<int, int>> &v) {\n  \
    \      int b = 0;\n        while ((1 << b) <= static_cast<int>(v.size()))\n  \
    \        ++b;\n        st.assign(b, vector<pair<int, int>>(1 << b));\n       \
    \ for (int i = 0; i < static_cast<int>(v.size()); i++) {\n          st[0][i] =\
    \ v[i];\n        }\n        for (int i = 1; i < b; i++) {\n          for (int\
    \ j = 0; j + (1 << i) <= (1 << b); j++) {\n            st[i][j] = min(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n          }\n        }\n        lookup.resize(v.size()\
    \ + 1);\n        for (int i = 2; i < static_cast<int>(lookup.size()); i++) {\n\
    \          lookup[i] = lookup[i >> 1] + 1;\n        }\n      }\n\n      inline\
    \ pair<int, int> query(int l, int r) {\n        int b = lookup[r - l];\n     \
    \   return min(st[b][l], st[b][r - (1 << b)]);\n      }\n    };\n\n    class SegmentTree\
    \ {\n    private:\n      int n;\n      vector<T> data;\n\n      T search(int l,\
    \ int r) {\n        T vl = e(), vr = e();\n        l += n, r += n;\n        while\
    \ (l < r) {\n          if (l & 1)\n            vl = op(vl, data[l++]);\n     \
    \     if (r & 1)\n            vr = op(vr, data[--r]);\n          l >>= 1, r >>=\
    \ 1;\n        }\n        return op(vl, vr);\n      }\n\n    public:\n      SegmentTree()\
    \ {}\n\n      void assign(int _n) {\n        n = 1;\n        while (n < _n) {\n\
    \          n <<= 1;\n        }\n        data.assign(2 * n, e());\n      }\n\n\
    \      T get(int i) {\n        return data[i + n];\n      }\n\n      void set(int\
    \ i, T key) {\n        i += n;\n        data[i] = key;\n        while (i > 0)\
    \ {\n          i >>= 1;\n          data[i] = op(data[i << 1 | 0], data[i << 1\
    \ | 1]);\n        }\n      }\n\n      void add(int i, T key) {\n        set(i,\
    \ get(i) + key);\n      }\n\n      T prod(int l, int r) {\n        return search(l,\
    \ r);\n      }\n\n      T all_prod() {\n        return n != 0 ? data[0] : e();\n\
    \      }\n    };\n\n    SparseTable min_dep_idx;\n    SegmentTree data;\n    vector<int>\
    \ in, out, dep, par, dia_to, edge_table;\n    pair<T, int> dia;\n    vector<vector<int>>\
    \ doubling_par;\n    vector<vector<pair<int, T>>> G;\n    vector<T> data;\n  \
    \  const int LOG;\n\n    void dfs(int v, int &time, int depth) {\n      in[v]\
    \ = time;\n      dep[time] = depth;\n      edge_table[time++] = v;\n      for\
    \ (auto to: G[v]) {\n        if (in[to] != -1)\n          continue;\n        par[to]\
    \ = v;\n        dfs(to, time, depth + 1);\n      }\n      out[v] = time;\n   \
    \   dep[time] = depth - 1;\n      edge_table[time++] = -v;\n    }\n\n    pair<T,\
    \ int> dfs_diameter(int v, int p) {\n      pair<T, int> res(0, v);\n      for\
    \ (auto [to, cost]: G[v]) {\n        if (to == par)\n          continue;\n   \
    \     auto [ncost, u] = dfs_diameter(to, v);\n        if (res < make_pair(ncost\
    \ + cost, u)) {\n          res = make_pair(ncost + cost);\n          dia_to[v]\
    \ = to;\n        }\n      }\n      return res;\n    }\n\n    // min({ x | 2^x\
    \ > n })\n    int log_two(int n) {\n      int x = 1;\n      while ((1 << x) <=\
    \ n) {\n        x++;\n      }\n      return x;\n    }\n\n  public:\n    WeightedTree(int\
    \ n): G(n), data(n), LOG(log_two(n)), dia(-1) {\n      data.assign(n);\n    }\n\
    \n    void add_edge(int from, int to, T cost = 1) {\n      G[from].emplace_back(to,\
    \ cost);\n    }\n\n    T path_query(int v) {\n      return data.prod(0, in[v]\
    \ + 1);\n    }\n\n    // O(log N)\n    T path_query(int u, int v) {\n      T res\
    \ = op(path_query(u), path_query(v));\n      res = op(res, inv(path_query(lca(u,\
    \ v))));\n      res = op(res, inv(path_query(lca(u, v))));\n      return res;\n\
    \    }\n\n    // O(log N)\n    T subtree_query(int v) {\n      return data.prod(in[v],\
    \ out[v]);\n    }\n\n    // O(Nlog N)\n    void build(int s) {\n      int n =\
    \ G.size();\n\n      dia_to.assign(n, -1);\n      dia = dfs_diameter(dfs_diameter(s,\
    \ -1).second, -1);\n\n      in.assign(n, -1);\n      out.assign(n, -1);\n    \
    \  par.assign(n, 0);\n      dep.assign(2 * n, 0);\n      edge_table.assign(2 *\
    \ n, -1);\n      int time = 0;\n      dfs(s, time, 0);\n      dep.back() = s;\n\
    \n      // build doubling parent\n      doubling_par.assign(LOG, vector<int>(n,\
    \ -1));\n      for (int i = 0; i < n; i++) {\n        doubling_par[0][i] = par[i];\n\
    \      }\n      for (int k = 0; k < LOG - 1; k++) {\n        for (int i = 0; i\
    \ < n; i++) {\n          if (doubling_par[k][i] == -1) {\n            doubling_par[k\
    \ + 1][i] = -1;\n            continue;\n          }\n          doubling_par[k\
    \ + 1][i] = doubling_par[k][doubling_par[k][i]];\n        }\n      }\n\n     \
    \ // build sparse table\n      vector<pair<int, int>> dep_idx(dep.size());\n \
    \     for (int i = 0; i < static_cast<int>(dep.size()); i++) {\n        auto &[depth,\
    \ idx] = dep_idx[i];\n        depth = dep[i];\n        idx = i;\n      }\n   \
    \   min_dep_idx.build(dep_idx);\n    }\n\n    // O(1)\n    T diameter() {\n  \
    \    return dia.first;\n    }\n\n    // O(N)\n    vector<int> diameter_path()\
    \ {\n      int v = dia.second;\n      vector<int> path;\n      path.reserve(dia.first);\n\
    \      while (v != -1) {\n        path.emplace_back(v);\n        v = dia_to[v];\n\
    \      }\n      return path;\n    }\n\n    // O(1)\n    bool in_subtree(int subroot,\
    \ int v) {\n      return in[subroot] < in[v] and out[v] < out[subroot];\n    }\n\
    \n    // O(1) : lowest common ancestor\n    int lca(int u, int v) {\n      int\
    \ idx = min_dep_idx.query(min(in[u], in[v]), max(in[u], in[v]) + 1).second;\n\
    \      int res = edge_table[idx];\n      if (res < 0)\n        res = par[-res];\n\
    \      return res;\n    }\n\n    // O(log N) : level ancestor\n    int la(int\
    \ v, int depth) {\n      int anc = v;\n      for (int i = 0; i < LOG; i++) {\n\
    \        if (depth >> i & 1)\n          anc = doubling_par[i][anc];\n      }\n\
    \      return anc;\n    }\n\n    // O(1)\n    int depth(int v) {\n      return\
    \ dep[in[v]];\n    }\n\n    // O(1)\n    int distance(int u, int v) {\n      return\
    \ depth(u) + depth(v) - 2 * depth(lca(u, v));\n    }\n\n    // O(1) : from v to\
    \ root move k step\n    int up(int v, int k) {\n      return la(v, depth(v) -\
    \ k);\n    }\n\n    // O(1) : from u to v move k step\n    int next(int u, int\
    \ v, int k = 1) {\n      if (k <= distance(u, lca(u, v)))\n        return up(u,\
    \ k);\n      return up(v, distance(v, lca(u, v)) - k);\n    }\n  };\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <vector>\n\n// WIP\n\n\
    namespace matumoto {\n  // path_query    : op,e,inv\n  // subtree_query : op,e\n\
    \  // op   : T, T -> T (operation)\n  // e    : void -> T (identity element)\n\
    \  // inv  : T    -> T (inverse element)\n  // T is weight type and value type\n\
    \  template <typename T, T (*op)(T, T), T (*e)(), T (*inv)(T)>\n  class WeightedTree\
    \ {\n  private:\n    struct SparseTable {\n      vector<vector<pair<int, int>>>\
    \ st;\n      vector<int> lookup;\n\n      SparseTable() {}\n\n      void build(const\
    \ vector<pair<int, int>> &v) {\n        int b = 0;\n        while ((1 << b) <=\
    \ static_cast<int>(v.size()))\n          ++b;\n        st.assign(b, vector<pair<int,\
    \ int>>(1 << b));\n        for (int i = 0; i < static_cast<int>(v.size()); i++)\
    \ {\n          st[0][i] = v[i];\n        }\n        for (int i = 1; i < b; i++)\
    \ {\n          for (int j = 0; j + (1 << i) <= (1 << b); j++) {\n            st[i][j]\
    \ = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n          }\n        }\n\
    \        lookup.resize(v.size() + 1);\n        for (int i = 2; i < static_cast<int>(lookup.size());\
    \ i++) {\n          lookup[i] = lookup[i >> 1] + 1;\n        }\n      }\n\n  \
    \    inline pair<int, int> query(int l, int r) {\n        int b = lookup[r - l];\n\
    \        return min(st[b][l], st[b][r - (1 << b)]);\n      }\n    };\n\n    class\
    \ SegmentTree {\n    private:\n      int n;\n      vector<T> data;\n\n      T\
    \ search(int l, int r) {\n        T vl = e(), vr = e();\n        l += n, r +=\
    \ n;\n        while (l < r) {\n          if (l & 1)\n            vl = op(vl, data[l++]);\n\
    \          if (r & 1)\n            vr = op(vr, data[--r]);\n          l >>= 1,\
    \ r >>= 1;\n        }\n        return op(vl, vr);\n      }\n\n    public:\n  \
    \    SegmentTree() {}\n\n      void assign(int _n) {\n        n = 1;\n       \
    \ while (n < _n) {\n          n <<= 1;\n        }\n        data.assign(2 * n,\
    \ e());\n      }\n\n      T get(int i) {\n        return data[i + n];\n      }\n\
    \n      void set(int i, T key) {\n        i += n;\n        data[i] = key;\n  \
    \      while (i > 0) {\n          i >>= 1;\n          data[i] = op(data[i << 1\
    \ | 0], data[i << 1 | 1]);\n        }\n      }\n\n      void add(int i, T key)\
    \ {\n        set(i, get(i) + key);\n      }\n\n      T prod(int l, int r) {\n\
    \        return search(l, r);\n      }\n\n      T all_prod() {\n        return\
    \ n != 0 ? data[0] : e();\n      }\n    };\n\n    SparseTable min_dep_idx;\n \
    \   SegmentTree data;\n    vector<int> in, out, dep, par, dia_to, edge_table;\n\
    \    pair<T, int> dia;\n    vector<vector<int>> doubling_par;\n    vector<vector<pair<int,\
    \ T>>> G;\n    vector<T> data;\n    const int LOG;\n\n    void dfs(int v, int\
    \ &time, int depth) {\n      in[v] = time;\n      dep[time] = depth;\n      edge_table[time++]\
    \ = v;\n      for (auto to: G[v]) {\n        if (in[to] != -1)\n          continue;\n\
    \        par[to] = v;\n        dfs(to, time, depth + 1);\n      }\n      out[v]\
    \ = time;\n      dep[time] = depth - 1;\n      edge_table[time++] = -v;\n    }\n\
    \n    pair<T, int> dfs_diameter(int v, int p) {\n      pair<T, int> res(0, v);\n\
    \      for (auto [to, cost]: G[v]) {\n        if (to == par)\n          continue;\n\
    \        auto [ncost, u] = dfs_diameter(to, v);\n        if (res < make_pair(ncost\
    \ + cost, u)) {\n          res = make_pair(ncost + cost);\n          dia_to[v]\
    \ = to;\n        }\n      }\n      return res;\n    }\n\n    // min({ x | 2^x\
    \ > n })\n    int log_two(int n) {\n      int x = 1;\n      while ((1 << x) <=\
    \ n) {\n        x++;\n      }\n      return x;\n    }\n\n  public:\n    WeightedTree(int\
    \ n): G(n), data(n), LOG(log_two(n)), dia(-1) {\n      data.assign(n);\n    }\n\
    \n    void add_edge(int from, int to, T cost = 1) {\n      G[from].emplace_back(to,\
    \ cost);\n    }\n\n    T path_query(int v) {\n      return data.prod(0, in[v]\
    \ + 1);\n    }\n\n    // O(log N)\n    T path_query(int u, int v) {\n      T res\
    \ = op(path_query(u), path_query(v));\n      res = op(res, inv(path_query(lca(u,\
    \ v))));\n      res = op(res, inv(path_query(lca(u, v))));\n      return res;\n\
    \    }\n\n    // O(log N)\n    T subtree_query(int v) {\n      return data.prod(in[v],\
    \ out[v]);\n    }\n\n    // O(Nlog N)\n    void build(int s) {\n      int n =\
    \ G.size();\n\n      dia_to.assign(n, -1);\n      dia = dfs_diameter(dfs_diameter(s,\
    \ -1).second, -1);\n\n      in.assign(n, -1);\n      out.assign(n, -1);\n    \
    \  par.assign(n, 0);\n      dep.assign(2 * n, 0);\n      edge_table.assign(2 *\
    \ n, -1);\n      int time = 0;\n      dfs(s, time, 0);\n      dep.back() = s;\n\
    \n      // build doubling parent\n      doubling_par.assign(LOG, vector<int>(n,\
    \ -1));\n      for (int i = 0; i < n; i++) {\n        doubling_par[0][i] = par[i];\n\
    \      }\n      for (int k = 0; k < LOG - 1; k++) {\n        for (int i = 0; i\
    \ < n; i++) {\n          if (doubling_par[k][i] == -1) {\n            doubling_par[k\
    \ + 1][i] = -1;\n            continue;\n          }\n          doubling_par[k\
    \ + 1][i] = doubling_par[k][doubling_par[k][i]];\n        }\n      }\n\n     \
    \ // build sparse table\n      vector<pair<int, int>> dep_idx(dep.size());\n \
    \     for (int i = 0; i < static_cast<int>(dep.size()); i++) {\n        auto &[depth,\
    \ idx] = dep_idx[i];\n        depth = dep[i];\n        idx = i;\n      }\n   \
    \   min_dep_idx.build(dep_idx);\n    }\n\n    // O(1)\n    T diameter() {\n  \
    \    return dia.first;\n    }\n\n    // O(N)\n    vector<int> diameter_path()\
    \ {\n      int v = dia.second;\n      vector<int> path;\n      path.reserve(dia.first);\n\
    \      while (v != -1) {\n        path.emplace_back(v);\n        v = dia_to[v];\n\
    \      }\n      return path;\n    }\n\n    // O(1)\n    bool in_subtree(int subroot,\
    \ int v) {\n      return in[subroot] < in[v] and out[v] < out[subroot];\n    }\n\
    \n    // O(1) : lowest common ancestor\n    int lca(int u, int v) {\n      int\
    \ idx = min_dep_idx.query(min(in[u], in[v]), max(in[u], in[v]) + 1).second;\n\
    \      int res = edge_table[idx];\n      if (res < 0)\n        res = par[-res];\n\
    \      return res;\n    }\n\n    // O(log N) : level ancestor\n    int la(int\
    \ v, int depth) {\n      int anc = v;\n      for (int i = 0; i < LOG; i++) {\n\
    \        if (depth >> i & 1)\n          anc = doubling_par[i][anc];\n      }\n\
    \      return anc;\n    }\n\n    // O(1)\n    int depth(int v) {\n      return\
    \ dep[in[v]];\n    }\n\n    // O(1)\n    int distance(int u, int v) {\n      return\
    \ depth(u) + depth(v) - 2 * depth(lca(u, v));\n    }\n\n    // O(1) : from v to\
    \ root move k step\n    int up(int v, int k) {\n      return la(v, depth(v) -\
    \ k);\n    }\n\n    // O(1) : from u to v move k step\n    int next(int u, int\
    \ v, int k = 1) {\n      if (k <= distance(u, lca(u, v)))\n        return up(u,\
    \ k);\n      return up(v, distance(v, lca(u, v)) - k);\n    }\n  };\n} // namespace\
    \ matumoto"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/tree.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree.hpp
layout: document
redirect_from:
- /library/graph/tree.hpp
- /library/graph/tree.hpp.html
title: graph/tree.hpp
---
