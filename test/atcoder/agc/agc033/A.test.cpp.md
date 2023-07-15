---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/convert-graph.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc033/tasks/agc033_a\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/convert-graph.hpp\"\
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
    \ on\n\n// }}} Templates\n\n\nint main() {\n  int h, w;\n  cin >> h >> w;\n  vector<string>\
    \ s(h);\n  cin >> s;\n\n  UnWeightedGraph graph = convert_graph(s, \"\");\n\n\
    \  vector<UnWeightedEdges> adj_list = graph.graph();\n\n  queue<int> q;\n  vector<bool>\
    \ used(h * w, false);\n  vector<int> depths(h * w, 0);\n\n  rep(i, h) {\n    rep(j,\
    \ w) {\n      if (s[i][j] == '#') {\n        int v = i * w + j;\n        q.push(v);\n\
    \        used[v] = true;\n      }\n    }\n  }\n\n  while (not q.empty()) {\n \
    \   int v = q.front();\n    q.pop();\n\n    for (auto edge: adj_list[v]) {\n \
    \     int to = edge.to();\n\n      if (used[to])\n        continue;\n\n      used[to]\
    \ = true;\n      depths[to] = depths[v] + 1;\n      q.push(to);\n    }\n  }\n\n\
    \  int max_depth = *max_element(depths.begin(), depths.end());\n\n  cout << max_depth\
    \ << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/agc/agc033/A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/agc/agc033/A.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc/agc033/A.test.cpp
- /verify/test/atcoder/agc/agc033/A.test.cpp.html
title: test/atcoder/agc/agc033/A.test.cpp
---
