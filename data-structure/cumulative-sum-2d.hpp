#pragma once

#include "./base.hpp"

#include <vector>

namespace data_structure {
  template <typename T>
  struct CumulativeSum2D {
    vector<vector<T>> data;
    CumulativeSum2D(int H, int W): data(H + 1, vector<T>(W + 1, 0)) {}
    CumulativeSum2D(const vector<vector<T>> &vs): data(vs) {}

    void set(int y, int x, T v) { data[y + 1][x + 1] = v; }

    void build() {
      for (int i = 1; i < static_cast<int>(data.size()); i++) {
        for (int j = 1; j < static_cast<int>(data[i].size()); j++) {
          data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
        }
      }
    }

    // [ (sy,sx), (gy,gx) )
    T query(int sy, int sx, int gy, int gx) { return data[gy][gx] - data[gy][sx] - data[sy][gx] + data[sy][sx]; }
  };
} // namespace data_structure