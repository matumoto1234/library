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
    #include <stack>\n\nnamespace matumoto {\n  // s,t : 0-indexed.\n  // reachable\
    \ s -> t\n  template <class Graph>\n  bool reachable(const Graph &g, int s, int\
    \ t) {\n    const auto &graph = g.graph();\n\n    stack<int> st;\n    st.push(s);\n\
    \    vector<char> used(g.size(), 0);\n\n    while (not st.empty()) {\n      int\
    \ v = st.top();\n      st.pop();\n\n      used[v] = true;\n      if (v == t)\n\
    \        return true;\n\n      for (const auto &edge: graph[v]) {\n        const\
    \ int &to = edge.to();\n        if (used[to])\n          continue;\n\n       \
    \ st.push(to);\n      }\n    }\n\n    return false;\n  }\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/reachable.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/reachable.hpp
layout: document
redirect_from:
- /library/graph/reachable.hpp
- /library/graph/reachable.hpp.html
title: graph/reachable.hpp
---
