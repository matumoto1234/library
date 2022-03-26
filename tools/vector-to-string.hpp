#pragma once

#include "./base.hpp"

#include <string>
#include <vector>

namespace tools_library {
  template <typename T>
  string vector_to_string(const vector<T> &vs, const string &sep = " ") {
    stringstream ss;
    for (int i = 0; i < static_cast<int>(vs.size()); i++) {
      if (i)
        ss << sep;
      ss << vs[i];
    }
    return ss.str();
  }
} // namespace tools_library