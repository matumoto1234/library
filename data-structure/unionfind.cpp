#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct union_find {
  int cnt;
  vector<int> siz, par;
  union_find(int N) : cnt(N), siz(N, 1), par(N) {
    iota(par.begin(), par.end(), 0);
  }

  int root(int x) {
    if ( x == par[x] ) return x;
    return par[x] = root(par[x]);
  }

  int group_count() { return cnt; }

  int size(int x) { return siz[root(x)]; }

  bool same(int x, int y) { return root(x) == root(y); }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if ( x == y ) return;
    if ( siz[x] < siz[y] ) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    cnt--;
  }

  // Θ(NlogN)
  // 2つのunion_findでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
  vector<int> connect_count(union_find tree) {
    map<pair<int, int>, int> mp;

    int N = par.size();
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      mp[p]++;
    }

    vector<int> res(N);
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      res[i] = mp[p];
    }
    return res;
  }
};