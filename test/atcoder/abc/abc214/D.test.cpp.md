---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find-undo.hpp
    title: data-structure/union-find-undo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc214/tasks/abc214_d
    links:
    - https://atcoder.jp/contests/abc214/tasks/abc214_d
  bundledCode: "#line 1 \"test/atcoder/abc/abc214/D.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc214/tasks/abc214_d\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"data-structure/union-find-undo.hpp\"\n\n#line\
    \ 2 \"data-structure/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n\
    }\n#line 4 \"data-structure/union-find-undo.hpp\"\n\n#line 9 \"data-structure/union-find-undo.hpp\"\
    \n\nnamespace matumoto {\n  // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\n  class UnionFindUndo\
    \ {\n  private:\n    // number of vertices\n    int n_;\n\n    vector<int> sizes_,\
    \ parents_;\n\n    // <index, parent(index), size(index)>\n    stack<tuple<int,\
    \ int, int>> history_;\n\n  public:\n    UnionFindUndo(int N): sizes_(N, 1), parents_(N)\
    \ {\n      iota(parents_.begin(), parents_.end(), 0);\n    }\n\n    // \u6839\uFF08\
    \u305D\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u8B58\u5225\u756A\u53F7\uFF09\n   \
    \ int root(int x) {\n      if (x == parents_[x])\n        return x;\n      return\
    \ root(parents_[x]);\n    }\n\n    int size(int x) {\n      return sizes_[root(x)];\n\
    \    }\n\n    bool same(int x, int y) {\n      return root(x) == root(y);\n  \
    \  }\n\n    // size(x) < size(y): -1\n    // not merged:         0\n    // size(x)\
    \ > size(y): +1\n    int merge(int x, int y) {\n      x = root(x);\n      y =\
    \ root(y);\n      if (x == y)\n        return 0;\n\n      int result = +1;\n \
    \     if (sizes_[x] < sizes_[y]) {\n        swap(x, y);\n        result = -1;\n\
    \      }\n\n      history_.emplace(tuple(x, parents_[x], sizes_[x]));\n      history_.emplace(tuple(y,\
    \ parents_[y], sizes_[y]));\n      sizes_[x] += sizes_[y];\n      parents_[y]\
    \ = x;\n      return result;\n    }\n\n    bool undo() {\n      if (history_.empty())\n\
    \        return false;\n\n      auto [x, x_parent, x_size] = history_.top();\n\
    \      history_.pop();\n      auto [y, y_parent, y_size] = history_.top();\n \
    \     history_.pop();\n\n      parents_[x] = x_parent;\n      sizes_[x] = x_size;\n\
    \      parents_[y] = y_parent;\n      sizes_[y] = y_size;\n      return true;\n\
    \    }\n\n    void clear_history() {\n      while (not history_.empty()) {\n \
    \       history_.pop();\n      }\n    }\n\n    void all_undo() {\n      while\
    \ (undo()) {}\n    }\n\n    // \u0398(N log(N))\n    vector<vector<int>> groups()\
    \ {\n      vector<vector<int>> grps(n_);\n      for (int i = 0; i < n_; i++) {\n\
    \        grps[root(i)].emplace_back(i);\n      }\n\n      vector<vector<int>>\
    \ res;\n      for (int i = 0; i < n_; i++) {\n        if (grps[i].empty())\n \
    \         continue;\n        res.emplace_back(grps[i]);\n      }\n      return\
    \ res;\n    }\n  };\n} // namespace matumoto\n#line 7 \"test/atcoder/abc/abc214/D.test.cpp\"\
    \nusing namespace matumoto;\n\n\n// {{{ Templates\n\n// clang-format off\n\n//\
    \ Macros\n#define over_load_(_1,_2,_3,_4,NAME,...) NAME\n#define rep(...) over_load_(__VA_ARGS__,\
    \ rep4, rep3, rep2)(__VA_ARGS__)\n#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r);\
    \ (i) += 1)\n#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r);\
    \ (i) += 1)\n#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l);\
    \ i < static_cast<int>(r); (i) += (stride))\n#define rrep(...) over_load_(__VA_ARGS__,\
    \ rrep4, rrep3, rrep2)(__VA_ARGS__)\n#define rrep2(i, r) for ( int i = static_cast<int>(r)\
    \ - 1; i >= 0; (i) -= 1)\n#define rrep3(i, l, r) for ( int i = static_cast<int>(r)\
    \ - 1; i >= static_cast<int>(l); (i) -= 1)\n#define rrep4(i, l, r, stride) for\
    \ ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))\n\
    #define len(x) (static_cast<int>((x).size()))\n#define whole(f, x, ...) ([&](decltype((x))\
    \ container) { return (f)( begin(container), end(container), ## __VA_ARGS__);\
    \ })(x)\n#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)(\
    \ rbegin(container), rend(container), ## __VA_ARGS__); })(x)\n#define debug(...)\
    \ debug_function(#__VA_ARGS__, __VA_ARGS__)\n\n// Operators\ntemplate <typename\
    \ T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os\
    \ << \"(\" << p.first << \",\" << p.second << \")\"; return os; }\ntemplate <typename\
    \ T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool\
    \ is_first = true; for (auto x: v) { os << (is_first ? \"\" : \" \") << x; is_first\
    \ = false; } return os; }\ntemplate <typename T> ostream &operator<<(ostream &os,\
    \ queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?\"\"\
    :\" \")<<v.front(); v.pop(); is_first = false; } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while\
    \ (!v.empty()) { os << (is_first?\"\":\" \") << v.top(); v.pop(); is_first=false;\
    \ } return os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? \"\" : \" \"\
    ); return os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\\n'; } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const deque<T>\
    \ &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? \"\" : \" \"); return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const set<T> &v)\
    \ { bool is_first = true; for (T x: v) { os << (is_first ? \"\" : \" \") << x;\
    \ is_first = false; } return os; }\ntemplate <typename T> istream &operator>>(istream\
    \ &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }\n\n// For debug\
    \ macro\nint find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs\
    \ = \"({[\", rbs = \")}]\"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i])\
    \ != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty())\
    \ bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }\ntemplate\
    \ <typename T, typename... Ts> void debug_function(string_view name, const T &a,\
    \ Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0,\
    \ end) << \":\" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\\n'; } else\
    \ { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end +\
    \ 1)), forward<Ts>(rest)...); } }\n\n// Functions\ntemplate <typename T> vector<T>\
    \ make_vector(size_t a, T b) { return vector<T>(a, b); }\ntemplate <typename...\
    \ Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...)); }\ntemplate <typename T1, typename T2> inline bool chmax(T1\
    \ &a, T2 b) { return a < b and (a = b, true); }\ntemplate <typename T1, typename\
    \ T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }\n\n//\
    \ Structs\nstruct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false);\
    \ cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;\n\
    \n// Type aliases\nusing ull = unsigned long long;\nusing ll = long long;\nusing\
    \ pll = pair<ll, ll>;\nusing pii = pair<int, int>;\n\n// Literals\nconstexpr ll\
    \ INF64 = INT64_MAX / 2;\nconstexpr int INF32 = INT32_MAX / 2;\nconstexpr int\
    \ dy[] = { 0, 1, -1, 0, -1, 1, -1, 1 };\nconstexpr int dx[] = { 1, 0, 0, -1, -1,\
    \ -1, 1, 1 };\nconstexpr int mod998244353 = 998244353;\nconstexpr int mod1000000007\
    \ = static_cast<int>(1e9) + 7;\nconstexpr char newl = '\\n';\n\n// clang-format\
    \ on\n\n// }}} Templates\n\n\nint main() {\n  int n;\n  cin >> n;\n\n  // <w,\
    \ u, v>\n  vector<tuple<int, int, int>> edges(n - 1);\n\n  UnionFindUndo uf(n);\n\
    \n  rep(i, n - 1) {\n    int u, v, w;\n    cin >> u >> v >> w;\n\n    u--, v--;\n\
    \n    edges[i] = tuple(w, u, v);\n  }\n\n  whole(sort, edges);\n\n  rep(i, n -\
    \ 1) {\n    auto [w, u, v] = edges[i];\n    uf.merge(u, v);\n  }\n\n\n  ll ans\
    \ = 0;\n\n  rrep(i, n - 1) {\n    auto [w, u, v] = edges[i];\n\n    uf.undo();\n\
    \    ans += ll(uf.size(u)) * ll(uf.size(v)) * ll(w);\n  }\n\n  cout << ans <<\
    \ newl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_d\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find-undo.hpp\"\
    \nusing namespace matumoto;\n\n\n// {{{ Templates\n\n// clang-format off\n\n//\
    \ Macros\n#define over_load_(_1,_2,_3,_4,NAME,...) NAME\n#define rep(...) over_load_(__VA_ARGS__,\
    \ rep4, rep3, rep2)(__VA_ARGS__)\n#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r);\
    \ (i) += 1)\n#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r);\
    \ (i) += 1)\n#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l);\
    \ i < static_cast<int>(r); (i) += (stride))\n#define rrep(...) over_load_(__VA_ARGS__,\
    \ rrep4, rrep3, rrep2)(__VA_ARGS__)\n#define rrep2(i, r) for ( int i = static_cast<int>(r)\
    \ - 1; i >= 0; (i) -= 1)\n#define rrep3(i, l, r) for ( int i = static_cast<int>(r)\
    \ - 1; i >= static_cast<int>(l); (i) -= 1)\n#define rrep4(i, l, r, stride) for\
    \ ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))\n\
    #define len(x) (static_cast<int>((x).size()))\n#define whole(f, x, ...) ([&](decltype((x))\
    \ container) { return (f)( begin(container), end(container), ## __VA_ARGS__);\
    \ })(x)\n#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)(\
    \ rbegin(container), rend(container), ## __VA_ARGS__); })(x)\n#define debug(...)\
    \ debug_function(#__VA_ARGS__, __VA_ARGS__)\n\n// Operators\ntemplate <typename\
    \ T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os\
    \ << \"(\" << p.first << \",\" << p.second << \")\"; return os; }\ntemplate <typename\
    \ T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool\
    \ is_first = true; for (auto x: v) { os << (is_first ? \"\" : \" \") << x; is_first\
    \ = false; } return os; }\ntemplate <typename T> ostream &operator<<(ostream &os,\
    \ queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?\"\"\
    :\" \")<<v.front(); v.pop(); is_first = false; } return os; }\ntemplate <typename\
    \ T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while\
    \ (!v.empty()) { os << (is_first?\"\":\" \") << v.top(); v.pop(); is_first=false;\
    \ } return os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? \"\" : \" \"\
    ); return os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\\n'; } return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const deque<T>\
    \ &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? \"\" : \" \"); return\
    \ os; }\ntemplate <typename T> ostream &operator<<(ostream &os, const set<T> &v)\
    \ { bool is_first = true; for (T x: v) { os << (is_first ? \"\" : \" \") << x;\
    \ is_first = false; } return os; }\ntemplate <typename T> istream &operator>>(istream\
    \ &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }\n\n// For debug\
    \ macro\nint find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs\
    \ = \"({[\", rbs = \")}]\"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i])\
    \ != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty())\
    \ bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }\ntemplate\
    \ <typename T, typename... Ts> void debug_function(string_view name, const T &a,\
    \ Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0,\
    \ end) << \":\" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\\n'; } else\
    \ { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end +\
    \ 1)), forward<Ts>(rest)...); } }\n\n// Functions\ntemplate <typename T> vector<T>\
    \ make_vector(size_t a, T b) { return vector<T>(a, b); }\ntemplate <typename...\
    \ Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a,\
    \ make_vector(ts...)); }\ntemplate <typename T1, typename T2> inline bool chmax(T1\
    \ &a, T2 b) { return a < b and (a = b, true); }\ntemplate <typename T1, typename\
    \ T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }\n\n//\
    \ Structs\nstruct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false);\
    \ cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;\n\
    \n// Type aliases\nusing ull = unsigned long long;\nusing ll = long long;\nusing\
    \ pll = pair<ll, ll>;\nusing pii = pair<int, int>;\n\n// Literals\nconstexpr ll\
    \ INF64 = INT64_MAX / 2;\nconstexpr int INF32 = INT32_MAX / 2;\nconstexpr int\
    \ dy[] = { 0, 1, -1, 0, -1, 1, -1, 1 };\nconstexpr int dx[] = { 1, 0, 0, -1, -1,\
    \ -1, 1, 1 };\nconstexpr int mod998244353 = 998244353;\nconstexpr int mod1000000007\
    \ = static_cast<int>(1e9) + 7;\nconstexpr char newl = '\\n';\n\n// clang-format\
    \ on\n\n// }}} Templates\n\n\nint main() {\n  int n;\n  cin >> n;\n\n  // <w,\
    \ u, v>\n  vector<tuple<int, int, int>> edges(n - 1);\n\n  UnionFindUndo uf(n);\n\
    \n  rep(i, n - 1) {\n    int u, v, w;\n    cin >> u >> v >> w;\n\n    u--, v--;\n\
    \n    edges[i] = tuple(w, u, v);\n  }\n\n  whole(sort, edges);\n\n  rep(i, n -\
    \ 1) {\n    auto [w, u, v] = edges[i];\n    uf.merge(u, v);\n  }\n\n\n  ll ans\
    \ = 0;\n\n  rrep(i, n - 1) {\n    auto [w, u, v] = edges[i];\n\n    uf.undo();\n\
    \    ans += ll(uf.size(u)) * ll(uf.size(v)) * ll(w);\n  }\n\n  cout << ans <<\
    \ newl;\n}\n"
  dependsOn:
  - data-structure/union-find-undo.hpp
  - data-structure/base.hpp
  isVerificationFile: true
  path: test/atcoder/abc/abc214/D.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc/abc214/D.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc/abc214/D.test.cpp
- /verify/test/atcoder/abc/abc214/D.test.cpp.html
title: test/atcoder/abc/abc214/D.test.cpp
---
