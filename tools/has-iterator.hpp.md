---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/contains.hpp
    title: tools/contains.hpp
  - icon: ':warning:'
    path: tools/has-find.hpp
    title: tools/has-find.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/has-iterator.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\
    \nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/has-iterator.hpp\"\
    \n\n#include <type_traits>\n\nnamespace matumoto {\n  template <typename T>\n\
    \  class HasIterator {\n    template <typename Container>\n    static true_type\
    \ check(typename Container::iterator *);\n\n    template <typename Container>\n\
    \    static false_type check(...);\n\n  public:\n    static const bool value =\
    \ decltype(check<T>(0))::value;\n  };\n\n  template <typename T>\n  using has_iterator_t\
    \ = enable_if_t<HasIterator<T>::value, typename T::iterator>;\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <type_traits>\n\nnamespace\
    \ matumoto {\n  template <typename T>\n  class HasIterator {\n    template <typename\
    \ Container>\n    static true_type check(typename Container::iterator *);\n\n\
    \    template <typename Container>\n    static false_type check(...);\n\n  public:\n\
    \    static const bool value = decltype(check<T>(0))::value;\n  };\n\n  template\
    \ <typename T>\n  using has_iterator_t = enable_if_t<HasIterator<T>::value, typename\
    \ T::iterator>;\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/has-iterator.hpp
  requiredBy:
  - tools/has-find.hpp
  - tools/contains.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/has-iterator.hpp
layout: document
redirect_from:
- /library/tools/has-iterator.hpp
- /library/tools/has-iterator.hpp.html
title: tools/has-iterator.hpp
---
