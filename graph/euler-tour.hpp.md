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
    namespace matumoto {\n  class EulerTour {\n    vector<int> in_time_, out_time_,\
    \ depths_, parents_, edge_table_;\n\n    void dfs(const vector<UnWeightedEdges>\
    \ &adj_list, int v, int &time, int d) {\n      in_time_.at(v) = time;\n      depths_.at(v)\
    \ = d;\n      edge_table_.at(time) = v;\n      time++;\n\n      for (auto e: adj_list.at(v))\
    \ {\n        int to = e.to();\n\n        if (in_time_.at(to) != -1)\n        \
    \  continue;\n\n        parents_.at(to) = v;\n        dfs(adj_list, to, time,\
    \ d + 1);\n      }\n      out_time_.at(v) = time;\n      edge_table_.at(time)\
    \ = -v;\n      time++;\n    }\n\n  public:\n    EulerTour(const UnWeightedGraph\
    \ &graph, int root) {\n      int n = graph.size();\n      in_time_.assign(n, -1);\n\
    \      out_time_.assign(n, -1);\n      depths_.assign(n, -1);\n      parents_.assign(n,\
    \ -1);\n      edge_table_.assign(2 * n, -1);\n\n      vector<UnWeightedEdges>\
    \ adj_list = graph.graph();\n\n      int time = 0;\n      dfs(adj_list, root,\
    \ time, 0);\n    }\n\n    int in(int v) {\n      return in_time_.at(v);\n    }\n\
    \    int out(int v) {\n      return out_time_.at(v);\n    }\n    int depth(int\
    \ v) {\n      return depths_.at(v);\n    }\n    int parent(int v) {\n      return\
    \ parents_.at(v);\n    }\n    vector<int> edge_table() {\n      return edge_table_;\n\
    \    }\n\n    // edge_table: [first, second], vertex_table:[first, second)\n \
    \   pair<int, int> subtree(int v) {\n      return pair(in_time_.at(v), out_time_.at(v));\n\
    \    }\n\n    vector<int> vertex_table() {\n      vector<int> res = edge_table_;\n\
    \      for (auto &v: res) {\n        if (v < 0)\n          v = parents_.at(-v);\n\
    \      }\n      // \u534A\u958B\u533A\u9593->\u9589\u533A\u9593\u306E\u8AA4\u5DEE\
    \n      res.pop_back();\n      return res;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/euler-tour.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/euler-tour.hpp
layout: document
redirect_from:
- /library/graph/euler-tour.hpp
- /library/graph/euler-tour.hpp.html
title: graph/euler-tour.hpp
---
