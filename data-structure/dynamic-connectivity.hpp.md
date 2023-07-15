---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/base.hpp
    title: data-structure/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-connectivity.hpp\"\n\n#line 2 \"\
    data-structure/base.hpp\"\n\nnamespace matumoto {\n  using namespace std;\n}\n\
    #line 4 \"data-structure/dynamic-connectivity.hpp\"\n\n#include <functional>\n\
    #include <iostream>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\nnamespace matumoto {\n  template <typename T>\n  class DynamicConnectivity\
    \ {\n    class EulerTourTree {\n    public:\n      struct node;\n      using np\
    \ = node *;\n      using lint = long long;\n      struct node {\n        np ch[2]\
    \ = { nullptr, nullptr };\n        np p = nullptr;\n        int l, r, sz;\n  \
    \      T val = et, sum = et;\n        bool exact;\n        bool child_exact;\n\
    \        bool edge_connected = 0;\n        bool child_edge_connected = 0;\n  \
    \      node() {}\n        node(int l, int r): l(l), r(r), sz(l == r), exact(l\
    \ < r), child_exact(l < r) {}\n        bool is_root() {\n          return !p;\n\
    \        }\n      };\n      vector<unordered_map<int, np>> ptr;\n      np get_node(int\
    \ l, int r) {\n        if (ptr[l].find(r) == ptr[l].end())\n          ptr[l][r]\
    \ = new node(l, r);\n        return ptr[l][r];\n      }\n      np root(np t) {\n\
    \        if (!t)\n          return t;\n        while (t->p)\n          t = t->p;\n\
    \        return t;\n      }\n      bool same(np s, np t) {\n        if (s)\n \
    \         splay(s);\n        if (t)\n          splay(t);\n        return root(s)\
    \ == root(t);\n      }\n      np reroot(np t) {\n        auto s = split(t);\n\
    \        return merge(s.second, s.first);\n      }\n      pair<np, np> split(np\
    \ s) {\n        splay(s);\n        np t = s->ch[0];\n        if (t)\n        \
    \  t->p = nullptr;\n        s->ch[0] = nullptr;\n        return { t, update(s)\
    \ };\n      }\n      pair<np, np> split2(np s) {\n        splay(s);\n        np\
    \ t = s->ch[0];\n        np u = s->ch[1];\n        if (t)\n          t->p = nullptr;\n\
    \        s->ch[0] = nullptr;\n        if (u)\n          u->p = nullptr;\n    \
    \    s->ch[1] = nullptr;\n        return { t, u };\n      }\n      tuple<np, np,\
    \ np> split(np s, np t) {\n        auto u = split2(s);\n        if (same(u.first,\
    \ t)) {\n          auto r = split2(t);\n          return make_tuple(r.first, r.second,\
    \ u.second);\n        } else {\n          auto r = split2(t);\n          return\
    \ make_tuple(u.first, r.first, r.second);\n        }\n      }\n      template\
    \ <typename First, typename... Rest>\n      np merge(First s, Rest... t) {\n \
    \       return merge(s, merge(t...));\n      }\n      np merge(np s, np t) {\n\
    \        if (!s)\n          return t;\n        if (!t)\n          return s;\n\
    \        while (s->ch[1])\n          s = s->ch[1];\n        splay(s);\n      \
    \  s->ch[1] = t;\n        if (t)\n          t->p = s;\n        return update(s);\n\
    \      }\n      int size(np t) {\n        return t ? t->sz : 0;\n      }\n   \
    \   np update(np t) {\n        t->sum = et;\n        if (t->ch[0])\n         \
    \ t->sum = fn(t->sum, t->ch[0]->sum);\n        if (t->l == t->r)\n          t->sum\
    \ = fn(t->sum, t->val);\n        if (t->ch[1])\n          t->sum = fn(t->sum,\
    \ t->ch[1]->sum);\n        t->sz = size(t->ch[0]) + (t->l == t->r) + size(t->ch[1]);\n\
    \        t->child_edge_connected = (t->ch[0] ? t->ch[0]->child_edge_connected\
    \ : 0) | (t->edge_connected) | (t->ch[1] ? t->ch[1]->child_edge_connected : 0);\n\
    \        t->child_exact = (t->ch[0] ? t->ch[0]->child_exact : 0) | (t->exact)\
    \ | (t->ch[1] ? t->ch[1]->child_exact : 0);\n        return t;\n      }\n    \
    \  void push(np t) {\n        //\u9045\u5EF6\u8A55\u4FA1\u4E88\u5B9A\n      }\n\
    \      void rot(np t, bool b) {\n        np x = t->p, y = x->p;\n        if ((x->ch[1\
    \ - b] = t->ch[b]))\n          t->ch[b]->p = x;\n        t->ch[b] = x, x->p =\
    \ t;\n        update(x);\n        update(t);\n        if ((t->p = y)) {\n    \
    \      if (y->ch[0] == x)\n            y->ch[0] = t;\n          if (y->ch[1] ==\
    \ x)\n            y->ch[1] = t;\n          update(y);\n        }\n      }\n  \
    \    void splay(np t) {\n        push(t);\n        while (!t->is_root()) {\n \
    \         np q = t->p;\n          if (q->is_root()) {\n            push(q), push(t);\n\
    \            rot(t, q->ch[0] == t);\n          } else {\n            np r = q->p;\n\
    \            push(r), push(q), push(t);\n            bool b = r->ch[0] == q;\n\
    \            if (q->ch[1 - b] == t)\n              rot(q, b), rot(t, b);\n   \
    \         else\n              rot(t, 1 - b), rot(t, b);\n          }\n       \
    \ }\n      }\n      void debug(np t) {\n        if (!t)\n          return;\n \
    \       debug(t->ch[0]);\n        cerr << t->l << \"-\" << t->r << \" \";\n  \
    \      debug(t->ch[1]);\n      }\n\n    public:\n      EulerTourTree() {}\n  \
    \    EulerTourTree(int sz) {\n        ptr.resize(sz);\n        for (int i = 0;\
    \ i < sz; i++)\n          ptr[i][i] = new node(i, i);\n      }\n      int size(int\
    \ s) {\n        np t = get_node(s, s);\n        splay(t);\n        return t->sz;\n\
    \      }\n      bool same(int s, int t) {\n        return same(get_node(s, s),\
    \ get_node(t, t));\n      }\n      void set_size(int sz) {\n        ptr.resize(sz);\n\
    \        for (int i = 0; i < sz; i++)\n          ptr[i][i] = new node(i, i);\n\
    \      }\n      void update(int s, T x) {\n        np t = get_node(s, s);\n  \
    \      splay(t);\n        t->val = fn(t->val, x);\n        update(t);\n      }\n\
    \      void edge_update(int s, auto g) {\n        np t = get_node(s, s);\n   \
    \     splay(t);\n        function<void(np)> dfs = [&](np t) {\n          assert(t);\n\
    \          if (t->l < t->r and t->exact) {\n            splay(t);\n          \
    \  t->exact = 0;\n            update(t);\n            g(t->l, t->r);\n       \
    \     return;\n          }\n          if (t->ch[0] and t->ch[0]->child_exact)\n\
    \            dfs(t->ch[0]);\n          else\n            dfs(t->ch[1]);\n    \
    \    };\n        while (t and t->child_exact) {\n          dfs(t);\n         \
    \ splay(t);\n        }\n      }\n      bool try_reconnect(int s, auto f) {\n \
    \       np t = get_node(s, s);\n        splay(t);\n        function<bool(np)>\
    \ dfs = [&](np t) -> bool {\n          assert(t);\n          if (t->edge_connected)\
    \ {\n            splay(t);\n            return f(t->l);\n          }\n       \
    \   if (t->ch[0] and t->ch[0]->child_edge_connected)\n            return dfs(t->ch[0]);\n\
    \          else\n            return dfs(t->ch[1]);\n        };\n        while\
    \ (t->child_edge_connected) {\n          if (dfs(t))\n            return 1;\n\
    \          splay(t);\n        }\n        return 0;\n      }\n      void edge_connected_update(int\
    \ s, bool b) {\n        np t = get_node(s, s);\n        splay(t);\n        t->edge_connected\
    \ = b;\n        update(t);\n      }\n      bool link(int l, int r) {\n       \
    \ if (same(l, r))\n          return 0;\n        merge(reroot(get_node(l, l)),\
    \ get_node(l, r), reroot(get_node(r, r)), get_node(r, l));\n        return 1;\n\
    \      }\n      bool cut(int l, int r) {\n        if (ptr[l].find(r) == ptr[l].end())\n\
    \          return 0;\n        np s, t, u;\n        tie(s, t, u) = split(get_node(l,\
    \ r), get_node(r, l));\n        merge(s, u);\n        np p = ptr[l][r];\n    \
    \    np q = ptr[r][l];\n        ptr[l].erase(r);\n        ptr[r].erase(l);\n \
    \       delete p;\n        delete q;\n        return 1;\n      }\n      T get_sum(int\
    \ p, int v) {\n        cut(p, v);\n        np t = get_node(v, v);\n        splay(t);\n\
    \        T res = t->sum;\n        link(p, v);\n        return res;\n      }\n\
    \      T get_sum(int s) {\n        np t = get_node(s, s);\n        splay(t);\n\
    \        return t->sum;\n      }\n    };\n    int dep = 1;\n    vector<EulerTourTree>\
    \ ett;\n    vector<vector<unordered_set<int>>> edges;\n    int sz;\n\n  public:\n\
    \    DynamicConnectivity(int sz): sz(sz) {\n      ett.emplace_back(sz);\n    \
    \  edges.emplace_back(sz);\n    }\n    bool link(int s, int t) {\n      if (s\
    \ == t)\n        return 0;\n      if (ett[0].link(s, t))\n        return 1;\n\
    \      edges[0][s].insert(t);\n      edges[0][t].insert(s);\n      if (edges[0][s].size()\
    \ == 1)\n        ett[0].edge_connected_update(s, 1);\n      if (edges[0][t].size()\
    \ == 1)\n        ett[0].edge_connected_update(t, 1);\n      return 0;\n    }\n\
    \n    bool same(int s, int t) {\n      return ett[0].same(s, t);\n    }\n\n  \
    \  int size(int s) {\n      return ett[0].size(s);\n    }\n\n    vector<int> get_vertex(int\
    \ s) {\n      return ett[0].vertex_list(s);\n    }\n\n    void update(int s, T\
    \ x) {\n      ett[0].update(s, x);\n    }\n\n    T get_sum(int s) {\n      return\
    \ ett[0].get_sum(s);\n    }\n\n    bool cut(int s, int t) {\n      if (s == t)\n\
    \        return 0;\n      for (int i = 0; i < dep; i++) {\n        edges[i][s].erase(t);\n\
    \        edges[i][t].erase(s);\n        if (edges[i][s].size() == 0)\n       \
    \   ett[i].edge_connected_update(s, 0);\n        if (edges[i][t].size() == 0)\n\
    \          ett[i].edge_connected_update(t, 0);\n      }\n      for (int i = dep\
    \ - 1; i >= 0; i--) {\n        if (ett[i].cut(s, t)) {\n          if (dep - 1\
    \ == i) {\n            dep++;\n            ett.emplace_back(sz);\n           \
    \ edges.emplace_back(sz);\n          }\n          return !try_reconnect(s, t,\
    \ i);\n        }\n      }\n      return 0;\n    }\n\n    bool try_reconnect(int\
    \ s, int t, int k) {\n      for (int i = 0; i < k; i++) {\n        ett[i].cut(s,\
    \ t);\n      }\n      for (int i = k; i >= 0; i--) {\n        if (ett[i].size(s)\
    \ > ett[i].size(t))\n          swap(s, t);\n        auto g = [&](int s, int t)\
    \ {\n          ett[i + 1].link(s, t);\n        };\n        ett[i].edge_update(s,\
    \ g);\n        auto f = [&](int x) -> bool {\n          for (auto itr = edges[i][x].begin();\
    \ itr != edges[i][x].end();) {\n            auto y = *itr;\n            itr =\
    \ edges[i][x].erase(itr);\n            edges[i][y].erase(x);\n            if (edges[i][x].size()\
    \ == 0)\n              ett[i].edge_connected_update(x, 0);\n            if (edges[i][y].size()\
    \ == 0)\n              ett[i].edge_connected_update(y, 0);\n            if (ett[i].same(x,\
    \ y)) {\n              edges[i + 1][x].insert(y);\n              edges[i + 1][y].insert(x);\n\
    \              if (edges[i + 1][x].size() == 1)\n                ett[i + 1].edge_connected_update(x,\
    \ 1);\n              if (edges[i + 1][y].size() == 1)\n                ett[i +\
    \ 1].edge_connected_update(y, 1);\n            } else {\n              for (int\
    \ j = 0; j <= i; j++) {\n                ett[j].link(x, y);\n              }\n\
    \              return 1;\n            }\n          }\n          return 0;\n  \
    \      };\n        if (ett[i].try_reconnect(s, f))\n          return 1;\n    \
    \  }\n      return 0;\n    }\n    constexpr static T et = T();\n    constexpr\
    \ static T fn(T s, T t) {\n      return s + t;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <functional>\n#include\
    \ <iostream>\n#include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  class DynamicConnectivity {\n\
    \    class EulerTourTree {\n    public:\n      struct node;\n      using np =\
    \ node *;\n      using lint = long long;\n      struct node {\n        np ch[2]\
    \ = { nullptr, nullptr };\n        np p = nullptr;\n        int l, r, sz;\n  \
    \      T val = et, sum = et;\n        bool exact;\n        bool child_exact;\n\
    \        bool edge_connected = 0;\n        bool child_edge_connected = 0;\n  \
    \      node() {}\n        node(int l, int r): l(l), r(r), sz(l == r), exact(l\
    \ < r), child_exact(l < r) {}\n        bool is_root() {\n          return !p;\n\
    \        }\n      };\n      vector<unordered_map<int, np>> ptr;\n      np get_node(int\
    \ l, int r) {\n        if (ptr[l].find(r) == ptr[l].end())\n          ptr[l][r]\
    \ = new node(l, r);\n        return ptr[l][r];\n      }\n      np root(np t) {\n\
    \        if (!t)\n          return t;\n        while (t->p)\n          t = t->p;\n\
    \        return t;\n      }\n      bool same(np s, np t) {\n        if (s)\n \
    \         splay(s);\n        if (t)\n          splay(t);\n        return root(s)\
    \ == root(t);\n      }\n      np reroot(np t) {\n        auto s = split(t);\n\
    \        return merge(s.second, s.first);\n      }\n      pair<np, np> split(np\
    \ s) {\n        splay(s);\n        np t = s->ch[0];\n        if (t)\n        \
    \  t->p = nullptr;\n        s->ch[0] = nullptr;\n        return { t, update(s)\
    \ };\n      }\n      pair<np, np> split2(np s) {\n        splay(s);\n        np\
    \ t = s->ch[0];\n        np u = s->ch[1];\n        if (t)\n          t->p = nullptr;\n\
    \        s->ch[0] = nullptr;\n        if (u)\n          u->p = nullptr;\n    \
    \    s->ch[1] = nullptr;\n        return { t, u };\n      }\n      tuple<np, np,\
    \ np> split(np s, np t) {\n        auto u = split2(s);\n        if (same(u.first,\
    \ t)) {\n          auto r = split2(t);\n          return make_tuple(r.first, r.second,\
    \ u.second);\n        } else {\n          auto r = split2(t);\n          return\
    \ make_tuple(u.first, r.first, r.second);\n        }\n      }\n      template\
    \ <typename First, typename... Rest>\n      np merge(First s, Rest... t) {\n \
    \       return merge(s, merge(t...));\n      }\n      np merge(np s, np t) {\n\
    \        if (!s)\n          return t;\n        if (!t)\n          return s;\n\
    \        while (s->ch[1])\n          s = s->ch[1];\n        splay(s);\n      \
    \  s->ch[1] = t;\n        if (t)\n          t->p = s;\n        return update(s);\n\
    \      }\n      int size(np t) {\n        return t ? t->sz : 0;\n      }\n   \
    \   np update(np t) {\n        t->sum = et;\n        if (t->ch[0])\n         \
    \ t->sum = fn(t->sum, t->ch[0]->sum);\n        if (t->l == t->r)\n          t->sum\
    \ = fn(t->sum, t->val);\n        if (t->ch[1])\n          t->sum = fn(t->sum,\
    \ t->ch[1]->sum);\n        t->sz = size(t->ch[0]) + (t->l == t->r) + size(t->ch[1]);\n\
    \        t->child_edge_connected = (t->ch[0] ? t->ch[0]->child_edge_connected\
    \ : 0) | (t->edge_connected) | (t->ch[1] ? t->ch[1]->child_edge_connected : 0);\n\
    \        t->child_exact = (t->ch[0] ? t->ch[0]->child_exact : 0) | (t->exact)\
    \ | (t->ch[1] ? t->ch[1]->child_exact : 0);\n        return t;\n      }\n    \
    \  void push(np t) {\n        //\u9045\u5EF6\u8A55\u4FA1\u4E88\u5B9A\n      }\n\
    \      void rot(np t, bool b) {\n        np x = t->p, y = x->p;\n        if ((x->ch[1\
    \ - b] = t->ch[b]))\n          t->ch[b]->p = x;\n        t->ch[b] = x, x->p =\
    \ t;\n        update(x);\n        update(t);\n        if ((t->p = y)) {\n    \
    \      if (y->ch[0] == x)\n            y->ch[0] = t;\n          if (y->ch[1] ==\
    \ x)\n            y->ch[1] = t;\n          update(y);\n        }\n      }\n  \
    \    void splay(np t) {\n        push(t);\n        while (!t->is_root()) {\n \
    \         np q = t->p;\n          if (q->is_root()) {\n            push(q), push(t);\n\
    \            rot(t, q->ch[0] == t);\n          } else {\n            np r = q->p;\n\
    \            push(r), push(q), push(t);\n            bool b = r->ch[0] == q;\n\
    \            if (q->ch[1 - b] == t)\n              rot(q, b), rot(t, b);\n   \
    \         else\n              rot(t, 1 - b), rot(t, b);\n          }\n       \
    \ }\n      }\n      void debug(np t) {\n        if (!t)\n          return;\n \
    \       debug(t->ch[0]);\n        cerr << t->l << \"-\" << t->r << \" \";\n  \
    \      debug(t->ch[1]);\n      }\n\n    public:\n      EulerTourTree() {}\n  \
    \    EulerTourTree(int sz) {\n        ptr.resize(sz);\n        for (int i = 0;\
    \ i < sz; i++)\n          ptr[i][i] = new node(i, i);\n      }\n      int size(int\
    \ s) {\n        np t = get_node(s, s);\n        splay(t);\n        return t->sz;\n\
    \      }\n      bool same(int s, int t) {\n        return same(get_node(s, s),\
    \ get_node(t, t));\n      }\n      void set_size(int sz) {\n        ptr.resize(sz);\n\
    \        for (int i = 0; i < sz; i++)\n          ptr[i][i] = new node(i, i);\n\
    \      }\n      void update(int s, T x) {\n        np t = get_node(s, s);\n  \
    \      splay(t);\n        t->val = fn(t->val, x);\n        update(t);\n      }\n\
    \      void edge_update(int s, auto g) {\n        np t = get_node(s, s);\n   \
    \     splay(t);\n        function<void(np)> dfs = [&](np t) {\n          assert(t);\n\
    \          if (t->l < t->r and t->exact) {\n            splay(t);\n          \
    \  t->exact = 0;\n            update(t);\n            g(t->l, t->r);\n       \
    \     return;\n          }\n          if (t->ch[0] and t->ch[0]->child_exact)\n\
    \            dfs(t->ch[0]);\n          else\n            dfs(t->ch[1]);\n    \
    \    };\n        while (t and t->child_exact) {\n          dfs(t);\n         \
    \ splay(t);\n        }\n      }\n      bool try_reconnect(int s, auto f) {\n \
    \       np t = get_node(s, s);\n        splay(t);\n        function<bool(np)>\
    \ dfs = [&](np t) -> bool {\n          assert(t);\n          if (t->edge_connected)\
    \ {\n            splay(t);\n            return f(t->l);\n          }\n       \
    \   if (t->ch[0] and t->ch[0]->child_edge_connected)\n            return dfs(t->ch[0]);\n\
    \          else\n            return dfs(t->ch[1]);\n        };\n        while\
    \ (t->child_edge_connected) {\n          if (dfs(t))\n            return 1;\n\
    \          splay(t);\n        }\n        return 0;\n      }\n      void edge_connected_update(int\
    \ s, bool b) {\n        np t = get_node(s, s);\n        splay(t);\n        t->edge_connected\
    \ = b;\n        update(t);\n      }\n      bool link(int l, int r) {\n       \
    \ if (same(l, r))\n          return 0;\n        merge(reroot(get_node(l, l)),\
    \ get_node(l, r), reroot(get_node(r, r)), get_node(r, l));\n        return 1;\n\
    \      }\n      bool cut(int l, int r) {\n        if (ptr[l].find(r) == ptr[l].end())\n\
    \          return 0;\n        np s, t, u;\n        tie(s, t, u) = split(get_node(l,\
    \ r), get_node(r, l));\n        merge(s, u);\n        np p = ptr[l][r];\n    \
    \    np q = ptr[r][l];\n        ptr[l].erase(r);\n        ptr[r].erase(l);\n \
    \       delete p;\n        delete q;\n        return 1;\n      }\n      T get_sum(int\
    \ p, int v) {\n        cut(p, v);\n        np t = get_node(v, v);\n        splay(t);\n\
    \        T res = t->sum;\n        link(p, v);\n        return res;\n      }\n\
    \      T get_sum(int s) {\n        np t = get_node(s, s);\n        splay(t);\n\
    \        return t->sum;\n      }\n    };\n    int dep = 1;\n    vector<EulerTourTree>\
    \ ett;\n    vector<vector<unordered_set<int>>> edges;\n    int sz;\n\n  public:\n\
    \    DynamicConnectivity(int sz): sz(sz) {\n      ett.emplace_back(sz);\n    \
    \  edges.emplace_back(sz);\n    }\n    bool link(int s, int t) {\n      if (s\
    \ == t)\n        return 0;\n      if (ett[0].link(s, t))\n        return 1;\n\
    \      edges[0][s].insert(t);\n      edges[0][t].insert(s);\n      if (edges[0][s].size()\
    \ == 1)\n        ett[0].edge_connected_update(s, 1);\n      if (edges[0][t].size()\
    \ == 1)\n        ett[0].edge_connected_update(t, 1);\n      return 0;\n    }\n\
    \n    bool same(int s, int t) {\n      return ett[0].same(s, t);\n    }\n\n  \
    \  int size(int s) {\n      return ett[0].size(s);\n    }\n\n    vector<int> get_vertex(int\
    \ s) {\n      return ett[0].vertex_list(s);\n    }\n\n    void update(int s, T\
    \ x) {\n      ett[0].update(s, x);\n    }\n\n    T get_sum(int s) {\n      return\
    \ ett[0].get_sum(s);\n    }\n\n    bool cut(int s, int t) {\n      if (s == t)\n\
    \        return 0;\n      for (int i = 0; i < dep; i++) {\n        edges[i][s].erase(t);\n\
    \        edges[i][t].erase(s);\n        if (edges[i][s].size() == 0)\n       \
    \   ett[i].edge_connected_update(s, 0);\n        if (edges[i][t].size() == 0)\n\
    \          ett[i].edge_connected_update(t, 0);\n      }\n      for (int i = dep\
    \ - 1; i >= 0; i--) {\n        if (ett[i].cut(s, t)) {\n          if (dep - 1\
    \ == i) {\n            dep++;\n            ett.emplace_back(sz);\n           \
    \ edges.emplace_back(sz);\n          }\n          return !try_reconnect(s, t,\
    \ i);\n        }\n      }\n      return 0;\n    }\n\n    bool try_reconnect(int\
    \ s, int t, int k) {\n      for (int i = 0; i < k; i++) {\n        ett[i].cut(s,\
    \ t);\n      }\n      for (int i = k; i >= 0; i--) {\n        if (ett[i].size(s)\
    \ > ett[i].size(t))\n          swap(s, t);\n        auto g = [&](int s, int t)\
    \ {\n          ett[i + 1].link(s, t);\n        };\n        ett[i].edge_update(s,\
    \ g);\n        auto f = [&](int x) -> bool {\n          for (auto itr = edges[i][x].begin();\
    \ itr != edges[i][x].end();) {\n            auto y = *itr;\n            itr =\
    \ edges[i][x].erase(itr);\n            edges[i][y].erase(x);\n            if (edges[i][x].size()\
    \ == 0)\n              ett[i].edge_connected_update(x, 0);\n            if (edges[i][y].size()\
    \ == 0)\n              ett[i].edge_connected_update(y, 0);\n            if (ett[i].same(x,\
    \ y)) {\n              edges[i + 1][x].insert(y);\n              edges[i + 1][y].insert(x);\n\
    \              if (edges[i + 1][x].size() == 1)\n                ett[i + 1].edge_connected_update(x,\
    \ 1);\n              if (edges[i + 1][y].size() == 1)\n                ett[i +\
    \ 1].edge_connected_update(y, 1);\n            } else {\n              for (int\
    \ j = 0; j <= i; j++) {\n                ett[j].link(x, y);\n              }\n\
    \              return 1;\n            }\n          }\n          return 0;\n  \
    \      };\n        if (ett[i].try_reconnect(s, f))\n          return 1;\n    \
    \  }\n      return 0;\n    }\n    constexpr static T et = T();\n    constexpr\
    \ static T fn(T s, T t) {\n      return s + t;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn:
  - data-structure/base.hpp
  isVerificationFile: false
  path: data-structure/dynamic-connectivity.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-connectivity.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-connectivity.hpp
- /library/data-structure/dynamic-connectivity.hpp.html
title: data-structure/dynamic-connectivity.hpp
---
