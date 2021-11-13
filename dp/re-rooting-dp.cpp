#include <bits/stdc++.h>
using namespace std;

template <typename T, typename CostType>
class ReRootingDP {
private:
  vector<vector<pair<int, CostType>>> g;
  vector<vector<int>> seen_idx;
  vector<vector<T>> ch_tree;
  vector<int> pars, deps, sizs, order;
  vector<T> results;

  T identity;
  function<T(T, T)> merge;
  function<T(T, int, ReRootingDP<T, CostType> &)> add_node;

  void dfs(int v, int par, int &idx) {
    order[idx++] = v;
    pars[v] = par;
    deps[v] = par == -1 ? 0 : deps[par] + 1;
    for (auto [to, ignore]: g[v]) {
      if (to == par) continue;
      dfs(to, v, idx);
    }
    if (par != -1) sizs[par] = ++sizs[v];
  }

  void post_order() {
    for (int i = order.size() - 1; i >= 1; i--) {
      int v = order[i];
      int par = pars[v];
      int par_idx = -1;
      T accum = identity;
      for (int j = 0; j < static_cast<int>(g[v].size()); j++) {
        int to = g[v][j].first;
        if (to == par) {
          par_idx = j;
          continue;
        }
        accum = merge(accum, ch_tree[v][j]);
      }
      if (par_idx != -1) { ch_tree[par][seen_idx[v][par_idx]] = add_node(accum, v, *this); }
    }
  }

  void pre_order() {
    for (auto v: order) {
      int adj_cnt = g[v].size();
      vector<T> accum_back(adj_cnt);
      accum_back.back() = identity;
      for (int j = adj_cnt - 1; j >= 1; j--) {
        accum_back[j - 1] = merge(accum_back[j], ch_tree[v][j]);
      }
      T accum_front = identity;
      for (int j = 0; j < adj_cnt; j++) {
        T res = add_node(merge(accum_front, accum_back[j]), v, *this);
        ch_tree[g[v][j].first][seen_idx[v][j]] = res;
        accum_front = merge(accum_front, ch_tree[v][j]);
      }
      results[v] = add_node(accum_front, v, *this);
    }
  }

public:
  ReRootingDP(int n, T id, function<T(T, T)> f1, function<T(T, int, ReRootingDP<T, CostType> &)> f2): g(n), seen_idx(n) {
    identity = id;
    merge = f1;
    add_node = f2;
  }

  void add_edge(int from, int to, CostType cost) {
    g[from].emplace_back(to, cost);
    seen_idx[to].emplace_back(g[from].size() - 1);
  }

  void build(int root) {
    pars.assign(g.size(), -1);
    deps.assign(g.size(), -1);
    sizs.assign(g.size(), 0);
    order.assign(g.size(), -1);
    results.assign(g.size(), identity);
    ch_tree.resize(g.size());
    for (int i = 0; i < static_cast<int>(g.size()); i++) {
      ch_tree[i].assign(g[i].size(), identity);
    }
    int idx = 0;
    dfs(root, -1, idx);
    post_order();
    pre_order();
  }

  int size(int v) { return sizs[v]; }
  int depth(int v) { return deps[v]; }
  int parent(int v) { return pars[v]; }
  T query(int v) { return results[v]; }
  T operator[](int v) { return results[v]; }
};

using ll = long long;
using Pll = pair<ll, ll>;

Pll e() {
  return make_pair<ll, ll>(0, 0);
}

Pll op(Pll a, Pll b) {
  return make_pair<ll, ll>(a.first + b.first, a.second + b.second);
}

Pll add_node(Pll res, int v, ReRootingDP<Pll, ll> &tree) {
  auto [child_result, mydistance] = res;
  return make_pair<ll, ll>(child_result + mydistance, mydistance + 1);
}

// ABC220-F
int main() {
  int n;
  cin >> n;

  ReRootingDP<Pll, ll> tree(n, e(), op, add_node);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    tree.add_edge(u, v, 1);
    tree.add_edge(v, u, 1);
  }

  tree.build(0);

  for (int i = 0; i < n; i++) {
    cout << tree[i].first << endl;
  }
}