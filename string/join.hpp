#pragma once

#include "./base.hpp"

#include <string>
#include <vector>

namespace matumoto {
  string join(const vector<string> &strs, const string &sep) {
    string res = "";
    for (int i = 0; i < static_cast<int>(strs.size()); i++) {
      if (i)
        res += sep;
      res += strs[i];
    }
    return res;
  }
} // namespace matumoto