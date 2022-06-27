#pragma once

#include "./base.hpp"

#include <numeric>
#include <vector>

namespace data_structure_library {
  class UnionFind {
    // number of vertices
    int n_;

    vector<int> sizes_, parents_;

  public:
    UnionFind(int n): n_(n), sizes_(n, 1), parents_(n) {
      iota(parents_.begin(), parents_.end(), 0);
    }

    // 根（そのグループの識別番号）
    int root(int x) {
      if (x == parents_[x])
        return x;
      return parents_[x] = root(parents_[x]);
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

      sizes_[x] += sizes_[y];
      parents_[y] = x;

      return result;
    }

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
