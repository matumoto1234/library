#pragma once

#include "./base.hpp"

#include <string>

namespace string_library {
  string substr(const string &s, int l, int r) {
    string res = "";
    for (int i = l; i < r; i++) {
      res += s[i];
    }
    return res;
  }
} // namespace string_library