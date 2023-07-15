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
  bundledCode: "#line 2 \"graph/grid-bfs.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"graph/grid-bfs.hpp\"\n\n#include\
    \ <queue>\n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  vector<vector<int>>\
    \ grid_bfs(vector<string> &s, char start, const string &wall = \"#\") {\n    constexpr\
    \ int dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };\n    int h = s.size(), w\
    \ = s[0].size();\n    vector<vector<int>> res(h, vector<int>(w, -1));\n    queue<pair<int,\
    \ int>> q;\n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++)\
    \ {\n        if (s[i][j] == start) {\n          q.emplace(i, j);\n          res[i][j]\
    \ = 0;\n        }\n      }\n    }\n    while (!q.empty()) {\n      auto p = q.front();\n\
    \      q.pop();\n      for (int i = 0; i < 4; i++) {\n        int ny = p.first\
    \ + dy[i], nx = p.second + dx[i];\n        if (ny < 0 or nx < 0 or ny >= h or\
    \ nx >= w)\n          continue;\n        if (res[ny][nx] != -1)\n          continue;\n\
    \        if (wall.find(s[ny][nx]) != string::npos)\n          continue;\n    \
    \    res[ny][nx] = res[p.first][p.second] + 1;\n        q.emplace(ny, nx);\n \
    \     }\n    }\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <queue>\n#include <string>\n\
    #include <vector>\n\nnamespace matumoto {\n  vector<vector<int>> grid_bfs(vector<string>\
    \ &s, char start, const string &wall = \"#\") {\n    constexpr int dy[] = { 0,\
    \ 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };\n    int h = s.size(), w = s[0].size();\n\
    \    vector<vector<int>> res(h, vector<int>(w, -1));\n    queue<pair<int, int>>\
    \ q;\n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n\
    \        if (s[i][j] == start) {\n          q.emplace(i, j);\n          res[i][j]\
    \ = 0;\n        }\n      }\n    }\n    while (!q.empty()) {\n      auto p = q.front();\n\
    \      q.pop();\n      for (int i = 0; i < 4; i++) {\n        int ny = p.first\
    \ + dy[i], nx = p.second + dx[i];\n        if (ny < 0 or nx < 0 or ny >= h or\
    \ nx >= w)\n          continue;\n        if (res[ny][nx] != -1)\n          continue;\n\
    \        if (wall.find(s[ny][nx]) != string::npos)\n          continue;\n    \
    \    res[ny][nx] = res[p.first][p.second] + 1;\n        q.emplace(ny, nx);\n \
    \     }\n    }\n    return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/grid-bfs.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/grid-bfs.hpp
layout: document
redirect_from:
- /library/graph/grid-bfs.hpp
- /library/graph/grid-bfs.hpp.html
title: graph/grid-bfs.hpp
---
