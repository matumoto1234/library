---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph-type.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./graph-type.hpp\"\n\n\
    #include <limits>\n\nnamespace matumoto {\n  template <typename Cost>\n  class\
    \ WarshallFloyd {\n    vector<pair<Cost, int>> graph_;\n    vector<vector<Cost>>\
    \ distances_;\n    vector<vector<int>> nexts_;\n    bool has_neg_cycle_;\n\n \
    \ public:\n    WarshallFloyd(const vector<pair<Cost, int>> &graph): graph_(graph),\
    \ has_neg_cycle_(false) {\n      int n = graph_.size();\n      distances_.assign(n,\
    \ vector<Cost>(n, inf()));\n      for (int i = 0; i < n; i++) {\n        distances_[i][i]\
    \ = 0;\n      }\n\n      nexts_.assign(n, vector<int>(n, 0));\n      for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n          nexts_[i][j]\
    \ = j;\n        }\n      }\n\n      auto edges = graph_.edges();\n      for (auto\
    \ edge: edges) {\n        int from = edge.from();\n        int to = edge.to();\n\
    \        Cost cost = edge.cost();\n\n        // if there are multiple edges, use\
    \ the minimum cost edge.\n        distances_.at(from).at(to) = min(distances_.at(from).at(to),\
    \ cost);\n      }\n\n      for (int k = 0; k < n; k++) {\n        for (int i =\
    \ 0; i < n; i++) {\n          for (int j = 0; j < n; j++) {\n            if (distances_[i][k]\
    \ == inf() or distances_[k][j] == inf()) {\n              continue;\n        \
    \    }\n\n            if (distances_[i][j] > distances_[i][k] + distances_[k][j])\
    \ {\n              distances_[i][j] = distances_[i][k] + distances_[k][j];\n \
    \             nexts_[i][j] = nexts_[i][k];\n            }\n          }\n     \
    \   }\n      }\n\n      for (int i = 0; i < n; i++) {\n        if (distances_[i][i]\
    \ < 0) {\n          has_neg_cycle_ = true;\n          break;\n        }\n    \
    \  }\n    }\n\n    static constexpr Cost inf() {\n      return numeric_limits<Cost>::max()\
    \ / 2;\n    }\n\n    vector<Cost> &operator[](int k) {\n      return distances_.at(k);\n\
    \    }\n\n    bool has_negative_cycle() const {\n      return has_neg_cycle_;\n\
    \    }\n\n    vector<int> restore(int s, int g) {\n      vector<int> path;\n \
    \     for (int v = s; v != g; v = nexts_.at(v).at(g)) {\n        path.emplace_back(v);\n\
    \      }\n      path.emplace_back(g);\n      return path;\n    }\n  };\n} // namespace\
    \ matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/warshall-floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall-floyd.hpp
- /library/graph/warshall-floyd.hpp.html
title: graph/warshall-floyd.hpp
---
