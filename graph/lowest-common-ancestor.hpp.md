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
    #include <stack>\n#include <tuple>\n\nnamespace matumoto {\n  class LowestCommonAncestor\
    \ {\n    UnWeightedGraph graph_;\n    int height_, root_;\n    vector<vector<int>>\
    \ doubling_parents_;\n    vector<int> depths_;\n\n  public:\n    LowestCommonAncestor(const\
    \ UnWeightedGraph &graph, int root = 0): graph_(graph), root_(root) {\n      int\
    \ n = graph_.size();\n\n      height_ = 1;\n      while ((1 << height_) <= n)\
    \ {\n        height_++;\n      }\n\n      doubling_parents_.assign(height_, vector<int>(n,\
    \ -1));\n      depths_.assign(n, 0);\n\n      vector<UnWeightedEdges> adj_list\
    \ = graph_.graph();\n      // <v, par, dep>\n      stack<tuple<int, int, int>>\
    \ st;\n      st.emplace(root, -1, 0);\n      while (not st.empty()) {\n      \
    \  auto [v, par, dep] = st.top();\n        st.pop();\n\n        doubling_parents_.at(0).at(v)\
    \ = par;\n        depths_.at(v) = dep;\n        for (UnWeightedEdge e: adj_list.at(v))\
    \ {\n          int to = e.to();\n          if (to != par) {\n            st.emplace(to,\
    \ v, dep + 1);\n          }\n        }\n      }\n\n      for (int k = 0; k + 1\
    \ < height_; k++) {\n        for (int v = 0; v < n; v++) {\n          if (doubling_parents_.at(k).at(v)\
    \ != -1) {\n            int kth_pow_par = doubling_parents_.at(k).at(v);\n   \
    \         doubling_parents_.at(k + 1).at(v) = doubling_parents_.at(k).at(kth_pow_par);\n\
    \          }\n        }\n      }\n    }\n\n    int query(int u, int v) {\n   \
    \   if (depths_.at(u) > depths_.at(v))\n        swap(u, v);\n      for (int k\
    \ = 0; k < height_; k++)\n        if ((depths_.at(v) - depths_.at(u)) >> k & 1)\n\
    \          v = doubling_parents_.at(k).at(v);\n\n      if (u == v)\n        return\
    \ u;\n\n      for (int k = height_ - 1; k >= 0; k--)\n        if (doubling_parents_.at(k).at(u)\
    \ != doubling_parents_.at(k).at(v))\n          u = doubling_parents_.at(k).at(u),\
    \ v = doubling_parents_.at(k).at(v);\n\n      return doubling_parents_.at(0).at(u);\n\
    \    }\n\n    int distance(int u, int v) {\n      return depths_.at(u) + depths_.at(v)\
    \ - depths_[query(u, v)] * 2;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowest-common-ancestor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowest-common-ancestor.hpp
layout: document
redirect_from:
- /library/graph/lowest-common-ancestor.hpp
- /library/graph/lowest-common-ancestor.hpp.html
title: graph/lowest-common-ancestor.hpp
---
