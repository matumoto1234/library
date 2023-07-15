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
    #include <queue>\n\nnamespace matumoto {\n  // if graph is not DAG, return {}\n\
    \  vector<int> topological_sort(const UnWeightedGraph &graph) {\n    int n = graph.size();\n\
    \    vector<int> in_degree(n, 0);\n\n    auto edges = graph.edges();\n    for\
    \ (auto e: edges) {\n      in_degree[e.to()]++;\n    }\n\n    vector<UnWeightedEdges>\
    \ adj_list = graph.graph();\n\n    queue<int> q;\n    for (int i = 0; i < n; i++)\
    \ {\n      if (in_degree[i] == 0)\n        q.push(i);\n    }\n\n    vector<int>\
    \ sorted_indexes;\n    while (not q.empty()) {\n      int v = q.front();\n   \
    \   q.pop();\n\n      sorted_indexes.emplace_back(v);\n      for (auto e: adj_list[v])\
    \ {\n        int to = e.to();\n\n        in_degree[to]--;\n        if (in_degree[to]\
    \ == 0)\n          q.push(to);\n      }\n    }\n\n    bool has_cycle = int(sorted_indexes.size())\
    \ < n;\n    if (has_cycle) {\n      return {};\n    }\n    return sorted_indexes;\n\
    \  }\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/topological-sort.hpp
- /library/graph/topological-sort.hpp.html
title: graph/topological-sort.hpp
---
