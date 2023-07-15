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
  code: "#pragma once\n\n#include \"./base.hpp\"\n#include \"./graph-type.hpp\"\n\
    #include \"./reverse-edges.hpp\"\n\nnamespace matumoto {\n  template <typename\
    \ Graph>\n  class StronglyConnectedComponent {\n    Graph scc_graph_;\n    vector<vector<int>>\
    \ scc_;\n    vector<bool> used_;\n    vector<int> post_order_, group_;\n\n  public:\n\
    \    StronglyConnectedComponent(const Graph &graph) {\n      int n = graph.size();\n\
    \n      // get post order\n      used_.assign(n, false);\n      auto adj_list\
    \ = graph.graph();\n\n      for (int i = 0; i < n; i++) {\n        if (used_[i])\n\
    \          continue;\n\n        dfs(adj_list, i);\n      }\n\n      int scc_cnt\
    \ = 0;\n      group_.assign(n, 0);\n      used_.assign(n, false);\n\n      Graph\
    \ rgraph = reverse_edges(graph);\n      auto radj_list = rgraph.graph();\n\n \
    \     // scc grouping\n      for (int i = n - 1; i >= 0; i--) {\n        int idx\
    \ = post_order_[i];\n        if (used_[idx])\n          continue;\n\n        rdfs(radj_list,\
    \ idx, scc_cnt);\n        scc_cnt++;\n      }\n\n      scc_.assign(scc_cnt, vector<int>(0));\n\
    \      scc_graph_ = Graph(scc_cnt);\n\n      for (int i = 0; i < n; i++) {\n \
    \       // build scc\n        scc_[group_[i]].push_back(i);\n\n        // build\
    \ scc graph\n        for (auto e: adj_list[i]) {\n          bool is_same_scc =\
    \ group_[i] == group_[e.to()];\n          if (is_same_scc)\n            continue;\n\
    \n          if constexpr (is_same_v<Graph, UnWeightedGraph>) {\n            scc_graph_.add_edge(UnWeightedEdge(group_[i],\
    \ group_[e.to()]));\n          } else {\n            scc_graph_.add_edge(WeightedEdge(group_[i],\
    \ group_[e.to()], e.cost()));\n          }\n        }\n      }\n    }\n\n    vector<int>\
    \ group() const {\n      return group_;\n    }\n\n    vector<vector<int>> scc()\
    \ const {\n      return scc_;\n    }\n\n    Graph scc_graph() const {\n      return\
    \ scc_graph_;\n    }\n\n  private:\n    template <typename Edges>\n    void dfs(const\
    \ vector<Edges> &adj_list, int idx) {\n      used_[idx] = true;\n      for (const\
    \ auto &e: adj_list[idx]) {\n        const int &to = e.to();\n        if (used_[to])\n\
    \          continue;\n\n        dfs(adj_list, to);\n      }\n      post_order_.emplace_back(idx);\n\
    \    }\n\n    template <typename Edges>\n    void rdfs(const vector<Edges> &adj_list,\
    \ int idx, int group_id) {\n      used_[idx] = true;\n      group_[idx] = group_id;\n\
    \      for (const auto &e: adj_list[idx]) {\n        const int &to = e.to();\n\
    \        if (used_[to])\n          continue;\n\n        rdfs(adj_list, to, group_id);\n\
    \      }\n    }\n  };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly-connected-component.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/strongly-connected-component.hpp
layout: document
redirect_from:
- /library/graph/strongly-connected-component.hpp
- /library/graph/strongly-connected-component.hpp.html
title: graph/strongly-connected-component.hpp
---
