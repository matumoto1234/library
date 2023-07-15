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
  bundledCode: "#line 2 \"tools/function-measure.hpp\"\n\n#line 2 \"tools/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/function-measure.hpp\"\
    \n\n#include <chrono>\n#include <functional>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n\nnamespace matumoto {\n  struct FunctionMeasure {\n    chrono::system_clock::time_point\
    \ start, end;\n\n    template <auto f, typename... Args>\n    void measure(Args...\
    \ args) {\n      start = chrono::system_clock::now();\n\n      f(args...);\n\n\
    \      end = chrono::system_clock::now();\n    }\n\n    // bias:1000 -> [ms]\n\
    \    double time(double bias = 1000.0) {\n      return static_cast<double>(chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count() / bias);\n    }\n\n    void print(double bias = 1000.0) {\n\
    \      cout << fixed << setprecision(10);\n      cout << time(bias) << \"\\n\"\
    ;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <chrono>\n#include <functional>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n\nnamespace matumoto\
    \ {\n  struct FunctionMeasure {\n    chrono::system_clock::time_point start, end;\n\
    \n    template <auto f, typename... Args>\n    void measure(Args... args) {\n\
    \      start = chrono::system_clock::now();\n\n      f(args...);\n\n      end\
    \ = chrono::system_clock::now();\n    }\n\n    // bias:1000 -> [ms]\n    double\
    \ time(double bias = 1000.0) {\n      return static_cast<double>(chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count() / bias);\n    }\n\n    void print(double bias = 1000.0) {\n\
    \      cout << fixed << setprecision(10);\n      cout << time(bias) << \"\\n\"\
    ;\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/function-measure.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/function-measure.hpp
layout: document
redirect_from:
- /library/tools/function-measure.hpp
- /library/tools/function-measure.hpp.html
title: tools/function-measure.hpp
---
