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
  bundledCode: "#line 2 \"tools/fix-point.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\n\
    namespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/fix-point.hpp\"\
    \n\n#include <utility>\n\nnamespace matumoto {\n  template <typename F>\n  struct\
    \ FixPoint: F {\n    FixPoint(F &&f) noexcept: F{ forward<F>(f) } {}\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args &&...args) const {\n\
    \      return F::operator()(*this, forward<Args>(args)...);\n    }\n  };\n\n \
    \ template <typename F>\n  inline decltype(auto) make_fix_point(F &&f) {\n   \
    \ return FixPoint<F>{ forward<F>(f) };\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <utility>\n\nnamespace\
    \ matumoto {\n  template <typename F>\n  struct FixPoint: F {\n    FixPoint(F\
    \ &&f) noexcept: F{ forward<F>(f) } {}\n\n    template <typename... Args>\n  \
    \  decltype(auto) operator()(Args &&...args) const {\n      return F::operator()(*this,\
    \ forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  inline decltype(auto)\
    \ make_fix_point(F &&f) {\n    return FixPoint<F>{ forward<F>(f) };\n  }\n} //\
    \ namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/fix-point.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/fix-point.hpp
layout: document
redirect_from:
- /library/tools/fix-point.hpp
- /library/tools/fix-point.hpp.html
title: tools/fix-point.hpp
---
