#pragma once

#include "./has-find.hpp"

namespace tools {
  template <typename Container, typename T>
  bool contains(const Container &container, const T &x) {
    if constexpr (HasFind<Container, T>::value) {
      return container.find(x) != end(container);
    } else {
      return find(begin(container), end(container), x) != end(container);
    }
  }
} // namespace tools