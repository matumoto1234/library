#include <bits/stdc++.h>
using namespace std;

template <typename T>
class UnionFind {
  int grp_cnt, merge_cnt;
  vector<int> siz, par;
  vector<T> val;

public:
  UnionFind(int N): grp_cnt(N), merge_cnt(0), siz(N, 1), par(N), val(N, 0) { iota(par.begin(), par.end(), 0); }
  UnionFind(int N, T init): grp_cnt(N), merge_cnt(0), siz(N, 1), par(N), val(N, init) { iota(par.begin(), par.end(), 0); }

  // 根（そのグループの識別番号）
  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
  }

  T root_value(int x) { return val[root(x)]; }

  void set_root_value(int x, T v) { val[root(x)] = v; }

  // 連結成分の個数
  int group_count() { return grp_cnt; }

  int merge_count() { return merge_cnt; }

  int size(int x) { return siz[root(x)]; }

  bool same(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    grp_cnt--;
    merge_cnt++;
    if (vals[x] == -1) {
      vals[x] = vals[y];
    } else {
      vals[y] = vals[x];
    }
    return true;
  }

  // Θ(N)
  vector<vector<int>> groups() {
    int n = par.size();
    vector<vector<int>> grps(n);
    for (int i = 0; i < n; i++) {
      grps[root(i)].emplace_back(i);
    }
    vector<vector<int>> res;
    res.reserve(group_count());
    for (int i = 0; i < n; i++) {
      if (grps[i].empty()) continue;
      res.emplace_back(grps[i]);
    }
    return res;
  }

  // Θ(NlogN)
  // 2つのUnionFindでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
  vector<int> connect_count(UnionFind tree) {
    map<pair<int, int>, int> mp;

    int n = par.size();
    for (int i = 0; i < n; i++) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      mp[p]++;
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      res[i] = mp[p];
    }
    return res;
  }
};