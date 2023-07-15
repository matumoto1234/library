---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/sorted-index.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/sorted-index.hpp\"\
    \n\n#include <numeric>\n#include <vector>\n\nnamespace matumoto {\n  template\
    \ <typename Iterator>\n  vector<int> sorted_index(Iterator first, Iterator last)\
    \ {\n    using T = remove_reference_t<decltype(*first)>;\n    vector<T> a(first,\
    \ last);\n    vector<int> res(a.size());\n    iota(res.begin(), res.end(), 0);\n\
    \    stable_sort(res.begin(), res.end(), [&](int i, int j) {\n      return a[i]\
    \ < a[j];\n    });\n    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <numeric>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename Iterator>\n  vector<int> sorted_index(Iterator\
    \ first, Iterator last) {\n    using T = remove_reference_t<decltype(*first)>;\n\
    \    vector<T> a(first, last);\n    vector<int> res(a.size());\n    iota(res.begin(),\
    \ res.end(), 0);\n    stable_sort(res.begin(), res.end(), [&](int i, int j) {\n\
    \      return a[i] < a[j];\n    });\n    return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/sorted-index.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/sorted-index.hpp
layout: document
redirect_from:
- /library/tools/sorted-index.hpp
- /library/tools/sorted-index.hpp.html
title: tools/sorted-index.hpp
---
