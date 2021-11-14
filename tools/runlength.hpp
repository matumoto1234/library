#pragma once

#include "./base.hpp"

#include <vector>

namespace tools {
  template <typename iter>
  auto runlength(iter first, iter last) {
    vector<pair<decltype(*first), int>> res;
    for (auto it = first; it != last; it++) {
      if (res.empty() or res.back().first != *it) res.emplace_back(*it, 0);
      res.back().second++;
    }
    return res;
  }
} // namespace tools