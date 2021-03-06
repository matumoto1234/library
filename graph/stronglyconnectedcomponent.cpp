#include <bits/stdc++.h>
using namespace std;

class strongly_connected_component
{
private:
  // sccは強連結成分ごとの集合
  vector<vector<int>> G, rG, scc;
  vector<int> groups, post_order;
  vector<bool> arrived;
  vector<pair<int, int>> edges;
  int cnt;

  void dfs(int idx) {
    arrived[idx] = true;
    for ( int to : G[idx] ) {
      if ( arrived[to] ) continue;
      dfs(to);
    }
    post_order.emplace_back(idx);
  }

  void rdfs(int idx, int num) {
    arrived[idx] = true;
    groups[idx] = num;
    for ( int to : rG[idx] ) {
      if ( arrived[to] ) continue;
      rdfs(to, num);
    }
  }

public:
  strongly_connected_component(int V) : G(V), rG(V) {}

  void add_edge(int from, int to) {
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
    edges.emplace_back(from, to);
  }

  void build() {
    int V = G.size();
    arrived.assign(V, false);

    for ( int i = 0; i < V; i++ ) {
      if ( arrived[i] ) continue;
      dfs(i);
    }

    cnt = 0;
    groups.assign(V, 0);
    arrived.assign(V, false);

    for ( int i = V - 1; i >= 0; i-- ) {
      int idx = post_order[i];
      if ( arrived[idx] ) continue;
      rdfs(idx, cnt);
      cnt++;
    }

    for ( int i = 0; i < V; i++ ) {
      scc[groups[i]].emplace_back(i);
    }
  }

  // 強連結成分をトポロジカルソートしたもの
  vector<vector<int>> topological_sort() {
    vector<vector<int>> graph(cnt);
    vector<int> in_degree(cnt);
    for ( int i = 0; i < (int)edges.size(); i++ ) {
      auto [from, to] = edges[i];
      if ( same(from, to) ) continue;
      graph[groups[from]].emplace_back(groups[to]);
      in_degree[groups[to]]++;
    }

    queue<int> q;
    for ( int i = 0; i < cnt; i++ ) {
      if ( in_degree[i] == 0 ) q.push(i);
    }

    vector<vector<int>> res;
    while ( !q.empty() ) {
      int v = q.front();
      q.pop();
      res.emplace_back(scc[v]);
      for ( int to : graph[v] ) {
        in_degree[to]--;
        if ( in_degree[to] == 0 ) q.push(to);
      }
    }

    return res;
  }

  int size() { return cnt; }

  bool same(int a, int b) { return groups[a] == groups[b]; }

  int operator[](int k) { return groups[k]; }
};

int main() {
  int V, E;
  cin >> V >> E;

  strongly_connected_component G(V);
  for ( int i = 0; i < E; i++ ) {
    int s, t;
    cin >> s >> t;
    G.add_edge(s, t);
  }

  G.build();

  int q;
  cin >> q;
  for ( int i = 0; i < q; i++ ) {
    int a, b;
    cin >> a >> b;
    cout << (int)(G[a] == G[b]) << '\n';
  }
}