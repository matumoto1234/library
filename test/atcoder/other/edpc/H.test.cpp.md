---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  - icon: ':heavy_check_mark:'
    path: tools/mod-int.hpp
    title: tools/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_h
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_h
  bundledCode: "#line 1 \"test/atcoder/other/edpc/H.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/dp/tasks/dp_h\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"tools/mod-int.hpp\"\n\n#line 2 \"tools/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"tools/mod-int.hpp\"\n\n#line\
    \ 7 \"tools/mod-int.hpp\"\n#include <optional>\n#line 9 \"tools/mod-int.hpp\"\n\
    \nnamespace matumoto {\n  template <int m>\n  class ModInt {\n    using ll = long\
    \ long;\n    using ull = unsigned long long;\n    static_assert(1 <= m);\n\n \
    \   unsigned int v_;\n    bool has_nullval_;\n\n    static constexpr unsigned\
    \ int umod() {\n      return m;\n    }\n\n    constexpr ll extgcd(ll a, ll b,\
    \ ll &x, ll &y) {\n      if (b == 0) {\n        x = 1;\n        y = 0;\n     \
    \   return a;\n      }\n      ll d = extgcd(b, a % b, y, x);\n      y -= a / b\
    \ * x;\n      return d;\n    }\n\n    // gcd_inv:()|-> pair(g, x). g := gcd(v,\
    \ umod()). vx = g (mod umod())\n    constexpr pair<ll, ll> gcd_inv() const {\n\
    \      ll x = 0, y = 0;\n      ll d = extgcd(v_, umod(), x, y);\n      return\
    \ pair(d, x);\n    }\n\n  public:\n    using nullval_t = nullopt_t;\n    static\
    \ constexpr nullval_t nullval = nullopt;\n\n    constexpr ModInt() noexcept: v_(0),\
    \ has_nullval_(false) {}\n    constexpr ModInt(nullval_t x): v_(0), has_nullval_(true)\
    \ {}\n    ModInt(ll x): has_nullval_(false) {\n      if (abs(x) >= umod())\n \
    \       x %= umod();\n\n      if (x < 0)\n        x += umod();\n\n      v_ = x;\n\
    \    }\n\n    constexpr bool has_nullval() const noexcept {\n      return has_nullval_;\n\
    \    }\n\n    constexpr unsigned int val() const noexcept {\n      return v_;\n\
    \    }\n\n    constexpr ModInt &operator++() noexcept {\n      v_++;\n      if\
    \ (v_ == umod())\n        v_ = 0;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt &operator--() noexcept {\n      if (v_ == 0)\n        v_ = umod();\n\
    \      v_--;\n      return *this;\n    }\n\n    constexpr ModInt operator++([[maybe_unused]]\
    \ int unused) noexcept {\n      ModInt old = *this;\n      ++*this;\n      return\
    \ old;\n    }\n\n    constexpr ModInt operator--([[maybe_unused]] int unused)\
    \ noexcept {\n      ModInt old = *this;\n      --*this;\n      return old;\n \
    \   }\n\n    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {\n    \
    \  v_ += rhs.v_;\n      if (v_ >= umod())\n        v_ -= umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n      v_ -= rhs.v_;\n      if (v_ < 0)\n        v_ += umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt &operator*=(const ModInt &rhs) noexcept\
    \ {\n      ull z = v_;\n      z *= rhs.v_;\n      v_ = z % umod();\n      return\
    \ *this;\n    }\n\n    constexpr ModInt operator/=(const ModInt &rhs) {\n    \
    \  assert(rhs.v_ != 0);\n      return *this = *this * rhs.inv();\n    }\n\n  \
    \  constexpr ModInt operator+() const noexcept {\n      return *this;\n    }\n\
    \    constexpr ModInt operator-() const noexcept {\n      return ModInt() - *this;\n\
    \    }\n\n    constexpr ModInt pow(ll n) const {\n      // x = base \u306E 2\u3079\
    \u304D\u4E57\n      ModInt x = /* base = */ *this, res = 1;\n      if (n < 0)\
    \ {\n        const auto &[gcd, inverse] = gcd_inv();\n        assert(gcd == 1);\n\
    \        x = inverse;\n        n *= -1;\n      }\n      while (n) {\n        if\
    \ (n & 1)\n          res *= x;\n        x *= x;\n        n >>= 1;\n      }\n \
    \     return res;\n    }\n\n    constexpr ModInt inv() const {\n      const auto\
    \ &[gcd, inverse] = gcd_inv();\n      assert(gcd == 1);\n      return inverse;\n\
    \    }\n\n    constexpr friend ModInt operator+(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return ModInt(lhs) += rhs;\n    }\n\n    constexpr friend\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept {\n      return\
    \ ModInt(lhs) -= rhs;\n    }\n\n    constexpr friend ModInt operator*(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept {\n      return ModInt(lhs) *= rhs;\n    }\n\
    \n    constexpr friend ModInt operator/(const ModInt &lhs, const ModInt &rhs)\
    \ {\n      return ModInt(lhs) /= rhs;\n    }\n\n    constexpr friend bool operator==(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept {\n      return lhs.v_ == rhs.v_;\n\
    \    }\n\n    constexpr friend bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept {\n      return lhs.v_ != rhs.v_;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &rhs) {\n      ll temp;\n      is >> temp;\n\
    \      rhs = ModInt(temp);\n      return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &rhs) {\n      os << rhs.val();\n      return os;\n    }\n\
    \  };\n\n  using ModInt1000000007 = ModInt<1000000007>;\n  using ModInt998244353\
    \ = ModInt<998244353>;\n} // namespace matumoto\n#line 6 \"test/atcoder/other/edpc/H.test.cpp\"\
    \nusing namespace matumoto;\n\n// {{{ Templates\n\n// clang-format off\n\n// Macros\n\
    #define over_load_(_1,_2,_3,_4,NAME,...) NAME\n#define rep(...) over_load_(__VA_ARGS__,\
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
    \ on\n\n// }}} Templates\n\n\nbool is_inside(int y, int x, int h, int w) {\n \
    \ return 0 <= y and y < h and 0 <= x and x < w;\n}\n\nusing mint = ModInt1000000007;\n\
    \nint main() {\n  int h, w;\n  cin >> h >> w;\n\n  vector<string> as(h);\n  cin\
    \ >> as;\n\n  auto dp = make_vector(h, w, mint(0));\n  dp[0][0] = 1;\n\n  rep(i,\
    \ h) {\n    rep(j, w) {\n      int y = i;\n      int x = j;\n      rep(k, 2) {\n\
    \        int ny = y + dy[k];\n        int nx = x + dx[k];\n\n        if (not is_inside(ny,\
    \ nx, h, w))\n          continue;\n\n        if (as[ny][nx] == '#')\n        \
    \  continue;\n\n        dp[ny][nx] += dp[y][x];\n      }\n    }\n  }\n\n  cout\
    \ << dp[h - 1][w - 1] << endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_h\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"tools/mod-int.hpp\"\nusing namespace matumoto;\n\
    \n// {{{ Templates\n\n// clang-format off\n\n// Macros\n#define over_load_(_1,_2,_3,_4,NAME,...)\
    \ NAME\n#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)\n\
    #define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)\n#define\
    \ rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i)\
    \ += 1)\n#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i <\
    \ static_cast<int>(r); (i) += (stride))\n#define rrep(...) over_load_(__VA_ARGS__,\
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
    \ on\n\n// }}} Templates\n\n\nbool is_inside(int y, int x, int h, int w) {\n \
    \ return 0 <= y and y < h and 0 <= x and x < w;\n}\n\nusing mint = ModInt1000000007;\n\
    \nint main() {\n  int h, w;\n  cin >> h >> w;\n\n  vector<string> as(h);\n  cin\
    \ >> as;\n\n  auto dp = make_vector(h, w, mint(0));\n  dp[0][0] = 1;\n\n  rep(i,\
    \ h) {\n    rep(j, w) {\n      int y = i;\n      int x = j;\n      rep(k, 2) {\n\
    \        int ny = y + dy[k];\n        int nx = x + dx[k];\n\n        if (not is_inside(ny,\
    \ nx, h, w))\n          continue;\n\n        if (as[ny][nx] == '#')\n        \
    \  continue;\n\n        dp[ny][nx] += dp[y][x];\n      }\n    }\n  }\n\n  cout\
    \ << dp[h - 1][w - 1] << endl;\n}\n"
  dependsOn:
  - tools/mod-int.hpp
  - tools/base.hpp
  isVerificationFile: true
  path: test/atcoder/other/edpc/H.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/other/edpc/H.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/other/edpc/H.test.cpp
- /verify/test/atcoder/other/edpc/H.test.cpp.html
title: test/atcoder/other/edpc/H.test.cpp
---
