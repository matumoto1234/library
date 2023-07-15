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
  bundledCode: "#line 2 \"tools/counter.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/counter.hpp\"\n\n#include\
    \ <map>\n\nnamespace matumoto {\n  template <typename Iterator>\n  auto counter(Iterator\
    \ first, Iterator last) {\n    using T = remove_reference_t<decltype(*first)>;\n\
    \    map<T, int> res;\n    for (auto it = first; it != last; it++) {\n      T\
    \ value = *it;\n      res[value]++;\n    }\n    return res;\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <map>\n\nnamespace matumoto\
    \ {\n  template <typename Iterator>\n  auto counter(Iterator first, Iterator last)\
    \ {\n    using T = remove_reference_t<decltype(*first)>;\n    map<T, int> res;\n\
    \    for (auto it = first; it != last; it++) {\n      T value = *it;\n      res[value]++;\n\
    \    }\n    return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/counter.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/counter.hpp
layout: document
redirect_from:
- /library/tools/counter.hpp
- /library/tools/counter.hpp.html
title: tools/counter.hpp
---
