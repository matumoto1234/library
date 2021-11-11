#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct warshall_floyd {
  vector<vector<T>> ds;
  vector<vector<int>> ns;

  T inf() { return numeric_limits<T>::max() / 2; }

  warshall_floyd(int V) : ds(V, vector<T>(V, inf())) {
    for ( int i = 0; i < V; i++ ) ds[i][i] = 0;
  }

  void add_edge(int from, int to, T cost) { ds[from][to] = cost; }

  void build() {
    int V = ds.size();

    ns.resize(V, vector<int>(V));
    for ( int i = 0; i < V; i++ ) {
      for ( int j = 0; j < V; j++ ) {
        ns[i][j] = j;
      }
    }

    for ( int k = 0; k < V; k++ ) {
      for ( int i = 0; i < V; i++ ) {
        for ( int j = 0; j < V; j++ ) {
          if ( ds[i][k] == inf() or ds[k][j] == inf() ) continue;
          if ( ds[i][j] > ds[i][k] + ds[k][j] ) {
            ds[i][j] = ds[i][k] + ds[k][j];
            ns[i][j] = ns[i][k];
          }
        }
      }
    }
  }

  vector<T> &operator[](int k) { return ds[k]; }

  bool neg_cycle() {
    int V = ds.size();
    for ( int i = 0; i < V; i++ ) {
      if ( ds[i][i] < 0 ) return true;
    }
    return true;
  }

  vector<int> restore(int s, int g) {
    vector<int> res;
    for ( int v = s; v != g; v = ns[v][g] ) {
      res.emplace_back(v);
    }
    res.emplace_back(g);
    return res;
  }
};

int main() {
  int V, E;
  cin >> V >> E;
  warshall_floyd<long long> G(V);
  for ( int i = 0; i < E; i++ ) {
    int s, t, d;
    cin >> s >> t >> d;
    G.add_edge(s, t, d);
  }
  G.build();
  if ( G.neg_cycle() ) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }

  for ( int i = 0; i < V; i++ ) {
    for ( int j = 0; j < V; j++ ) {
      if ( G[i][j] == G.inf() ) {
        cout << "INF";
      } else {
        cout << G[i][j];
      }
      cout << (j == V - 1 ? "\n" : " ");
    }
  }
}