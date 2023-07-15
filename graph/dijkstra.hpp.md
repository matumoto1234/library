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
    #include <algorithm>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    \n\nnamespace matumoto {\n  template <typename Cost>\n  struct Dijkstra {\n  \
    \  using Edge = WeightedEdge<Cost>;\n    vector<Cost> ds;\n    vector<int> bs;\n\
    \n    static constexpr Cost inf() {\n      return numeric_limits<Cost>::max()\
    \ / 2;\n    }\n\n    Dijkstra(vector<pair<Cost, int>> g, int start): ds(g.size(),\
    \ inf()), bs(g.size(), -1) {\n      assert(0 <= start and start < g.size());\n\
    \      auto G = g.graph();\n      priority_queue<Edge, vector<Edge>, greater<Edge>>\
    \ Q;\n      ds[start] = 0;\n      Q.emplace(start, ds[start]);\n\n      while\
    \ (!Q.empty()) {\n        Edge p = Q.top();\n        int v = p.to();\n       \
    \ Q.pop();\n\n        if (ds[v] < p.cost())\n          continue;\n\n        for\
    \ (Edge e: G[v]) {\n          int to = e.to();\n          Cost cost = e.cost();\n\
    \          if (ds[to] > ds[v] + cost) {\n            ds[to] = ds[v] + cost;\n\
    \            bs[to] = v;\n            Q.emplace(to, ds[to]);\n          }\n  \
    \      }\n      }\n    }\n\n    Cost operator[](int k) {\n      return ds.at(k);\n\
    \    }\n\n    vector<int> restore(int to) {\n      vector<int> res;\n      if\
    \ (bs[to] == -1) {\n        res.emplace_back(to);\n        return res;\n     \
    \ }\n      while (to != -1) {\n        res.emplace_back(to);\n        to = bs[to];\n\
    \      }\n      reverse(res.begin(), res.end());\n      return res;\n    }\n \
    \ };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
