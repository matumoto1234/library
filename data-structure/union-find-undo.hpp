#pragma once

#include "./base.hpp"

#include <map>
#include <numeric>
#include <stack>
#include <tuple>
#include <vector>

namespace data_structure {
  // 経路圧縮なし
  class UnionFindUndo {
  private:
    int grp_cnt, merge_cnt;
    vector<int> siz, par;
    stack<tuple<int, int, int>> history;

  public:
    UnionFindUndo(int N): grp_cnt(N), merge_cnt(0), siz(N, 1), par(N) { iota(par.begin(), par.end(), 0); }

    // 根（そのグループの識別番号）
    int root(int x) {
      if (x == par[x]) return x;
      return root(par[x]);
    }

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
      history.emplace(make_tuple(x, par[x], siz[x]));
      history.emplace(make_tuple(y, par[y], siz[y]));
      siz[x] += siz[y];
      par[y] = x;
      grp_cnt--;
      merge_cnt++;
      return true;
    }

    bool undo() {
      if (history.empty()) return false;
      auto [x, x_par, x_siz] = history.top();
      history.pop();
      auto [y, y_par, y_siz] = history.top();
      history.pop();

      par[x] = x_par;
      siz[x] = x_siz;
      par[y] = y_par;
      siz[y] = y_siz;
      return true;
    }

    void clear_history() {
      while (!history.empty()) {
        history.pop();
      }
    }

    void all_undo() {
      while (undo()) {}
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
    // 2つのunion_findでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
    vector<int> connect_count(UnionFindUndo tree) {
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

} // namespace data_structure