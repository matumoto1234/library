#include <bits/stdc++.h>
using namespace std;

// {{{
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2>
void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < (int)name.size(); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos && !bs.empty() ) bs.pop();
    if ( name[i] == ',' && bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)),
        forward<T2>(rest)...);
  }
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  for ( pair<T1, T2> x : v ) {
    os << "(" << x.first << ", " << x.second << ")"
       << (v.rbegin()->first == x.first ? "" : ", ");
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
  if ( !v.empty() ) {
    os << v.front();
    v.pop();
  }
  while ( !v.empty() ) {
    os << " " << v.front();
    v.pop();
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, stack<T> v) {
  if ( !v.empty() ) {
    os << v.top();
    v.pop();
  }
  while ( !v.empty() ) {
    os << " " << v.top();
    v.pop();
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  bool is_f = true;
  for ( T x : v ) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  bool is_f = true;
  for ( T x : v ) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  bool is_f = true;
  for ( T x : v ) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}

// }}}

// path_query    : op,e,inv
// subtree_query : op,e
// op   : T, T -> T (operation)
// e    : void -> T (identity element)
// inv  : T    -> T (inverse element)
// T is weight type && value type
template <typename T, T (*op)(T, T), T (*e)(), T (*inv)(T)>
class weighted_tree {
private:
  struct sparse_table {
    vector<vector<pair<int, int>>> st;
    vector<int> lookup;

    sparse_table() {}

    void build(const vector<pair<int, int>> &v) {
      int b = 0;
      while ( (1 << b) <= (int)v.size() )
        ++b;
      st.assign(b, vector<pair<int, int>>(1 << b));
      for ( int i = 0; i < (int)v.size(); i++ ) {
        st[0][i] = v[i];
      }
      for ( int i = 1; i < b; i++ ) {
        for ( int j = 0; j + (1 << i) <= (1 << b); j++ ) {
          st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
      lookup.resize(v.size() + 1);
      for ( int i = 2; i < (int)lookup.size(); i++ ) {
        lookup[i] = lookup[i >> 1] + 1;
      }
    }

    inline pair<int, int> query(int l, int r) {
      int b = lookup[r - l];
      return min(st[b][l], st[b][r - (1 << b)]);
    }
  };

  class segment_tree {
  private:
    int n;
    vector<T> dat;

    T search(int l, int r) {
      T vl = e(), vr = e();
      l += n, r += n;
      while ( l < r ) {
        if ( l & 1 ) vl = op(vl, dat[l++]);
        if ( r & 1 ) vr = op(vr, dat[--r]);
        l >>= 1, r >>= 1;
      }
      return op(vl, vr);
    }

  public:
    segment_tree() {}

    void assign(int _n) {
      n = 1;
      while ( n < _n ) {
        n <<= 1;
      }
      dat.assign(2 * n, e());
    }

    T get(int i) { return dat[i + n]; }

    void set(int i, T key) {
      i += n;
      dat[i] = key;
      while ( i > 0 ) {
        i >>= 1;
        dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);
      }
    }

    void add(int i, T key) { set(i, get(i) + key); }

    T prod(int l, int r) { return search(l, r); }

    T all_prod() { return n != 0 ? dat[0] : e(); }
  };

  sparse_table min_dep_idx;
  segment_tree dat;
  vector<int> in, out, dep, par, dia_to, edge_table;
  pair<T, int> dia;
  vector<vector<int>> doubling_par;
  vector<vector<pair<int, T>>> G;
  vector<T> dat;
  const int LOG;

  void dfs(int v, int &time, int depth) {
    in[v] = time;
    dep[time] = depth;
    edge_table[time++] = v;
    for ( auto to : G[v] ) {
      if ( in[to] != -1 ) continue;
      par[to] = v;
      dfs(to, time, depth + 1);
    }
    out[v] = time;
    dep[time] = depth - 1;
    edge_table[time++] = -v;
  }

  pair<T, int> dfs_diameter(int v, int p) {
    pair<T, int> res(0, v);
    for ( auto [to, cost] : G[v] ) {
      if ( to == par ) continue;
      auto [ncost, u] = dfs_diameter(to, v);
      if ( res < make_pair(ncost + cost, u) ) {
        res = make_pair(ncost + cost);
        dia_to[v] = to;
      }
    }
    return res;
  }

  // min({ x | 2^x > n })
  int log_two(int n) {
    int x = 1;
    while ( (1 << x) <= n ) {
      x++;
    }
    return x;
  }

public:
  weighted_tree(int n) : G(n), dat(n), LOG(log_two(n)), dia(-1) {
    dat.assign(n);
  }

  void add_edge(int from, int to, T cost = 1) { G[from].emplace_back(to, cost); }

  T path_query(int v) { return dat.prod(0, in[v] + 1); }

  // O(log N)
  T path_query(int u, int v) {
    T res = op(path_query(u), path_query(v));
    res = op(res, inv(path_query(lca(u, v))));
    res = op(res, inv(path_query(lca(u, v))));
    return res;
  }

  // O(log N)
  T subtree_query(int v) { return dat.prod(in[v], out[v]); }

  // O(Nlog N)
  void build(int s) {
    int n = G.size();

    dia_to.assign(n, -1);
    dia = dfs_diameter(dfs_diameter(s, -1).second, -1);

    in.assign(n, -1);
    out.assign(n, -1);
    par.assign(n, 0);
    dep.assign(2 * n, 0);
    edge_table.assign(2 * n, -1);
    int time = 0;
    dfs(s, time, 0);
    dep.back() = s;

    // build doubling parent
    doubling_par.assign(LOG, vector<int>(n, -1));
    for ( int i = 0; i < n; i++ ) {
      doubling_par[0][i] = par[i];
    }
    for ( int k = 0; k < LOG - 1; k++ ) {
      for ( int i = 0; i < n; i++ ) {
        if ( doubling_par[k][i] == -1 ) {
          doubling_par[k + 1][i] = -1;
          continue;
        }
        doubling_par[k + 1][i] = doubling_par[k][doubling_par[k][i]];
      }
    }

    // build sparse table
    vector<pair<int, int>> dep_idx(dep.size());
    for ( int i = 0; i < (int)dep.size(); i++ ) {
      auto &[depth, idx] = dep_idx[i];
      depth = dep[i];
      idx = i;
    }
    min_dep_idx.build(dep_idx);
  }

  // O(1)
  T diameter() { return dia.first; }

  // O(N)
  vector<int> diameter_path() {
    int v = dia.second;
    vector<int> path;
    path.reserve(dia.first);
    while ( v != -1 ) {
      path.emplace_back(v);
      v = dia_to[v];
    }
    return path;
  }

  // O(1)
  bool in_subtree(int subroot, int v) {
    return in[subroot] < in[v] and out[v] < out[subroot];
  }

  // O(1) : lowest common ancestor
  int lca(int u, int v) {
    int idx =
        min_dep_idx.query(min(in[u], in[v]), max(in[u], in[v]) + 1).second;
    int res = edge_table[idx];
    if ( res < 0 ) res = par[-res];
    return res;
  }

  // O(log N) : level ancestor
  int la(int v, int depth) {
    int anc = v;
    for ( int i = 0; i < LOG; i++ ) {
      if ( depth >> i & 1 ) anc = doubling_par[i][anc];
    }
    return anc;
  }

  // O(1)
  int depth(int v) { return dep[in[v]]; }

  // O(1)
  int distance(int u, int v) {
    return depth(u) + depth(v) - 2 * depth(lca(u, v));
  }

  // O(1) : from v to root move k step
  int up(int v, int k) { return la(v, depth(v) - k); }

  // O(1) : from u to v move k step
  int next(int u, int v, int k = 1) {
    if ( k <= distance(u, lca(u, v)) ) return up(u, k);
    return up(v, distance(v, lca(u, v)) - k);
  }
};

int op(int a, int b) {
  return a + b;
}

int e() {
  return 0;
}

int inv(int a) {
  return -a;
}

// AOJ_LCA
int main() {
  int n;
  cin >> n;
  weighted_tree<int, op, e, inv> t(n);
  for ( int i = 0; i < n - 1; i++ ) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    t.add_edge(a, b);
    t.add_edge(b, a);
  }

  t.build(0);

  int m;
  cin >> m;
  vector<pair<int, int>> uvs(m);
  for ( auto &[u, v] : uvs ) {
    cin >> u >> v;
    u--, v--;
  }
}