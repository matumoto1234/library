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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/fenwick-tree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../data-structure/fenwick-tree.hpp\"\n#include\
    \ \"./base.hpp\"\n\n#include <vector>\n\nnamespace matumoto {\n  // verify:AOJ_ALDS1_5_D\n\
    \  template <typename T>\n  long long inversion(vector<T> vs) {\n    auto uni\
    \ = vs;\n    sort(uni.begin(), uni.end());\n    uni.erase(unique(uni.begin(),\
    \ uni.end()), uni.end());\n    for (T &v: vs) {\n      v = lower_bound(uni.begin(),\
    \ uni.end(), v) - uni.begin();\n    }\n\n    int n = vs.size();\n    data_structure::FenwickTree<long\
    \ long> ft(n + 1);\n    long long res = 0;\n    for (T v: vs) {\n      res +=\
    \ ft.sum(v + 1, n);\n      ft.add(v, 1);\n    }\n    return res;\n  }\n} // namespace\
    \ matumoto"
  dependsOn: []
  isVerificationFile: false
  path: tools/inversion.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/inversion.hpp
layout: document
redirect_from:
- /library/tools/inversion.hpp
- /library/tools/inversion.hpp.html
title: tools/inversion.hpp
---
