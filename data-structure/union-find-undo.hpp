#pragma once

#include "./base.hpp"

#include <map>
#include <numeric>
#include <stack>
#include <tuple>
#include <vector>

namespace data_structure_library {
  // 経路圧縮なし
  class UnionFindUndo {
  private:
    // number of vertices
    int n_;

    vector<int> sizes_, parents_;

    // <index, parent(index), size(index)>
    stack<tuple<int, int, int>> history_;

  public:
    UnionFindUndo(int N): sizes_(N, 1), parents_(N) {
      iota(parents_.begin(), parents_.end(), 0);
    }

    // 根（そのグループの識別番号）
    int root(int x) {
      if (x == parents_[x])
        return x;
      return root(parents_[x]);
    }

    int size(int x) {
      return sizes_[root(x)];
    }

    bool same(int x, int y) {
      return root(x) == root(y);
    }

    // size(x) < size(y): -1
    // not merged:         0
    // size(x) > size(y): +1
    int merge(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y)
        return 0;

      int result = +1;
      if (sizes_[x] < sizes_[y]) {
        swap(x, y);
        result = -1;
      }

      history_.emplace(tuple(x, parents_[x], sizes_[x]));
      history_.emplace(tuple(y, parents_[y], sizes_[y]));
      sizes_[x] += sizes_[y];
      parents_[y] = x;
      return result;
    }

    bool undo() {
      if (history_.empty())
        return false;

      auto [x, x_parent, x_size] = history_.top();
      history_.pop();
      auto [y, y_parent, y_size] = history_.top();
      history_.pop();

      parents_[x] = x_parent;
      sizes_[x] = x_size;
      parents_[y] = y_parent;
      sizes_[y] = y_size;
      return true;
    }

    void clear_history() {
      while (not history_.empty()) {
        history_.pop();
      }
    }

    void all_undo() {
      while (undo()) {}
    }

    // Θ(N log(N))
    vector<vector<int>> groups() {
      vector<vector<int>> grps(n_);
      for (int i = 0; i < n_; i++) {
        grps[root(i)].emplace_back(i);
      }

      vector<vector<int>> res;
      for (int i = 0; i < n_; i++) {
        if (grps[i].empty())
          continue;
        res.emplace_back(grps[i]);
      }
      return res;
    }
  };
} // namespace data_structure_library
