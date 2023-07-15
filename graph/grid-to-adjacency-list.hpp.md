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
  bundledCode: "#line 2 \"graph/grid-to-adjacency-list.hpp\"\n\n#line 2 \"graph/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"graph/grid-to-adjacency-list.hpp\"\
    \n\n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  // grid graph\
    \ -> adjacency list\n  vector<vector<int>> grid_to_adjacency_list(const vector<string>\
    \ &s, const string &wall = \"#\") {\n    int h = s.size(), w = s[0].size();\n\
    \    constexpr int dy[] = { 1, 0, -1, 0 }, dx[] = { 0, 1, 0, -1 };\n    vector<vector<int>>\
    \ adj_list(h * w);\n\n    for (int i = 0; i < h; i++) {\n      for (int j = 0;\
    \ j < w; j++) {\n        int from = i * w + j;\n\n        for (int k = 0; k <\
    \ 4; k++) {\n          int ny = i + dy[k], nx = j + dx[k];\n\n          if (ny\
    \ < 0 or nx < 0 or ny >= h or nx >= w) {\n            continue;\n          }\n\
    \n          if (wall.find(s[ny][nx]) != string::npos) {\n            continue;\n\
    \          }\n\n          int to = ny * w + nx;\n          adj_list[from].push_back(to);\n\
    \        }\n      }\n    }\n    return adj_list;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  // grid graph -> adjacency list\n  vector<vector<int>>\
    \ grid_to_adjacency_list(const vector<string> &s, const string &wall = \"#\")\
    \ {\n    int h = s.size(), w = s[0].size();\n    constexpr int dy[] = { 1, 0,\
    \ -1, 0 }, dx[] = { 0, 1, 0, -1 };\n    vector<vector<int>> adj_list(h * w);\n\
    \n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n   \
    \     int from = i * w + j;\n\n        for (int k = 0; k < 4; k++) {\n       \
    \   int ny = i + dy[k], nx = j + dx[k];\n\n          if (ny < 0 or nx < 0 or ny\
    \ >= h or nx >= w) {\n            continue;\n          }\n\n          if (wall.find(s[ny][nx])\
    \ != string::npos) {\n            continue;\n          }\n\n          int to =\
    \ ny * w + nx;\n          adj_list[from].push_back(to);\n        }\n      }\n\
    \    }\n    return adj_list;\n  }\n} // namespace matumoto\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/grid-to-adjacency-list.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/grid-to-adjacency-list.hpp
layout: document
redirect_from:
- /library/graph/grid-to-adjacency-list.hpp
- /library/graph/grid-to-adjacency-list.hpp.html
title: graph/grid-to-adjacency-list.hpp
---
