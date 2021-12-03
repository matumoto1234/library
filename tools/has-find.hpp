#pragma once

#include "./has-iterator.hpp"

namespace tools {
  template <typename Container, typename T>
  class HasFind {
    template <typename InnerContainer>
    using Iterator = typename enable_if<HasIterator<InnerContainer>::value, InnerContainer>::type::iterator;

    template <typename InnerContainer, int dummy = (static_cast<Iterator<InnerContainer> (InnerContainer::*)(const T &)>(&InnerContainer::find), 0)>
    static true_type check(InnerContainer *);
    static false_type check(...);
    static Container *container;

  public:
    static const bool value = decltype(check(container))::value;
  };
} // namespace tools