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
  bundledCode: "#line 2 \"tools/cppint.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/cppint.hpp\"\n\n#include\
    \ <boost/multiprecision/cpp_int.hpp>\n#include <cassert>\n#include <string>\n\n\
    namespace matumoto {\n  namespace cpp_int_helper {\n    namespace mp = boost::multiprecision;\n\
    \n    string to_string(mp::cpp_int a) {\n      string res = \"\";\n      if (a\
    \ < 0) {\n        a *= -1;\n        res += \"-\";\n      }\n\n      while (a)\
    \ {\n        res += static_cast<char>(a % 10 + '0');\n        a /= 10;\n     \
    \ }\n      return res;\n    }\n\n    mp::cpp_int gcd(mp::cpp_int a, mp::cpp_int\
    \ b) {\n      mp::cpp_int tmp;\n      while (b > 0) {\n        tmp = a;\n    \
    \    a = b;\n        b = tmp % b;\n      }\n      return a;\n    }\n\n    mp::cpp_int\
    \ lcm(mp::cpp_int a, mp::cpp_int b) {\n      return a * b / gcd(a, b);\n    }\n\
    \n    namespace power_helper {\n\n      mp::cpp_int extgcd(mp::cpp_int a, mp::cpp_int\
    \ b, mp::cpp_int &x, mp::cpp_int &y) {\n        if (b == 0) {\n          x = 1;\n\
    \          y = 0;\n          return a;\n        }\n        mp::cpp_int d = extgcd(b,\
    \ a % b, y, x);\n        y = y - (a / b) * x;\n        return d;\n      }\n\n\
    \    } // namespace power_helper\n\n    mp::cpp_int power(mp::cpp_int a, mp::cpp_int\
    \ e, mp::cpp_int p = -1) {\n      assert(p != 0);\n      assert(p >= -1);\n\n\
    \      if (e < 0) {\n        assert(p != -1 and gcd(a, p) == 1);\n        mp::cpp_int\
    \ x, y;\n        power_helper::extgcd(a, p, x, y);\n        a = (x % p + p) %\
    \ p;\n        e *= -1;\n      }\n\n      mp::cpp_int res = 1;\n      while (e\
    \ > 0) {\n        if (e & 1) {\n          res *= a;\n          if (p != -1)\n\
    \            res %= p;\n        }\n        a *= a;\n        if (p != -1)\n   \
    \       a %= p;\n        e >>= 1;\n      }\n      return res;\n    }\n\n  } //\
    \ namespace cpp_int_helper\n  using namespace cpp_int_helper;\n  using cint =\
    \ boost::multiprecision::cpp_int;\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <boost/multiprecision/cpp_int.hpp>\n\
    #include <cassert>\n#include <string>\n\nnamespace matumoto {\n  namespace cpp_int_helper\
    \ {\n    namespace mp = boost::multiprecision;\n\n    string to_string(mp::cpp_int\
    \ a) {\n      string res = \"\";\n      if (a < 0) {\n        a *= -1;\n     \
    \   res += \"-\";\n      }\n\n      while (a) {\n        res += static_cast<char>(a\
    \ % 10 + '0');\n        a /= 10;\n      }\n      return res;\n    }\n\n    mp::cpp_int\
    \ gcd(mp::cpp_int a, mp::cpp_int b) {\n      mp::cpp_int tmp;\n      while (b\
    \ > 0) {\n        tmp = a;\n        a = b;\n        b = tmp % b;\n      }\n  \
    \    return a;\n    }\n\n    mp::cpp_int lcm(mp::cpp_int a, mp::cpp_int b) {\n\
    \      return a * b / gcd(a, b);\n    }\n\n    namespace power_helper {\n\n  \
    \    mp::cpp_int extgcd(mp::cpp_int a, mp::cpp_int b, mp::cpp_int &x, mp::cpp_int\
    \ &y) {\n        if (b == 0) {\n          x = 1;\n          y = 0;\n         \
    \ return a;\n        }\n        mp::cpp_int d = extgcd(b, a % b, y, x);\n    \
    \    y = y - (a / b) * x;\n        return d;\n      }\n\n    } // namespace power_helper\n\
    \n    mp::cpp_int power(mp::cpp_int a, mp::cpp_int e, mp::cpp_int p = -1) {\n\
    \      assert(p != 0);\n      assert(p >= -1);\n\n      if (e < 0) {\n       \
    \ assert(p != -1 and gcd(a, p) == 1);\n        mp::cpp_int x, y;\n        power_helper::extgcd(a,\
    \ p, x, y);\n        a = (x % p + p) % p;\n        e *= -1;\n      }\n\n     \
    \ mp::cpp_int res = 1;\n      while (e > 0) {\n        if (e & 1) {\n        \
    \  res *= a;\n          if (p != -1)\n            res %= p;\n        }\n     \
    \   a *= a;\n        if (p != -1)\n          a %= p;\n        e >>= 1;\n     \
    \ }\n      return res;\n    }\n\n  } // namespace cpp_int_helper\n  using namespace\
    \ cpp_int_helper;\n  using cint = boost::multiprecision::cpp_int;\n} // namespace\
    \ matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/cppint.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/cppint.hpp
layout: document
redirect_from:
- /library/tools/cppint.hpp
- /library/tools/cppint.hpp.html
title: tools/cppint.hpp
---
