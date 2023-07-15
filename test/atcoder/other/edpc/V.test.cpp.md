---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/base.hpp
    title: dp/base.hpp
  - icon: ':heavy_check_mark:'
    path: dp/re-rooting-dp.hpp
    title: dp/re-rooting-dp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/dp/tasks/dp_v
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_v
  bundledCode: "#line 1 \"test/atcoder/other/edpc/V.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/dp/tasks/dp_v\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"dp/re-rooting-dp.hpp\"\n\n#line 2 \"dp/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n}\n#line 4 \"dp/re-rooting-dp.hpp\"\n\n\
    #line 9 \"dp/re-rooting-dp.hpp\"\n\nnamespace matumoto {\n  // TODO verify:EDPC-V,\
    \ ABC220-F, ABC160-F\n  // add_node: \u81EA\u8EAB\u306E\u5024\u3092\u8FFD\u52A0\
    \u3057\u3066\u89AA\u65B9\u5411\u3078\u6E21\u3059\u95A2\u6570 (T result, int index)\
    \ |-> T\n  // op: \u4E8C\u9805\u6F14\u7B97 (monoid)\n  // e: op\u306B\u95A2\u3059\
    \u308B\u5358\u4F4D\u5143\n  template <typename T, T (*add_node)(T, int), T (*op)(T,\
    \ T), T (*e)()>\n  class ReRootingDP {\n    // order \u3068 parents \u306E\u524D\
    \u8A08\u7B97\n    void dfs(int root) {\n      int index = 0;\n      stack<int>\
    \ s;\n      s.push(root);\n      m_parents[root] = -1;\n\n      while (not s.empty())\
    \ {\n        int node = s.top();\n        s.pop();\n\n        m_order[index++]\
    \ = node;\n        for (auto [adjacent, ignore]: m_tree[node]) {\n          if\
    \ (adjacent == m_parents[node])\n            continue;\n          s.push(adjacent);\n\
    \          m_parents[adjacent] = node;\n        }\n      }\n    }\n\n    // \u6839\
    \u306E\u5024\u3092\u6C42\u3081\u308B\u305F\u3081\u306B\u5168\u9802\u70B9\u306E\
    \u5B50\u65B9\u5411\u306E\u5024\u3092\u5E30\u308A\u304C\u3051\u9806\u3067\u6C42\
    \u3081\u308B\n    // child_subtree_results[node][i] (\u9802\u70B9node\u306Ei\u756A\
    \u76EE\u306E\u5B50\u90E8\u5206\u6728\u306E\u5024) \u304C\u6C42\u307E\u308B\n \
    \   // \u305F\u3060\u3057\u3001\u5B50\u65B9\u5411\u3092\u89AA\u3068\u3057\u305F\
    \u3068\u304D\u306E child_subtree_results[node][i] \u306F\u6C42\u307E\u3089\u306A\
    \u3044\n    void post_order(int root) {\n      vector<int> reversed_order = m_order;\n\
    \      reverse(reversed_order.begin(), reversed_order.end());\n\n      for (int\
    \ node: reversed_order) {\n        if (node == root)\n          continue;\n\n\
    \        int parent = m_parents[node];\n        int parent_index = -1;\n     \
    \   T result = e();\n\n        for (int i = 0; i < (int)m_tree[node].size(); i++)\
    \ {\n          int to = m_tree[node][i].first;\n          if (to == parent) {\n\
    \            parent_index = i;\n            continue;\n          }\n\n       \
    \   result = op(result, m_child_subtree_results[node][i]);\n        }\n\n    \
    \    assert(parent_index != -1);\n        m_child_subtree_results[parent][m_index_for_adjacents[node][parent_index]]\
    \ = add_node(result, node);\n      }\n    }\n\n    // \u5168\u9802\u70B9\u306E\
    \u89AA\u65B9\u5411\u306E\u5024\u3092\u4E21\u5074\u7D2F\u7A4D\u3092\u4F7F\u3063\
    \u3066\u6C42\u3081\u308B(\u884C\u304D\u304C\u3051\u9806)\n    // node_results[node]\
    \ \u304C\u6C42\u307E\u308B\n    void pre_order() {\n      for (int node: m_order)\
    \ {\n        int size = m_tree[node].size();\n\n        if (size == 0)\n     \
    \     continue;\n\n        vector<T> accums_front(size + 1, e()), accums_back(size,\
    \ e());\n\n        for (int i = 0; i < size; i++) {\n          T child_subtree_result\
    \ = m_child_subtree_results[node][i];\n          accums_front[i + 1] = op(accums_front[i],\
    \ child_subtree_result);\n        }\n        for (int i = size - 1; i >= 1; i--)\
    \ {\n          T child_subtree_result = m_child_subtree_results[node][i];\n  \
    \        accums_back[i - 1] = op(accums_back[i], child_subtree_result);\n    \
    \    }\n\n        for (int i = 0; i < size; i++) {\n          T result = add_node(op(accums_front[i],\
    \ accums_back[i]), node);\n\n          int parent = m_tree[node][i].first;\n \
    \         int index_from_parent = m_index_for_adjacents[node][i];\n\n        \
    \  m_child_subtree_results[parent][index_from_parent] = result;\n        }\n \
    \       T accum_child_subtree_result = accums_front.back();\n        m_node_results[node]\
    \ = add_node(accum_child_subtree_result, node);\n      }\n    }\n\n  public:\n\
    \    using Edge = pair<int, T>;\n    vector<vector<Edge>> m_tree;\n    vector<vector<int>>\
    \ m_index_for_adjacents;\n    vector<vector<T>> m_child_subtree_results;\n   \
    \ vector<int> m_parents, m_order;\n    vector<T> m_node_results;\n\n    ReRootingDP(int\
    \ n): m_tree(n), m_index_for_adjacents(n), m_parents(n), m_order(n), m_node_results(n,\
    \ e()) {}\n\n    // Directed edge\n    void add_edge(int from, int to, T cost)\
    \ {\n      m_tree[from].emplace_back(to, cost);\n      m_index_for_adjacents[to].emplace_back(m_tree[from].size()\
    \ - 1);\n    }\n\n    void build() {\n      int size = m_tree.size();\n      assert(size\
    \ != 0);\n      m_child_subtree_results.resize(size);\n      for (int i = 0; i\
    \ < size; i++) {\n        m_child_subtree_results[i].assign(m_tree[i].size(),\
    \ e());\n      }\n\n      dfs(/* root = */ 0);\n      post_order(/* root = */\
    \ 0);\n      pre_order();\n    }\n\n    T operator[](int node) {\n      return\
    \ m_node_results[node];\n    }\n  };\n} // namespace matumoto\n#line 6 \"test/atcoder/other/edpc/V.test.cpp\"\
    \nusing namespace matumoto;\n\nusing ll = long long;\nll m;\n\nll op(ll a, ll\
    \ b) {\n  return (a * b) % m;\n}\n\nll e() {\n  return 1;\n}\n\nll add_node(ll\
    \ result, int node) {\n  return result + 1;\n}\n\nint main() {\n  ll n;\n  cin\
    \ >> n >> m;\n\n  if (n == 1) {\n    cout << 1 << endl;\n    return 0;\n  }\n\n\
    \  ReRootingDP<ll, add_node, op, e> dp(n);\n\n  for (int i = 0; i < n - 1; i++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n\n    x--, y--;\n\n    dp.add_edge(x,\
    \ y, 1);\n    dp.add_edge(y, x, 1);\n  }\n\n  dp.build();\n\n  for (int i = 0;\
    \ i < n; i++) {\n    // \u4F59\u5206\u306B add_node \u3057\u305F(\u5B58\u5728\u3057\
    \u306A\u3044\u89AA\u306B\u5BFE\u3057\u3066\u81EA\u5206\u3092\u542B\u3081\u305F\
    \u7D50\u679C\u3092\u8FD4\u3057\u3066\u3044\u308B)\u306E\u304C\u3042\u308B\u306E\
    \u3067\u3001\u305D\u306E\u5206\u3092 -1\n    ll ans = dp[i] - 1;\n    ans %= m;\n\
    \    cout << ans << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_v\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"dp/re-rooting-dp.hpp\"\nusing namespace matumoto;\n\
    \nusing ll = long long;\nll m;\n\nll op(ll a, ll b) {\n  return (a * b) % m;\n\
    }\n\nll e() {\n  return 1;\n}\n\nll add_node(ll result, int node) {\n  return\
    \ result + 1;\n}\n\nint main() {\n  ll n;\n  cin >> n >> m;\n\n  if (n == 1) {\n\
    \    cout << 1 << endl;\n    return 0;\n  }\n\n  ReRootingDP<ll, add_node, op,\
    \ e> dp(n);\n\n  for (int i = 0; i < n - 1; i++) {\n    int x, y;\n    cin >>\
    \ x >> y;\n\n    x--, y--;\n\n    dp.add_edge(x, y, 1);\n    dp.add_edge(y, x,\
    \ 1);\n  }\n\n  dp.build();\n\n  for (int i = 0; i < n; i++) {\n    // \u4F59\u5206\
    \u306B add_node \u3057\u305F(\u5B58\u5728\u3057\u306A\u3044\u89AA\u306B\u5BFE\u3057\
    \u3066\u81EA\u5206\u3092\u542B\u3081\u305F\u7D50\u679C\u3092\u8FD4\u3057\u3066\
    \u3044\u308B)\u306E\u304C\u3042\u308B\u306E\u3067\u3001\u305D\u306E\u5206\u3092\
    \ -1\n    ll ans = dp[i] - 1;\n    ans %= m;\n    cout << ans << endl;\n  }\n\
    }\n"
  dependsOn:
  - dp/re-rooting-dp.hpp
  - dp/base.hpp
  isVerificationFile: true
  path: test/atcoder/other/edpc/V.test.cpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/other/edpc/V.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/other/edpc/V.test.cpp
- /verify/test/atcoder/other/edpc/V.test.cpp.html
title: test/atcoder/other/edpc/V.test.cpp
---
