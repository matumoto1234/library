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
  bundledCode: "#line 2 \"tools/range.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/range.hpp\"\n\n#include\
    \ <iterator>\n#include <type_traits>\n#include <vector>\n\nnamespace matumoto\
    \ {\n  // begin,end\u3092\u6301\u3064\u69CB\u9020\u4F53\n  template <typename\
    \ Iterator>\n  class Range {\n    const Iterator begin_;\n    const Iterator end_;\n\
    \n  public:\n    Range(Iterator &&b, Iterator &&e) noexcept: begin_(forward<Iterator>(b)),\
    \ end_(forward<Iterator>(e)) {}\n\n    Iterator begin() const noexcept {\n   \
    \   return begin_;\n    }\n\n    Iterator end() const noexcept {\n      return\
    \ end_;\n    }\n  }; // class Range\n\n  template <typename Iterator>\n  Range<Iterator>\
    \ make_range(Iterator &&begin, Iterator &&end) noexcept {\n    return Range<Iterator>{\
    \ forward<Iterator>(begin), forward<Iterator>(end) };\n  }\n\n  // initiaizer_list\u7528\
    \n  template <typename T>\n  decltype(auto) make_reversed_range(const initializer_list<T>\
    \ &init_list) noexcept {\n    return make_range(rbegin(init_list), rend(init_list));\n\
    \  }\n\n  // rbegin,rend\u3092\u6301\u3063\u3066\u3044\u308B\u65B9\n  template\
    \ <typename T>\n  decltype(auto) make_reversed_range(T &&container) noexcept {\n\
    \    return make_range(rbegin(container), rend(container));\n  }\n} // namespace\
    \ matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <iterator>\n#include\
    \ <type_traits>\n#include <vector>\n\nnamespace matumoto {\n  // begin,end\u3092\
    \u6301\u3064\u69CB\u9020\u4F53\n  template <typename Iterator>\n  class Range\
    \ {\n    const Iterator begin_;\n    const Iterator end_;\n\n  public:\n    Range(Iterator\
    \ &&b, Iterator &&e) noexcept: begin_(forward<Iterator>(b)), end_(forward<Iterator>(e))\
    \ {}\n\n    Iterator begin() const noexcept {\n      return begin_;\n    }\n\n\
    \    Iterator end() const noexcept {\n      return end_;\n    }\n  }; // class\
    \ Range\n\n  template <typename Iterator>\n  Range<Iterator> make_range(Iterator\
    \ &&begin, Iterator &&end) noexcept {\n    return Range<Iterator>{ forward<Iterator>(begin),\
    \ forward<Iterator>(end) };\n  }\n\n  // initiaizer_list\u7528\n  template <typename\
    \ T>\n  decltype(auto) make_reversed_range(const initializer_list<T> &init_list)\
    \ noexcept {\n    return make_range(rbegin(init_list), rend(init_list));\n  }\n\
    \n  // rbegin,rend\u3092\u6301\u3063\u3066\u3044\u308B\u65B9\n  template <typename\
    \ T>\n  decltype(auto) make_reversed_range(T &&container) noexcept {\n    return\
    \ make_range(rbegin(container), rend(container));\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/range.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/range.hpp
layout: document
redirect_from:
- /library/tools/range.hpp
- /library/tools/range.hpp.html
title: tools/range.hpp
---
