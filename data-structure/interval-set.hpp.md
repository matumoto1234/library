---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc/abc001/D.test.cpp
    title: test/atcoder/abc/abc001/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc/abc228/D.test.cpp
    title: test/atcoder/abc/abc228/D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "[l, r)\u306E\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"data-structure/interval-set.hpp\"\n\n#line 2 \"data-structure/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"data-structure/interval-set.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <numeric>\n#include <set>\n\
    #include <utility>\n#include <vector>\n\nnamespace matumoto {\n  // verify:ABC001_D\n\
    \  // verify:ABC228_D\n\n  /**\n   * @brief [l, r)\u306E\u533A\u9593\u3092\u7BA1\
    \u7406\u3059\u308B\n   *        2\u3064\u306E\u533A\u9593[l1, r1), [l2, r2)\u306F\
    \u91CD\u8907\u3001\u9023\u7D50\u3057\u3066\u3044\u306A\u3044\n   *        \u4EFB\
    \u610F\u306E\u6574\u6570x\u3092\u542B\u3080\u533A\u9593\u306E\u6570\u306F\u9AD8\
    \u30051\u3064\n   */\n  template <typename T = long long>\n  struct IntervalSet\
    \ {\n    set<pair<T, T>> s;\n\n    IntervalSet() {\n      s.emplace(-inf(), -inf()\
    \ + 1);\n      s.emplace(inf(), inf() + 1);\n    }\n\n    T inf() const {\n  \
    \    return numeric_limits<T>::max() / 2;\n    }\n\n    bool is_inf(const pair<T,\
    \ T> &p) const {\n      return p.first == inf() or p.second == inf() or p.first\
    \ == -inf() or p.second == -inf();\n    }\n\n    bool empty() const {\n      return\
    \ s.size() <= 2;\n    }\n\n    // contains { (l, r) | l <= x < r }\n    bool contains(T\
    \ x) const {\n      if (empty()) {\n        return false;\n      }\n\n      auto\
    \ [l, r] = *(this->find(x));\n      return l <= x and x < r;\n    }\n\n    //\
    \ find { (l, r) | l <= x < r }\n    typename set<pair<T, T>>::iterator find(int\
    \ x) const {\n      // 1\u4EE5\u4E0A\u306E\u6B63\u6574\u6570n\u306B\u3064\u3044\
    \u3066pair(x, x+n) < pair(x+1, x+2)\u304C\u6210\u308A\u7ACB\u3064\n      // \u307E\
    \u305F\u3001pair(x, x+n) < a < pair(x+1, x+2)\u306A\u308Ba\u306F\u5B58\u5728\u3057\
    \u306A\u3044\u306E\u3067\n      // contains(x)\u304C\u6210\u308A\u7ACB\u3064\u306A\
    \u3089\u3070lower_bound\u3092\u53D6\u3063\u305Fprev\u306Bx\u304C\u542B\u307E\u308C\
    \u3066\u3044\u308B\n      return prev(s.lower_bound(pair(x + 1, x + 2)));\n  \
    \  }\n\n    pair<typename set<pair<T, T>>::iterator, bool> insert(T x) {\n   \
    \   return insert(pair(x, x + 1));\n    }\n\n    // insert [l, r)\n    // \u3082\
    \u3057[l, r)\u306B\u91CD\u8907or\u9023\u7D9A\u3059\u308B\u533A\u9593\u304C\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u3070\u305D\u308C\u3089\u3092\u524A\u9664\u3059\
    \u308B\n    // \u8A08\u7B97\u91CF : \u306A\u3089\u3057\u5BFE\u6570\u6642\u9593\
    \n    // \u8FD4\u308A\u5024 : std::set::insert\u306B\u6E96\u62E0\n    pair<typename\
    \ set<pair<T, T>>::iterator, bool> insert(pair<T, T> p) {\n      assert(p.first\
    \ < p.second);\n\n      auto l_itr = find(p.first);\n      while (intersect(*l_itr,\
    \ p) or continuous(*l_itr, p)) {\n        p = extend_interval(*l_itr, p);\n  \
    \      s.erase(l_itr);\n        l_itr = find(p.first);\n      }\n\n      auto\
    \ r_itr = find(p.second);\n      while (intersect(*r_itr, p) or continuous(*r_itr,\
    \ p)) {\n        p = extend_interval(*r_itr, p);\n        s.erase(r_itr);\n  \
    \      r_itr = find(p.second);\n      }\n\n      return s.insert(p);\n    }\n\n\
    \    // erase { (l, r) | l <= x < r }\n    void erase_interval(T x) {\n      if\
    \ (not contains(x)) {\n        return;\n      }\n\n      auto it = find(x);\n\
    \      s.erase(it);\n    }\n\n    // { (l, r) | l <= x < r } => { (l, x), (x+1,\
    \ r) | l < x && x+1 < r}\n    void cut(T x) {\n      if (not contains(x)) {\n\
    \        return;\n      }\n\n      auto it = find(x);\n      auto [l, r] = *it;\n\
    \      s.erase(it);\n      if (l < x) {\n        s.emplace(l, x);\n      }\n \
    \     if (x + 1 < r) {\n        s.emplace(x + 1, r);\n      }\n    }\n\n    template\
    \ <typename T1>\n    friend ostream &operator<<(ostream &os, const IntervalSet<T1>\
    \ &rhs) {\n      os << \"{\";\n      bool is_first = true;\n      for (const pair<T,\
    \ T> &p: rhs.s) {\n        if (rhs.is_inf(p)) {\n          continue;\n       \
    \ }\n        if (not is_first) {\n          os << \", \";\n        }\n       \
    \ is_first = false;\n        os << \"[\" << p.first << \",\" << p.second << \"\
    )\";\n      }\n      os << \"}\";\n      return os;\n    }\n\n    pair<T, T> extend_interval(const\
    \ pair<T, T> &p1, const pair<T, T> &p2) const {\n      assert(intersect(p1, p2)\
    \ or continuous(p1, p2));\n\n      vector<T> a{ p1.first, p1.second, p2.first,\
    \ p2.second };\n      sort(a.begin(), a.end());\n      return { a.front(), a.back()\
    \ };\n    }\n\n    bool intersect(pair<T, T> p1, pair<T, T> p2) const {\n    \
    \  if (p1 > p2) {\n        swap(p1, p2);\n      }\n      const auto &[a, b] =\
    \ p1;\n      const auto &[c, d] = p2;\n      return (a <= c and c < b) or (c <=\
    \ a and a < d);\n    }\n\n    bool continuous(pair<T, T> p1, pair<T, T> p2) const\
    \ {\n      if (p1 > p2) {\n        swap(p1, p2);\n      }\n      return p1.second\
    \ == p2.first;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <numeric>\n#include <set>\n#include <utility>\n#include <vector>\n\n\
    namespace matumoto {\n  // verify:ABC001_D\n  // verify:ABC228_D\n\n  /**\n  \
    \ * @brief [l, r)\u306E\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n   *      \
    \  2\u3064\u306E\u533A\u9593[l1, r1), [l2, r2)\u306F\u91CD\u8907\u3001\u9023\u7D50\
    \u3057\u3066\u3044\u306A\u3044\n   *        \u4EFB\u610F\u306E\u6574\u6570x\u3092\
    \u542B\u3080\u533A\u9593\u306E\u6570\u306F\u9AD8\u30051\u3064\n   */\n  template\
    \ <typename T = long long>\n  struct IntervalSet {\n    set<pair<T, T>> s;\n\n\
    \    IntervalSet() {\n      s.emplace(-inf(), -inf() + 1);\n      s.emplace(inf(),\
    \ inf() + 1);\n    }\n\n    T inf() const {\n      return numeric_limits<T>::max()\
    \ / 2;\n    }\n\n    bool is_inf(const pair<T, T> &p) const {\n      return p.first\
    \ == inf() or p.second == inf() or p.first == -inf() or p.second == -inf();\n\
    \    }\n\n    bool empty() const {\n      return s.size() <= 2;\n    }\n\n   \
    \ // contains { (l, r) | l <= x < r }\n    bool contains(T x) const {\n      if\
    \ (empty()) {\n        return false;\n      }\n\n      auto [l, r] = *(this->find(x));\n\
    \      return l <= x and x < r;\n    }\n\n    // find { (l, r) | l <= x < r }\n\
    \    typename set<pair<T, T>>::iterator find(int x) const {\n      // 1\u4EE5\u4E0A\
    \u306E\u6B63\u6574\u6570n\u306B\u3064\u3044\u3066pair(x, x+n) < pair(x+1, x+2)\u304C\
    \u6210\u308A\u7ACB\u3064\n      // \u307E\u305F\u3001pair(x, x+n) < a < pair(x+1,\
    \ x+2)\u306A\u308Ba\u306F\u5B58\u5728\u3057\u306A\u3044\u306E\u3067\n      //\
    \ contains(x)\u304C\u6210\u308A\u7ACB\u3064\u306A\u3089\u3070lower_bound\u3092\
    \u53D6\u3063\u305Fprev\u306Bx\u304C\u542B\u307E\u308C\u3066\u3044\u308B\n    \
    \  return prev(s.lower_bound(pair(x + 1, x + 2)));\n    }\n\n    pair<typename\
    \ set<pair<T, T>>::iterator, bool> insert(T x) {\n      return insert(pair(x,\
    \ x + 1));\n    }\n\n    // insert [l, r)\n    // \u3082\u3057[l, r)\u306B\u91CD\
    \u8907or\u9023\u7D9A\u3059\u308B\u533A\u9593\u304C\u5B58\u5728\u3059\u308B\u306A\
    \u3089\u3070\u305D\u308C\u3089\u3092\u524A\u9664\u3059\u308B\n    // \u8A08\u7B97\
    \u91CF : \u306A\u3089\u3057\u5BFE\u6570\u6642\u9593\n    // \u8FD4\u308A\u5024\
    \ : std::set::insert\u306B\u6E96\u62E0\n    pair<typename set<pair<T, T>>::iterator,\
    \ bool> insert(pair<T, T> p) {\n      assert(p.first < p.second);\n\n      auto\
    \ l_itr = find(p.first);\n      while (intersect(*l_itr, p) or continuous(*l_itr,\
    \ p)) {\n        p = extend_interval(*l_itr, p);\n        s.erase(l_itr);\n  \
    \      l_itr = find(p.first);\n      }\n\n      auto r_itr = find(p.second);\n\
    \      while (intersect(*r_itr, p) or continuous(*r_itr, p)) {\n        p = extend_interval(*r_itr,\
    \ p);\n        s.erase(r_itr);\n        r_itr = find(p.second);\n      }\n\n \
    \     return s.insert(p);\n    }\n\n    // erase { (l, r) | l <= x < r }\n   \
    \ void erase_interval(T x) {\n      if (not contains(x)) {\n        return;\n\
    \      }\n\n      auto it = find(x);\n      s.erase(it);\n    }\n\n    // { (l,\
    \ r) | l <= x < r } => { (l, x), (x+1, r) | l < x && x+1 < r}\n    void cut(T\
    \ x) {\n      if (not contains(x)) {\n        return;\n      }\n\n      auto it\
    \ = find(x);\n      auto [l, r] = *it;\n      s.erase(it);\n      if (l < x) {\n\
    \        s.emplace(l, x);\n      }\n      if (x + 1 < r) {\n        s.emplace(x\
    \ + 1, r);\n      }\n    }\n\n    template <typename T1>\n    friend ostream &operator<<(ostream\
    \ &os, const IntervalSet<T1> &rhs) {\n      os << \"{\";\n      bool is_first\
    \ = true;\n      for (const pair<T, T> &p: rhs.s) {\n        if (rhs.is_inf(p))\
    \ {\n          continue;\n        }\n        if (not is_first) {\n          os\
    \ << \", \";\n        }\n        is_first = false;\n        os << \"[\" << p.first\
    \ << \",\" << p.second << \")\";\n      }\n      os << \"}\";\n      return os;\n\
    \    }\n\n    pair<T, T> extend_interval(const pair<T, T> &p1, const pair<T, T>\
    \ &p2) const {\n      assert(intersect(p1, p2) or continuous(p1, p2));\n\n   \
    \   vector<T> a{ p1.first, p1.second, p2.first, p2.second };\n      sort(a.begin(),\
    \ a.end());\n      return { a.front(), a.back() };\n    }\n\n    bool intersect(pair<T,\
    \ T> p1, pair<T, T> p2) const {\n      if (p1 > p2) {\n        swap(p1, p2);\n\
    \      }\n      const auto &[a, b] = p1;\n      const auto &[c, d] = p2;\n   \
    \   return (a <= c and c < b) or (c <= a and a < d);\n    }\n\n    bool continuous(pair<T,\
    \ T> p1, pair<T, T> p2) const {\n      if (p1 > p2) {\n        swap(p1, p2);\n\
    \      }\n      return p1.second == p2.first;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/interval-set.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc/abc001/D.test.cpp
  - test/atcoder/abc/abc228/D.test.cpp
documentation_of: data-structure/interval-set.hpp
layout: document
redirect_from:
- /library/data-structure/interval-set.hpp
- /library/data-structure/interval-set.hpp.html
title: "[l, r)\u306E\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B"
---
