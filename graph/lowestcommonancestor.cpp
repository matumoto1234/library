#include <bits/stdc++.h>
using namespace std;

class lowest_common_ancestor {
private:
  int h;
  vector<vector<int>> G, par;
  vector<int> dep;

  void dfs(int v, int p, int d) {
    par[0][v] = p;
    dep[v] = d;
    for (int u: G[v])
      if (u != p) dfs(u, v, d + 1);
  }

public:
  lowest_common_ancestor(int n): G(n), dep(n) {
    h = 1;
    while ((1 << h) <= n)
      h++;
    par.assign(h, vector<int>(n, -1));
  }

  void add_edge(int u, int v) {
    G[u].emplace_back(v);
    // G[v].emplace_back(u);
  }

  void build(int root = 0) {
    int n = G.size();
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < h; k++)
      for (int v = 0; v < n; v++)
        if (~par[k][v]) par[k + 1][v] = par[k][par[k][v]];
  }

  int query(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int k = 0; k < h; k++)
      if ((dep[v] - dep[u]) >> k & 1) v = par[k][v];

    if (u == v) return u;

    for (int k = h - 1; k >= 0; k--)
      if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];

    return par[0][u];
  }

  int distance(int u, int v) { return dep[u] + dep[v] - dep[query(u, v)] * 2; }
};

int main() {
  int n;
  cin >> n;
  lowest_common_ancestor lca(n);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      c--;
      lca.add_edge(i, c);
    }
  }

  lca.build();

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << lca.query(u, v) << endl;
  }
}