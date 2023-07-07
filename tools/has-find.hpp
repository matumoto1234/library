#pragma once

#include "./has-iterator.hpp"

#include <cstddef>

namespace matumoto {
  template <typename Container, typename T>
  class HasFind {
    static false_type check(...);

    template <typename C, enable_if_t<(static_cast<has_iterator_t<C> (C::*)(const T &)>(&C::find), true), nullptr_t> = nullptr>
    static true_type check(C *);

    static Container *container;

  public:
    static constexpr bool value = decltype(check(container))::value;
  };

  template <typename Container, typename T>
  static constexpr bool has_find_v = HasFind<Container, T>::value;
} // namespace matumoto