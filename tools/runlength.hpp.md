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
  bundledCode: "#line 2 \"tools/runlength.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/runlength.hpp\"\
    \n\n#include <type_traits>\n#include <vector>\n\nnamespace matumoto {\n  template\
    \ <typename Iterator>\n  auto runlength(Iterator first, Iterator last) {\n   \
    \ vector<pair<remove_reference_t<decltype(*first)>, int>> res;\n    for (auto\
    \ it = first; it != last; it++) {\n      if (res.empty() or res.back().first !=\
    \ *it)\n        res.emplace_back(*it, 0);\n      res.back().second++;\n    }\n\
    \    return res;\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  template <typename Iterator>\n  auto runlength(Iterator\
    \ first, Iterator last) {\n    vector<pair<remove_reference_t<decltype(*first)>,\
    \ int>> res;\n    for (auto it = first; it != last; it++) {\n      if (res.empty()\
    \ or res.back().first != *it)\n        res.emplace_back(*it, 0);\n      res.back().second++;\n\
    \    }\n    return res;\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/runlength.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/runlength.hpp
layout: document
redirect_from:
- /library/tools/runlength.hpp
- /library/tools/runlength.hpp.html
title: tools/runlength.hpp
---