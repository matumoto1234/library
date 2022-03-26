#pragma once

#include "./base.hpp"

#include <cassert>
#include <vector>

namespace data_structure_library {
  // 1-indexed
  template <typename T>
  class FenwickTree2D {
  private:
    int H, W;
    vector<vector<T>> dat;

    // 1<=i<=y 1<=j<=x
    T internal_sum(int y, int x) {
      T res = 0;
      for (int i = y; i > 0; i -= (i & -i)) {
        for (int j = x; j > 0; j -= (j & -j)) {
          res += dat[i][j];
        }
      }
      return res;
    }

  public:
    FenwickTree2D() {}
    FenwickTree2D(int H_, int W_) {
      init(H_, W_);
    }
    void init(int H_, int W_) {
      H = H_ + 1;
      W = W_ + 1;
      dat.assign(H, vector<T>(W, 0));
    }

    // {h,w} += x
    void add(int h, int w, T x) {
      assert(1 <= h and h <= H and 1 <= w and w <= W);
      for (int i = h; i < H; i += (i & -i)) {
        for (int j = w; j < W; j += (j & -j)) {
          dat[i][j] += x;
        }
      }
    }

    // [{sy,sx}, {gy,gx})
    T sum(int sy, int sx, int gy, int gx) {
      assert(1 <= sy and sy <= H and 1 <= sx and sx <= W and 2 <= gy and gy <= H + 1 and 2 <= gx and gx <= W + 1);
      return internal_sum(gy - 1, gx - 1) - internal_sum(gy - 1, sx - 1) - internal_sum(sy - 1, gx - 1) + internal_sum(sy - 1, sx - 1);
    }

    T get(int y, int x) {
      return sum(y, x, y + 1, x + 1);
    }
  };
} // namespace data_structure_library