#pragma once

#include "./base.hpp"

#include <vector>

namespace matumoto {
  template <typename ArrayType>
  vector<ArrayType> rotate_cw(const vector<ArrayType> &s) {
    int h = s.size(), w = s[0].size();
    vector<ArrayType> res(w);
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        res[i].push_back(s[h - 1 - j][i]);
      }
    }
    return res;
  }

  template <typename ArrayType>
  vector<ArrayType> rotate_ccw(const vector<ArrayType> &s) {
    int h = s.size(), w = s[0].size();
    vector<ArrayType> res(w);
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        res[i].push_back(s[j][w - 1 - i]);
      }
    }
    return res;
  }
} // namespace matumoto