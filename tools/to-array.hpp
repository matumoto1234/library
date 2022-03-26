#pragma once

#include "./base.hpp"

#include <array>
#include <vector>

namespace tools_library {
  template <typename T, size_t length>
  array<T, length> to_array(const vector<T> &vs) {
    array<T, length> res;
    for (int i = 0; i < (int)length; i++) {
      res[i] = vs[i];
    }
    return res;
  }
} // namespace tools_library