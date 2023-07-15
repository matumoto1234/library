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
  bundledCode: "#line 2 \"tools/debug.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/debug.hpp\"\n\n#include\
    \ <iostream>\n#include <stack>\n#include <string>\n\nnamespace matumoto {\n#define\
    \ debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)\n\n  int find_comma_not_bracketed(string_view\
    \ s) {\n    stack<char> bs;\n    string lbs = \"({[\", rbs = \")}]\";\n    for\
    \ (size_t i = 0; i < s.size(); i++) {\n      if (lbs.find(s[i]) != string::npos)\n\
    \        bs.push(s[i]);\n      if (rbs.find(s[i]) != string::npos and !bs.empty())\n\
    \        bs.pop();\n      if (s[i] == ',' and bs.empty())\n        return i;\n\
    \    }\n    return s.size();\n  }\n\n  template <typename T, typename... Ts>\n\
    \  void debug_function(string_view name, const T &a, Ts &&...rest) {\n    int\
    \ end = find_comma_not_bracketed(name);\n    cerr << name.substr(0, end) << \"\
    :\" << a;\n    if constexpr (sizeof...(rest) == 0) {\n      cerr << '\\n';\n \
    \   } else {\n      cerr << ' ';\n      debug_function(name.substr(name.find_first_not_of('\
    \ ', end + 1)), forward<Ts>(rest)...);\n    }\n  }\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <iostream>\n#include\
    \ <stack>\n#include <string>\n\nnamespace matumoto {\n#define debug(...) debug_function(#__VA_ARGS__,\
    \ __VA_ARGS__)\n\n  int find_comma_not_bracketed(string_view s) {\n    stack<char>\
    \ bs;\n    string lbs = \"({[\", rbs = \")}]\";\n    for (size_t i = 0; i < s.size();\
    \ i++) {\n      if (lbs.find(s[i]) != string::npos)\n        bs.push(s[i]);\n\
    \      if (rbs.find(s[i]) != string::npos and !bs.empty())\n        bs.pop();\n\
    \      if (s[i] == ',' and bs.empty())\n        return i;\n    }\n    return s.size();\n\
    \  }\n\n  template <typename T, typename... Ts>\n  void debug_function(string_view\
    \ name, const T &a, Ts &&...rest) {\n    int end = find_comma_not_bracketed(name);\n\
    \    cerr << name.substr(0, end) << \":\" << a;\n    if constexpr (sizeof...(rest)\
    \ == 0) {\n      cerr << '\\n';\n    } else {\n      cerr << ' ';\n      debug_function(name.substr(name.find_first_not_of('\
    \ ', end + 1)), forward<Ts>(rest)...);\n    }\n  }\n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/debug.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/debug.hpp
layout: document
redirect_from:
- /library/tools/debug.hpp
- /library/tools/debug.hpp.html
title: tools/debug.hpp
---
