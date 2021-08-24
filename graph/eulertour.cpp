#include <bits/stdc++.h>
using namespace std;

class euler_tour {
private:
  vector<int> in, out, depth, parents, time_table;
  vector<vector<int>> G;

  void dfs(int v, int &time, int dep) {
    in[v] = time;
    depth[v] = dep;
    time_table[time] = v;
    time++;
    for ( auto to : G[v] ) {
      if ( in[to] != -1 ) continue;
      parents[to] = v;
      dfs(to, time, dep + 1);
    }
    out[v] = time;
    time_table[time] = -v;
    time++;
  }

public:
  euler_tour(int n) : G(n) {}

  void add_edge(int from, int to) { G[from].emplace_back(to); }

  void build(int s) {
    in.assign(G.size(), -1);
    out.assign(G.size(), -1);
    depth.assign(G.size(), -1);
    parents.assign(G.size(), -1);
    time_table.assign(2 * G.size(), -1);

    int time = 0;
    dfs(s, time, 0);
  }

  // time_table:[first, second), vertex_table:[first, second]
  pair<int, int> subtree(int v) { return make_pair(in[v], out[v]); }

  // O(N)
  int lca(int u, int v) {
    int mindep = G.size();
    int res = 0;
    for ( int i = in[u]; i <= in[v]; i++ ) {
      if ( mindep > depth[i] ) {
        mindep = depth[i];
        res = time_table[i];
        if ( res < 0 ) res = parents[i];
      }
    }
    return res;
  }

  vector<int> in_time() { return in; }
  vector<int> out_time() { return out; }
  vector<int> depths() { return depth; }
  vector<int> parent() { return parents; }
  vector<int> table() { return time_table; }

  vector<int> vertex_table() {
    vector<int> res = time_table;
    for ( auto &v : res ) {
      if ( v < 0 ) v = parents[v];
    }
    // 半開区間->閉区間の誤差
    res.pop_back();
    return res;
  }

  int operator[](int k) { return time_table[k]; }
};

int main() {
}