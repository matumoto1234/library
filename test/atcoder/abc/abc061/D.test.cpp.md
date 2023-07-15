---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/adjacency-list-to-edges.hpp
    title: graph/adjacency-list-to-edges.hpp
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/bellman-ford.hpp
    title: graph/bellman-ford.hpp
  - icon: ':x:'
    path: tools/assert-msg.hpp
    title: tools/assert-msg.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc061/tasks/abc061_d
    links:
    - https://atcoder.jp/contests/abc061/tasks/abc061_d
  bundledCode: "#line 1 \"test/atcoder/abc/abc061/D.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc061/tasks/abc061_d\n// verification-helper:\
    \ IGNORE\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/bellman-ford.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n\
    }\n#line 2 \"graph/adjacency-list-to-edges.hpp\"\n\n#line 5 \"graph/adjacency-list-to-edges.hpp\"\
    \n\nnamespace matumoto {\n  vector<pair<int, int>> adjacency_list_to_edges(const\
    \ vector<vector<int>> &adj_list) {\n    vector<pair<int, int>> edges;\n    for\
    \ (int v = 0; v < (int)adj_list.size(); v++) {\n      for (const auto &to: adj_list[v])\
    \ {\n        edges.emplace_back(v, to);\n      }\n    }\n    return edges;\n \
    \ }\n\n  template <typename Cost>\n  vector<tuple<int, int, Cost>> adjacency_list_to_edges(const\
    \ vector<vector<pair<Cost, int>>> &adj_list) {\n    vector<tuple<int, int, Cost>>\
    \ edges;\n    for (int v = 0; v < (int)adj_list.size(); v++) {\n      for (const\
    \ auto &[cost, to]: adj_list[v]) {\n        edges.emplace_back(v, to, cost);\n\
    \      }\n    }\n    return edges;\n  }\n} // namespace matumoto\n#line 2 \"tools/assert-msg.hpp\"\
    \n\n#line 2 \"tools/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n\
    }\n#line 4 \"tools/assert-msg.hpp\"\n\n#line 8 \"tools/assert-msg.hpp\"\n\nnamespace\
    \ matumoto {\n#define assert_msg(expr, msg) (static_cast<bool>(expr) ? void(0)\
    \ : assert_fail(__FILE__, __LINE__, #expr, msg))\n\n  namespace {\n    void assert_fail(const\
    \ char *file, int line, const char expr_str[], string msg) {\n      cerr << \"\
    File: \" << file << \"\\n\"\n           << \"Line: \" << line << \"\\n\"\n   \
    \        << \"Assertion '\" << expr_str << \"' failed.\\n\"\n           << \"\
    Message: \" << msg << \"\\n\";\n      abort();\n    }\n  } // namespace\n} //\
    \ namespace matumoto\n#line 6 \"graph/bellman-ford.hpp\"\n\n#line 11 \"graph/bellman-ford.hpp\"\
    \n\nnamespace matumoto {\n  template <typename Cost>\n  class BellmanFord {\n\
    \    // adjacency list\n    vector<vector<pair<Cost, int>>> adj_list_;\n    vector<tuple<int,\
    \ int, Cost>> edges_;\n    vector<Cost> dists_;\n    vector<int> prevs_;\n   \
    \ int start_, goal_;\n    bool has_neg_cycle_, has_neg_cycle_to_goal_;\n\n  public:\n\
    \    BellmanFord(const vector<vector<pair<Cost, int>>> &adj_list, int start, int\
    \ goal = -1)\n      : adj_list_(adj_list),\n        dists_(adj_list_.size(), inf()),\n\
    \        prevs_(adj_list_.size(), -1),\n        start_(start),\n        goal_(goal),\n\
    \        has_neg_cycle_(false),\n        has_neg_cycle_to_goal_(false) {\n   \
    \   int n = adj_list_.size();\n      if (goal_ == -1) {\n        goal_ = n - 1;\n\
    \      }\n      assert_msg(0 <= start and start < n, \"start:\" + to_string(start)\
    \ + \" n:\" + to_string(n));\n      assert_msg(0 <= goal and goal < n, \"goal:\"\
    \ + to_string(goal) + \" n:\" + to_string(n));\n\n      edges_ = adjacency_list_to_edges(adj_list_);\n\
    \n      dists_[start] = 0;\n\n      for (int i = 0; i < 2 * n; i++) {\n      \
    \  for (const auto &[from, to, cost]: edges_) {\n          assert_msg(0 <= from\
    \ and from < n, \"from:\" + to_string(from) + \" n:\" + to_string(n));\n     \
    \     assert_msg(0 <= to and to < n, \"to:\" + to_string(to) + \" n:\" + to_string(n));\n\
    \n          if (dists_[from] >= inf() or dists_[from] + cost >= dists_[to]) {\n\
    \            continue;\n          }\n\n          if (i >= n - 1 and to == goal)\
    \ {\n            has_neg_cycle_ = true;\n            has_neg_cycle_to_goal_ =\
    \ true;\n            return;\n          } else if (i >= n - 1) {\n           \
    \ has_neg_cycle_ = true;\n            dists_[to] = -inf();\n          } else {\n\
    \            dists_[to] = dists_[from] + cost;\n            prevs_[to] = from;\n\
    \          }\n        }\n      }\n    }\n\n    static constexpr Cost inf() {\n\
    \      return numeric_limits<Cost>::max() / 2;\n    }\n\n    bool has_negative_cycle()\
    \ const {\n      return has_neg_cycle_;\n    }\n\n    bool has_negative_cycle_to_goal()\
    \ const {\n      return has_neg_cycle_to_goal_;\n    }\n\n    Cost &operator[](int\
    \ k) {\n      assert_msg(0 <= k and k < (int)dists_.size(), \"k:\" + to_string(k)\
    \ + \" size:\" + to_string(dists_.size()));\n      return dists_[k];\n    }\n\n\
    \    vector<int> restore(int to) {\n      assert_msg(0 <= to and to < (int)dists_.size(),\
    \ \"to:\" + to_string(to) + \" size:\" + to_string(prevs_.size()));\n      vector<int>\
    \ path;\n      if (prevs_[to] == -1) {\n        path.emplace_back(to);\n     \
    \   return path;\n      }\n\n      while (prevs_[to] != -1) {\n        path.emplace_back(to);\n\
    \        to = prevs_.at(to);\n      }\n      reverse(path.begin(), path.end());\n\
    \      return path;\n    }\n  };\n} // namespace matumoto\n#line 8 \"test/atcoder/abc/abc061/D.test.cpp\"\
    \nusing namespace matumoto;\n\nusing ll = long long;\n\nint main() {\n  int n,\
    \ m;\n  cin >> n >> m;\n\n  vector<vector<pair<ll, int>>> adj_list(n);\n  for\
    \ (int i = 0; i < m; i++) {\n    int a, b;\n    ll c;\n    cin >> a >> b >> c;\n\
    \n    a--;\n    b--;\n\n    adj_list[a].emplace_back(-c, b);\n  }\n\n  auto bf\
    \ = BellmanFord<ll>(adj_list, 0, n - 1);\n  if (bf.has_negative_cycle()) {\n \
    \   cout << \"inf\" << endl;\n  } else {\n    cout << -bf[n - 1] << endl;\n  }\n\
    }\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc061/tasks/abc061_d\n\
    // verification-helper: IGNORE\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#include \"graph/bellman-ford.hpp\"\nusing namespace matumoto;\n\nusing ll =\
    \ long long;\n\nint main() {\n  int n, m;\n  cin >> n >> m;\n\n  vector<vector<pair<ll,\
    \ int>>> adj_list(n);\n  for (int i = 0; i < m; i++) {\n    int a, b;\n    ll\
    \ c;\n    cin >> a >> b >> c;\n\n    a--;\n    b--;\n\n    adj_list[a].emplace_back(-c,\
    \ b);\n  }\n\n  auto bf = BellmanFord<ll>(adj_list, 0, n - 1);\n  if (bf.has_negative_cycle())\
    \ {\n    cout << \"inf\" << endl;\n  } else {\n    cout << -bf[n - 1] << endl;\n\
    \  }\n}\n"
  dependsOn:
  - graph/bellman-ford.hpp
  - graph/adjacency-list-to-edges.hpp
  - graph/base.hpp
  - tools/assert-msg.hpp
  isVerificationFile: true
  path: test/atcoder/abc/abc061/D.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc/abc061/D.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc/abc061/D.test.cpp
- /verify/test/atcoder/abc/abc061/D.test.cpp.html
title: test/atcoder/abc/abc061/D.test.cpp
---
