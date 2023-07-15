---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  - icon: ':question:'
    path: data-structure/interval-set.hpp
    title: "[l, r)\u306E\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc001/tasks/abc001_4
    links:
    - https://atcoder.jp/contests/abc001/tasks/abc001_4
  bundledCode: "#line 1 \"test/atcoder/abc/abc001/D.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc001/tasks/abc001_4\n// verification-helper:\
    \ IGNORE\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data-structure/interval-set.hpp\"\
    \n\n#line 2 \"data-structure/base.hpp\"\n\nnamespace matumoto {\n  using namespace\
    \ std;\n}\n#line 4 \"data-structure/interval-set.hpp\"\n\n#line 11 \"data-structure/interval-set.hpp\"\
    \n\nnamespace matumoto {\n  // verify:ABC001_D\n  // verify:ABC228_D\n\n  /**\n\
    \   * @brief [l, r)\u306E\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n   *    \
    \    2\u3064\u306E\u533A\u9593[l1, r1), [l2, r2)\u306F\u91CD\u8907\u3001\u9023\
    \u7D50\u3057\u3066\u3044\u306A\u3044\n   *        \u4EFB\u610F\u306E\u6574\u6570\
    x\u3092\u542B\u3080\u533A\u9593\u306E\u6570\u306F\u9AD8\u30051\u3064\n   */\n\
    \  template <typename T = long long>\n  struct IntervalSet {\n    set<pair<T,\
    \ T>> s;\n\n    IntervalSet() {\n      s.emplace(-inf(), -inf() + 1);\n      s.emplace(inf(),\
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
    \      }\n      return p1.second == p2.first;\n    }\n  };\n} // namespace matumoto\n\
    #line 8 \"test/atcoder/abc/abc001/D.test.cpp\"\n\n// {{{ Templates\n\n// clang-format\
    \ off\n\n// Macros\n#define over_load_(_1,_2,_3,_4,NAME,...) NAME\n#define rep(...)\
    \ over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)\n#define rep2(i, r) for\
    \ ( int i = 0; i < static_cast<int>(r); (i) += 1)\n#define rep3(i, l, r) for (\
    \ int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)\n#define rep4(i,\
    \ l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i)\
    \ += (stride))\n#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)\n\
    #define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)\n\
    #define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l);\
    \ (i) -= 1)\n#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r)\
    \ - 1; i >= static_cast<int>(l); (i) -= (stride))\n#define len(x) (static_cast<int>((x).size()))\n\
    #define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container),\
    \ end(container), ## __VA_ARGS__); })(x)\n#define rwhole(f, x, ...) ([&](decltype((x))\
    \ container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__);\
    \ })(x)\n#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)\n\n// Operators\n\
    template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p) { os << \"(\" << p.first << \",\" << p.second << \")\"; return os; }\n\
    template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1,\
    \ T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? \"\" : \"\
    \ \") << x; is_first = false; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?\"\
    \":\" \")<<v.front(); v.pop(); is_first = false; } return os; }\ntemplate <typename\
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
    \ on\n\n// }}} Templates\n\n\nnamespace matumoto {\n  using namespace std;\n}\n\
    \n#line 78 \"test/atcoder/abc/abc001/D.test.cpp\"\n\nnamespace matumoto {\n  vector<string>\
    \ split(const string &str, const string &sep, const int &max_split = INT32_MAX)\
    \ {\n    vector<string> res;\n    string t = \"\";\n    int cnt_split = 0;\n \
    \   for (auto c: str) {\n      if (sep.find(c) == string::npos or cnt_split >=\
    \ max_split) {\n        t += c;\n        continue;\n      }\n      res.emplace_back(t);\n\
    \      t = \"\";\n      cnt_split++;\n    }\n    if (t != \"\")\n      res.emplace_back(t);\n\
    \    return res;\n  }\n} // namespace matumoto\n\n\nll time_to_ll(string time)\
    \ {\n  assert(time.size() == 4);\n  ll hour = stoll(string({ time[0] }) + string({\
    \ time[1] })) * 60;\n  ll minute = stoll(string({ time[2] }) + string({ time[3]\
    \ }));\n  return hour + minute;\n}\n\nstring ll_to_time(ll v) {\n  ll minute =\
    \ v % 60;\n  ll hour = v / 60;\n\n  stringstream sout1;\n  sout1 << setfill('0')\
    \ << setw(2) << hour;\n\n  stringstream sout2;\n  sout2 << setfill('0') << setw(2)\
    \ << minute;\n\n  return sout1.str() + sout2.str();\n}\n\nint main() {\n  int\
    \ n;\n  cin >> n;\n\n  matumoto::IntervalSet<long long> s;\n\n  rep(i, n) {\n\
    \    string line;\n    cin >> line;\n\n    auto times = matumoto::split(line,\
    \ \"-\");\n    ll begin = time_to_ll(times[0]);\n\n    ll digit = begin % 10;\n\
    \    if (digit != 0 and digit != 5) {\n      begin -= digit;\n      if (digit\
    \ > 5) {\n        begin += 5;\n      }\n    }\n\n    ll end = time_to_ll(times[1]);\n\
    \n    if (end % 10 != 0 and end % 10 != 5) {\n      if (end % 10 < 5) {\n    \
    \    end += 5 - end % 10;\n      } else {\n        end += 10 - end % 10;\n   \
    \   }\n    }\n\n    s.insert(make_pair(begin, end));\n  }\n\n  for (auto [begin,\
    \ end]: s.s) {\n    if (begin == s.inf() or begin == -s.inf()) {\n      continue;\n\
    \    }\n    if (end == s.inf() or end == -s.inf()) {\n      continue;\n    }\n\
    \n    auto b = ll_to_time(begin);\n    auto e = ll_to_time(end);\n\n    cout <<\
    \ b + \"-\" + e << newl;\n  }\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc001/tasks/abc001_4\n\
    // verification-helper: IGNORE\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#include \"data-structure/interval-set.hpp\"\n\n// {{{ Templates\n\n// clang-format\
    \ off\n\n// Macros\n#define over_load_(_1,_2,_3,_4,NAME,...) NAME\n#define rep(...)\
    \ over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)\n#define rep2(i, r) for\
    \ ( int i = 0; i < static_cast<int>(r); (i) += 1)\n#define rep3(i, l, r) for (\
    \ int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)\n#define rep4(i,\
    \ l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i)\
    \ += (stride))\n#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)\n\
    #define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)\n\
    #define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l);\
    \ (i) -= 1)\n#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r)\
    \ - 1; i >= static_cast<int>(l); (i) -= (stride))\n#define len(x) (static_cast<int>((x).size()))\n\
    #define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container),\
    \ end(container), ## __VA_ARGS__); })(x)\n#define rwhole(f, x, ...) ([&](decltype((x))\
    \ container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__);\
    \ })(x)\n#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)\n\n// Operators\n\
    template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p) { os << \"(\" << p.first << \",\" << p.second << \")\"; return os; }\n\
    template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1,\
    \ T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? \"\" : \"\
    \ \") << x; is_first = false; } return os; }\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?\"\
    \":\" \")<<v.front(); v.pop(); is_first = false; } return os; }\ntemplate <typename\
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
    \ on\n\n// }}} Templates\n\n\nnamespace matumoto {\n  using namespace std;\n}\n\
    \n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  vector<string>\
    \ split(const string &str, const string &sep, const int &max_split = INT32_MAX)\
    \ {\n    vector<string> res;\n    string t = \"\";\n    int cnt_split = 0;\n \
    \   for (auto c: str) {\n      if (sep.find(c) == string::npos or cnt_split >=\
    \ max_split) {\n        t += c;\n        continue;\n      }\n      res.emplace_back(t);\n\
    \      t = \"\";\n      cnt_split++;\n    }\n    if (t != \"\")\n      res.emplace_back(t);\n\
    \    return res;\n  }\n} // namespace matumoto\n\n\nll time_to_ll(string time)\
    \ {\n  assert(time.size() == 4);\n  ll hour = stoll(string({ time[0] }) + string({\
    \ time[1] })) * 60;\n  ll minute = stoll(string({ time[2] }) + string({ time[3]\
    \ }));\n  return hour + minute;\n}\n\nstring ll_to_time(ll v) {\n  ll minute =\
    \ v % 60;\n  ll hour = v / 60;\n\n  stringstream sout1;\n  sout1 << setfill('0')\
    \ << setw(2) << hour;\n\n  stringstream sout2;\n  sout2 << setfill('0') << setw(2)\
    \ << minute;\n\n  return sout1.str() + sout2.str();\n}\n\nint main() {\n  int\
    \ n;\n  cin >> n;\n\n  matumoto::IntervalSet<long long> s;\n\n  rep(i, n) {\n\
    \    string line;\n    cin >> line;\n\n    auto times = matumoto::split(line,\
    \ \"-\");\n    ll begin = time_to_ll(times[0]);\n\n    ll digit = begin % 10;\n\
    \    if (digit != 0 and digit != 5) {\n      begin -= digit;\n      if (digit\
    \ > 5) {\n        begin += 5;\n      }\n    }\n\n    ll end = time_to_ll(times[1]);\n\
    \n    if (end % 10 != 0 and end % 10 != 5) {\n      if (end % 10 < 5) {\n    \
    \    end += 5 - end % 10;\n      } else {\n        end += 10 - end % 10;\n   \
    \   }\n    }\n\n    s.insert(make_pair(begin, end));\n  }\n\n  for (auto [begin,\
    \ end]: s.s) {\n    if (begin == s.inf() or begin == -s.inf()) {\n      continue;\n\
    \    }\n    if (end == s.inf() or end == -s.inf()) {\n      continue;\n    }\n\
    \n    auto b = ll_to_time(begin);\n    auto e = ll_to_time(end);\n\n    cout <<\
    \ b + \"-\" + e << newl;\n  }\n}\n"
  dependsOn:
  - data-structure/interval-set.hpp
  - data-structure/base.hpp
  isVerificationFile: true
  path: test/atcoder/abc/abc001/D.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc/abc001/D.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc/abc001/D.test.cpp
- /verify/test/atcoder/abc/abc001/D.test.cpp.html
title: test/atcoder/abc/abc001/D.test.cpp
---
