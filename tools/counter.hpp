#pragma once

#include "./base.hpp"

#include <map>

namespace tools {
  template <typename Iterator>
  auto counter(Iterator first, Iterator last) {
    using T = remove_reference_t<decltype(*first)>;
    map<T, int> res;
    for (auto it = first; it != last; it++) {
      T value = *it;
      res[value]++;
    }
    return res;
  }
} // namespace tools