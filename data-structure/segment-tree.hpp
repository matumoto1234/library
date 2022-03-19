#pragma once

#include "./base.hpp"

#include <vector>

namespace library_data_structure {
  // verify:AOJ_DSL_2_A
  template <typename T, T (*op)(T, T), T (*e)()>
  class SegmentTree {
  private:
    int n;
    vector<T> data;

    T search(int l, int r) {
      T vl = e(), vr = e();
      l += n, r += n;
      while (l < r) {
        if (l & 1)
          vl = op(vl, data[l++]);
        if (r & 1)
          vr = op(vr, data[--r]);
        l >>= 1, r >>= 1;
      }
      return op(vl, vr);
    }

  public:
    SegmentTree() {}
    SegmentTree(int _n) { assign(_n); }

    void assign(int _n) {
      n = 1;
      while (n < _n) {
        n <<= 1;
      }
      data.assign(2 * n, e());
    }

    T get(int i) { return data[i + n]; }

    void set(int i, T key) {
      i += n;
      data[i] = key;
      while (i > 0) {
        i >>= 1;
        data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
      }
    }

    // [l, r)
    T prod(int l, int r) { return search(l, r); }

    T all_prod() { return n != 0 ? data[0] : e(); }
  };
} // namespace library_data_structure