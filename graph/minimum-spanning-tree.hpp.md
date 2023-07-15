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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/union-find.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../data-structure/union-find.hpp\"\n#include \"\
    ./base.hpp\"\n#include \"./graph-type.hpp\"\n\n#include <queue>\n\nnamespace matumoto\
    \ {\n\n  template <typename Cost>\n  struct MinimumSpanningTree {\n    vector<pair<Cost,\
    \ int>> graph_;\n    vector<pair<Cost, int>> mst_;\n    MinimumSpanningTree(const\
    \ vector<pair<Cost, int>> &graph): graph_(graph) {}\n\n    Cost kruskal() {\n\
    \      mst_ = vector<pair<Cost, int>>(graph_.size()); // init\n      if (graph_.size()\
    \ == 0) {\n        return Cost(0);\n      }\n\n      vector<WeightedEdge<Cost>>\
    \ edges = graph_.edges();\n      sort(edges.begin(), edges.end());\n\n      matumoto::UnionFind\
    \ uf(graph_.size());\n\n      Cost sum = 0;\n\n      for (auto edge: edges) {\n\
    \        int from = edge.from();\n        int to = edge.to();\n\n        if (uf.same(from,\
    \ to))\n          continue;\n\n        uf.merge(from, to);\n        sum += edge.cost();\n\
    \        mst_.add_edge(edge);\n      }\n\n      return sum;\n    }\n\n    Cost\
    \ prim() {\n      mst_ = vector<pair<Cost, int>>(graph_.size()); // init\n   \
    \   if (graph_.size() == 0) {\n        return Cost(0);\n      }\n\n      priority_queue<WeightedEdge<Cost>,\
    \ vector<WeightedEdge<Cost>>, greater<WeightedEdge<Cost>>> pq;\n      pq.emplace(/*from=*/0,\
    \ /*to=*/0, Cost(0));\n\n      vector<vector<WeightedEdge<Cost>>> adj_list = graph_.graph();\n\
    \      vector<bool> used(graph_.size(), false);\n\n      Cost sum = 0;\n\n   \
    \   while (not pq.empty()) {\n        auto e = pq.top();\n        pq.pop();\n\n\
    \        int v = e.to();\n\n        if (used[v])\n          continue;\n\n    \
    \    sum += e.cost();\n        used[v] = true;\n        mst_.add_edge(e);\n\n\
    \        for (auto edge: adj_list[v]) {\n          int to = edge.to();\n\n   \
    \       if (used[to])\n            continue;\n\n          pq.push(edge);\n   \
    \     }\n      }\n\n      return sum;\n    }\n  };\n\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum-spanning-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum-spanning-tree.hpp
layout: document
redirect_from:
- /library/graph/minimum-spanning-tree.hpp
- /library/graph/minimum-spanning-tree.hpp.html
title: graph/minimum-spanning-tree.hpp
---
