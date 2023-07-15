---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  - icon: ':warning:'
    path: tools/has-iterator.hpp
    title: tools/has-iterator.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/contains.hpp
    title: tools/contains.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/has-find.hpp\"\n\n#line 2 \"tools/has-iterator.hpp\"\
    \n\n#line 2 \"tools/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n\
    }\n#line 4 \"tools/has-iterator.hpp\"\n\n#include <type_traits>\n\nnamespace matumoto\
    \ {\n  template <typename T>\n  class HasIterator {\n    template <typename Container>\n\
    \    static true_type check(typename Container::iterator *);\n\n    template <typename\
    \ Container>\n    static false_type check(...);\n\n  public:\n    static const\
    \ bool value = decltype(check<T>(0))::value;\n  };\n\n  template <typename T>\n\
    \  using has_iterator_t = enable_if_t<HasIterator<T>::value, typename T::iterator>;\n\
    } // namespace matumoto\n#line 4 \"tools/has-find.hpp\"\n\n#include <cstddef>\n\
    \nnamespace matumoto {\n  template <typename Container, typename T>\n  class HasFind\
    \ {\n    static false_type check(...);\n\n    template <typename C, enable_if_t<(static_cast<has_iterator_t<C>\
    \ (C::*)(const T &)>(&C::find), true), nullptr_t> = nullptr>\n    static true_type\
    \ check(C *);\n\n    static Container *container;\n\n  public:\n    static constexpr\
    \ bool value = decltype(check(container))::value;\n  };\n\n  template <typename\
    \ Container, typename T>\n  static constexpr bool has_find_v = HasFind<Container,\
    \ T>::value;\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./has-iterator.hpp\"\n\n#include <cstddef>\n\n\
    namespace matumoto {\n  template <typename Container, typename T>\n  class HasFind\
    \ {\n    static false_type check(...);\n\n    template <typename C, enable_if_t<(static_cast<has_iterator_t<C>\
    \ (C::*)(const T &)>(&C::find), true), nullptr_t> = nullptr>\n    static true_type\
    \ check(C *);\n\n    static Container *container;\n\n  public:\n    static constexpr\
    \ bool value = decltype(check(container))::value;\n  };\n\n  template <typename\
    \ Container, typename T>\n  static constexpr bool has_find_v = HasFind<Container,\
    \ T>::value;\n} // namespace matumoto"
  dependsOn:
  - tools/has-iterator.hpp
  - tools/base.hpp
  isVerificationFile: false
  path: tools/has-find.hpp
  requiredBy:
  - tools/contains.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/has-find.hpp
layout: document
redirect_from:
- /library/tools/has-find.hpp
- /library/tools/has-find.hpp.html
title: tools/has-find.hpp
---
