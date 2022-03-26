#pragma once

#include "./base.hpp"

#include <vector>

// WIP

namespace math_library {
  template <typename T>
  struct matrix {
    vector<vector<T>> dat;

    matrix(int r, int c): dat(r, vector<T>(c, 0)) {}
    matrix(vector<vector<T>> _dat): dat(_dat) {}

    size_t size() const {
      return dat.size();
    }
    bool empty() const {
      return dat.empty();
    }
  };

  long long fibonacci(long long n) {
    long long f0 = 1, f1 = 1;
    // {(1,1),(1,0)}


    // if ( p <= 1 ) return 0;
    // if ( p == 0 ) p = numeric_limits<T>::max();
    // T res = 1;
    // while ( e > 0 ) {
    //   if ( e & 1 ) res = (res * a) % p;
    //   a = (a * a) % p;
    //   e >>= 1;
    // }
    // return res;
  }
} // namespace math_library