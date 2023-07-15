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
    #include <algorithm>\n\nnamespace matumoto {\n  class LowLink {\n    UnWeightedGraph\
    \ graph_;\n    vector<UnWeightedEdges> adj_list_;\n    vector<int> order_, lowlink_;\n\
    \    vector<int> articulations_;\n    vector<UnWeightedEdge> bridges_;\n\n  public:\n\
    \    LowLink(const UnWeightedGraph &graph): graph_(graph) {\n      adj_list_ =\
    \ graph_.graph();\n\n      int n = graph_.size();\n      order_.assign(n, -1);\n\
    \      lowlink_.assign(n, 0);\n\n      int k = 0;\n      for (int i = 0; i < n;\
    \ i++) {\n        if (order_[i] == -1)\n          dfs(i, k, -1);\n      }\n  \
    \    sort(articulations_.begin(), articulations_.end());\n      sort(bridges_.begin(),\
    \ bridges_.end());\n    }\n\n    vector<int> articulations() const {\n      return\
    \ articulations_;\n    }\n\n    vector<UnWeightedEdge> bridges() const {\n   \
    \   return bridges_;\n    }\n\n  private:\n    void dfs(int idx, int &k, int parent)\
    \ {\n      order_[idx] = lowlink_[idx] = k;\n      k++;\n\n      bool is_articulation\
    \ = false;\n      int child_cnt = 0;\n\n      for (auto edge: adj_list_[idx])\
    \ {\n        int to = edge.to();\n\n        if (order_[to] == -1) {\n        \
    \  child_cnt++;\n          dfs(to, k, idx);\n\n          lowlink_[idx] = min(lowlink_[idx],\
    \ lowlink_[to]);\n          if (parent != -1 and order_[idx] <= lowlink_[to])\n\
    \            is_articulation = true;\n          if (order_[idx] < lowlink_[to])\n\
    \            bridges_.emplace_back(min(idx, to), max(idx, to));\n        } else\
    \ if (to != parent) {\n          lowlink_[idx] = min(lowlink_[idx], order_[to]);\n\
    \        }\n      }\n\n      if (parent == -1 and child_cnt >= 2)\n        is_articulation\
    \ = true;\n      if (is_articulation)\n        articulations_.emplace_back(idx);\n\
    \    }\n  };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/low-link.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/low-link.hpp
layout: document
redirect_from:
- /library/graph/low-link.hpp
- /library/graph/low-link.hpp.html
title: graph/low-link.hpp
---
