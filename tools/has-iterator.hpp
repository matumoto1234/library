#pragma once

#include "./base.hpp"

#include <type_traits>

namespace tools {
  template <typename T>
  class HasIterator {
    template <typename Container>
    static true_type check(typename Container::iterator *);

    template <typename Container>
    static false_type check(...);

  public:
    static const bool value = decltype(check<T>(0))::value;
  };

} // namespace tools