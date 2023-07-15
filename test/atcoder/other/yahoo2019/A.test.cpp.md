---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  - icon: ':heavy_check_mark:'
    path: math/ceil-div.hpp
    title: math/ceil-div.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/2019yahoo_qual/tasks/2019yahoo_qual_a
    links:
    - https://atcoder.jp/contests/2019yahoo_qual/tasks/2019yahoo_qual_a
  bundledCode: "#line 1 \"test/atcoder/other/yahoo2019/A.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/2019yahoo_qual/tasks/2019yahoo_qual_a\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"math/ceil-div.hpp\"\n\n#line\
    \ 2 \"math/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n  using\
    \ ll = long long;\n} // namespace matumoto\n#line 4 \"math/ceil-div.hpp\"\n\n\
    #line 6 \"math/ceil-div.hpp\"\n\nnamespace matumoto {\n  constexpr ll ceil_div(ll\
    \ n, ll d) {\n    assert(d != 0);\n    return n / d + (((n ^ d) >= 0) and (n %\
    \ d));\n  }\n} // namespace matumoto\n#line 6 \"test/atcoder/other/yahoo2019/A.test.cpp\"\
    \nusing namespace matumoto;\n\nint main() {\n  int n, k;\n  cin >> n >> k;\n\n\
    \  cout << (ceil_div(n, 2) >= k ? \"YES\" : \"NO\") << endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/2019yahoo_qual/tasks/2019yahoo_qual_a\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/ceil-div.hpp\"\
    \nusing namespace matumoto;\n\nint main() {\n  int n, k;\n  cin >> n >> k;\n\n\
    \  cout << (ceil_div(n, 2) >= k ? \"YES\" : \"NO\") << endl;\n}"
  dependsOn:
  - math/ceil-div.hpp
  - math/base.hpp
  isVerificationFile: true
  path: test/atcoder/other/yahoo2019/A.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/other/yahoo2019/A.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/other/yahoo2019/A.test.cpp
- /verify/test/atcoder/other/yahoo2019/A.test.cpp.html
title: test/atcoder/other/yahoo2019/A.test.cpp
---
