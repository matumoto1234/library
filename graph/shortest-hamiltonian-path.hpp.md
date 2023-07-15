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
  bundledCode: "#line 2 \"graph/shortest-hamiltonian-path.hpp\"\n\n#line 2 \"graph/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"graph/shortest-hamiltonian-path.hpp\"\
    \n\n#include <limits>\n#include <vector>\n\nnamespace matumoto {\n  // \u5168\u9802\
    \u70B9\u30921\u5EA6\u3060\u3051\u8A2A\u554F\u3057\u305F\u3068\u304D\u306E\u6700\
    \u77ED\u7D4C\u8DEF\u8DDD\u96E2\n  // build\u3067inf\u304C\u5E30\u3063\u3066\u304D\
    \u305F\u3089\u305D\u306E\u3088\u3046\u306A\u7D4C\u8DEF\u306F\u306A\u3044\n  template\
    \ <typename T>\n  struct ShortestHamiltonianPath {\n    struct edge {\n      int\
    \ to;\n      T cost;\n      edge(int to, T cost): to(to), cost(cost) {}\n    };\n\
    \n    int V;\n    vector<vector<edge>> G;\n    vector<vector<T>> dp;\n\n    ShortestHamiltonianPath(int\
    \ V_): V(V_), G(V_) {}\n\n    T inf() {\n      return numeric_limits<T>::max()\
    \ / 2;\n    }\n\n    void add_edge(int from, int to, T cost) {\n      G[from].emplace_back(to,\
    \ cost);\n    }\n\n    T build() {\n      T res = inf();\n      dp.assign(V, vector<T>(1\
    \ << V, -1));\n      for (int sv = 0; sv < V; sv++) {\n        res = min(res,\
    \ dfs(sv, 1 << sv));\n      }\n      return res;\n    }\n\n    // private method\n\
    \    T dfs(int v, int Set) {\n      T &res = dp[v][Set];\n      if (Set + 1 ==\
    \ 1 << V)\n        res = 0;\n      if (res != -1)\n        return res;\n     \
    \ res = inf();\n      for (auto [to, cost]: G[v]) {\n        int bit = 1 << to;\n\
    \        if (Set & bit)\n          continue;\n        res = min(res, dfs(to, Set\
    \ | bit) + cost);\n      }\n      return res;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <limits>\n#include <vector>\n\
    \nnamespace matumoto {\n  // \u5168\u9802\u70B9\u30921\u5EA6\u3060\u3051\u8A2A\
    \u554F\u3057\u305F\u3068\u304D\u306E\u6700\u77ED\u7D4C\u8DEF\u8DDD\u96E2\n  //\
    \ build\u3067inf\u304C\u5E30\u3063\u3066\u304D\u305F\u3089\u305D\u306E\u3088\u3046\
    \u306A\u7D4C\u8DEF\u306F\u306A\u3044\n  template <typename T>\n  struct ShortestHamiltonianPath\
    \ {\n    struct edge {\n      int to;\n      T cost;\n      edge(int to, T cost):\
    \ to(to), cost(cost) {}\n    };\n\n    int V;\n    vector<vector<edge>> G;\n \
    \   vector<vector<T>> dp;\n\n    ShortestHamiltonianPath(int V_): V(V_), G(V_)\
    \ {}\n\n    T inf() {\n      return numeric_limits<T>::max() / 2;\n    }\n\n \
    \   void add_edge(int from, int to, T cost) {\n      G[from].emplace_back(to,\
    \ cost);\n    }\n\n    T build() {\n      T res = inf();\n      dp.assign(V, vector<T>(1\
    \ << V, -1));\n      for (int sv = 0; sv < V; sv++) {\n        res = min(res,\
    \ dfs(sv, 1 << sv));\n      }\n      return res;\n    }\n\n    // private method\n\
    \    T dfs(int v, int Set) {\n      T &res = dp[v][Set];\n      if (Set + 1 ==\
    \ 1 << V)\n        res = 0;\n      if (res != -1)\n        return res;\n     \
    \ res = inf();\n      for (auto [to, cost]: G[v]) {\n        int bit = 1 << to;\n\
    \        if (Set & bit)\n          continue;\n        res = min(res, dfs(to, Set\
    \ | bit) + cost);\n      }\n      return res;\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest-hamiltonian-path.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest-hamiltonian-path.hpp
layout: document
redirect_from:
- /library/graph/shortest-hamiltonian-path.hpp
- /library/graph/shortest-hamiltonian-path.hpp.html
title: graph/shortest-hamiltonian-path.hpp
---
