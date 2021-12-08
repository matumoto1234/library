#pragma once

#include "./has-iterator.hpp"

namespace tools {
  template <typename Container, typename T, enable_if_t<(static_cast<has_iterator_t<Container> (Container::*)(const T &)>(&Container::find), true), nullptr_t> = nullptr>
  class HasFind: public true_type {};

  template <typename Container, typename T>
  class HasFind: public false_type {};

  template <typename Container, typename T>
  using has_find_v = HasFind<Container, T>::value;
} // namespace tools