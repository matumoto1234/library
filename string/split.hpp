#pragma once

#include "./base.hpp"

#include <string>
#include <vector>

namespace matumoto {
  vector<string> split(const string &str, const string &sep, const int &max_split = INT32_MAX) {
    vector<string> res;
    string t = "";
    int cnt_split = 0;
    for (auto c: str) {
      if (sep.find(c) == string::npos or cnt_split >= max_split) {
        t += c;
        continue;
      }
      res.emplace_back(t);
      t = "";
      cnt_split++;
    }
    if (t != "")
      res.emplace_back(t);
    return res;
  }
} // namespace matumoto