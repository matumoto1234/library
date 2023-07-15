---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/bellman-ford.hpp
    title: graph/bellman-ford.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/grl/1_B.test.cpp
    title: test/aoj/grl/1_B.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc/abc061/D.test.cpp
    title: test/atcoder/abc/abc061/D.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc/abc137/E.test.cpp
    title: test/atcoder/abc/abc137/E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\nnamespace matumoto {\n  using namespace\
    \ std;\n}\n#line 2 \"graph/adjacency-list-to-edges.hpp\"\n\n#include <utility>\n\
    #include <vector>\n\nnamespace matumoto {\n  vector<pair<int, int>> adjacency_list_to_edges(const\
    \ vector<vector<int>> &adj_list) {\n    vector<pair<int, int>> edges;\n    for\
    \ (int v = 0; v < (int)adj_list.size(); v++) {\n      for (const auto &to: adj_list[v])\
    \ {\n        edges.emplace_back(v, to);\n      }\n    }\n    return edges;\n \
    \ }\n\n  template <typename Cost>\n  vector<tuple<int, int, Cost>> adjacency_list_to_edges(const\
    \ vector<vector<pair<Cost, int>>> &adj_list) {\n    vector<tuple<int, int, Cost>>\
    \ edges;\n    for (int v = 0; v < (int)adj_list.size(); v++) {\n      for (const\
    \ auto &[cost, to]: adj_list[v]) {\n        edges.emplace_back(v, to, cost);\n\
    \      }\n    }\n    return edges;\n  }\n} // namespace matumoto\n"
  code: "#include \"base.hpp\"\n\n#include <utility>\n#include <vector>\n\nnamespace\
    \ matumoto {\n  vector<pair<int, int>> adjacency_list_to_edges(const vector<vector<int>>\
    \ &adj_list) {\n    vector<pair<int, int>> edges;\n    for (int v = 0; v < (int)adj_list.size();\
    \ v++) {\n      for (const auto &to: adj_list[v]) {\n        edges.emplace_back(v,\
    \ to);\n      }\n    }\n    return edges;\n  }\n\n  template <typename Cost>\n\
    \  vector<tuple<int, int, Cost>> adjacency_list_to_edges(const vector<vector<pair<Cost,\
    \ int>>> &adj_list) {\n    vector<tuple<int, int, Cost>> edges;\n    for (int\
    \ v = 0; v < (int)adj_list.size(); v++) {\n      for (const auto &[cost, to]:\
    \ adj_list[v]) {\n        edges.emplace_back(v, to, cost);\n      }\n    }\n \
    \   return edges;\n  }\n} // namespace matumoto\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/adjacency-list-to-edges.hpp
  requiredBy:
  - graph/bellman-ford.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc/abc061/D.test.cpp
  - test/atcoder/abc/abc137/E.test.cpp
  - test/aoj/grl/1_B.test.cpp
documentation_of: graph/adjacency-list-to-edges.hpp
layout: document
redirect_from:
- /library/graph/adjacency-list-to-edges.hpp
- /library/graph/adjacency-list-to-edges.hpp.html
title: graph/adjacency-list-to-edges.hpp
---
