#pragma once

#include "./base.hpp"

#include <type_traits>

namespace tools {
  namespace helper {
    template <typename T>
    class HasIterator {
      template <typename Container>
      static true_type test(typename Container::iterator *);

      template <typename Container>
      static false_type test(...);

    public:
      static const bool value = decltype(test<T>(0))::value;
    };

    template <typename Container, typename T>
    class HasFind {
      template <typename InnerContainer,
                int dummy = (static_cast<typename enable_if<HasIterator<InnerContainer>::value, InnerContainer>::type::iterator (InnerContainer::*)(const T &)>(&InnerContainer::find), 0)>
      static true_type check(InnerContainer *);
      static false_type check(...);
      static Container *container;

    public:
      static const bool value = decltype(check(container))::value;
    };
  } // namespace helper

  template <typename Container, typename T>
  bool contains(const Container &container, const T &x) {
    if constexpr (helper::HasFind<Container, T>::value) {
      return container.find(x) != end(container);
    } else {
      return find(begin(container), end(container), x) != end(container);
    }
  }
} // namespace tools