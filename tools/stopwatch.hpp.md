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
  bundledCode: "#line 2 \"tools/stopwatch.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/stopwatch.hpp\"\
    \n\n#include <chrono>\n\nnamespace matumoto {\n  struct Stopwatch {\n    chrono::high_resolution_clock::time_point\
    \ start;\n\n    Stopwatch() {\n      restart();\n    }\n\n    void restart() {\n\
    \      start = chrono::high_resolution_clock::now();\n    }\n\n    chrono::milliseconds::rep\
    \ elapsed() {\n      auto end = chrono::high_resolution_clock::now();\n      return\
    \ chrono::duration_cast<chrono::milliseconds>(end - start).count();\n    }\n \
    \ };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <chrono>\n\nnamespace\
    \ matumoto {\n  struct Stopwatch {\n    chrono::high_resolution_clock::time_point\
    \ start;\n\n    Stopwatch() {\n      restart();\n    }\n\n    void restart() {\n\
    \      start = chrono::high_resolution_clock::now();\n    }\n\n    chrono::milliseconds::rep\
    \ elapsed() {\n      auto end = chrono::high_resolution_clock::now();\n      return\
    \ chrono::duration_cast<chrono::milliseconds>(end - start).count();\n    }\n \
    \ };\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/stopwatch.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/stopwatch.hpp
layout: document
redirect_from:
- /library/tools/stopwatch.hpp
- /library/tools/stopwatch.hpp.html
title: tools/stopwatch.hpp
---
