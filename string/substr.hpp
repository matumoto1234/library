#pragma once

#include "./base.hpp"

#include <string>

namespace matumoto {
  string substr(const string &s, int l, int r) {
    string res = "";
    for (int i = l; i < r; i++) {
      res += s[i];
    }
    return res;
  }
} // namespace matumoto