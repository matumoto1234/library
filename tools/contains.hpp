#pragma once

#include "./has-find.hpp"

#include <algorithm>
#include <iterator>

namespace tools_library {
  template <typename Container, typename T>
  bool contains(const Container &container, const T &x) {
    if constexpr (has_find_v<Container, T>) {
      return container.find(x) != end(container);
    } else {
      return find(begin(container), end(container), x) != end(container);
    }
  }
} // namespace tools_library