#pragma once

#include "./base.hpp"

#include <vector>
#include <type_traits>

namespace tools {
  template <typename Iterator>
  auto runlength(Iterator first, Iterator last) {
    vector<pair<remove_reference_t<decltype(*first)>, int>> res;
    for (auto it = first; it != last; it++) {
      if (res.empty() or res.back().first != *it) res.emplace_back(*it, 0);
      res.back().second++;
    }
    return res;
  }
} // namespace tools