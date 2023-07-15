---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/bellman-ford.hpp
    title: graph/bellman-ford.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/grl/1_B.test.cpp
    title: test/aoj/grl/1_B.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc/abc061/D.test.cpp
    title: test/atcoder/abc/abc061/D.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc/abc137/E.test.cpp
    title: test/atcoder/abc/abc137/E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/assert-msg.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/assert-msg.hpp\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <string>\n\nnamespace matumoto\
    \ {\n#define assert_msg(expr, msg) (static_cast<bool>(expr) ? void(0) : assert_fail(__FILE__,\
    \ __LINE__, #expr, msg))\n\n  namespace {\n    void assert_fail(const char *file,\
    \ int line, const char expr_str[], string msg) {\n      cerr << \"File: \" <<\
    \ file << \"\\n\"\n           << \"Line: \" << line << \"\\n\"\n           <<\
    \ \"Assertion '\" << expr_str << \"' failed.\\n\"\n           << \"Message: \"\
    \ << msg << \"\\n\";\n      abort();\n    }\n  } // namespace\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\n#include <cstdlib>\n#include <iostream>\n\
    #include <string>\n\nnamespace matumoto {\n#define assert_msg(expr, msg) (static_cast<bool>(expr)\
    \ ? void(0) : assert_fail(__FILE__, __LINE__, #expr, msg))\n\n  namespace {\n\
    \    void assert_fail(const char *file, int line, const char expr_str[], string\
    \ msg) {\n      cerr << \"File: \" << file << \"\\n\"\n           << \"Line: \"\
    \ << line << \"\\n\"\n           << \"Assertion '\" << expr_str << \"' failed.\\\
    n\"\n           << \"Message: \" << msg << \"\\n\";\n      abort();\n    }\n \
    \ } // namespace\n} // namespace matumoto\n"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/assert-msg.hpp
  requiredBy:
  - graph/bellman-ford.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc/abc061/D.test.cpp
  - test/atcoder/abc/abc137/E.test.cpp
  - test/aoj/grl/1_B.test.cpp
documentation_of: tools/assert-msg.hpp
layout: document
redirect_from:
- /library/tools/assert-msg.hpp
- /library/tools/assert-msg.hpp.html
title: tools/assert-msg.hpp
---
