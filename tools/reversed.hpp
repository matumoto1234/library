#pragma once

#include "./base.hpp"
#include "./container-traits.hpp"

#include <algorithm>
#include <type_traits>

namespace tools {
  // array or vector or deque or string
  template <typename Container>
  constexpr Container reversed(const Container &c) {
    Container res = c;
    reverse(res.begin(), res.end());
    return res;
  }

  // list or forward_list
  template <template <typename T> typename Container, typename T, enable_if_t<(is_forward_list_v<Container<T>> or is_list_v<Container<T>>)> * = nullptr>
  constexpr auto reversed(const Container<T> &ls) {
    Container<T> res = ls;
    res.reverse();
    return res;
  }

  // set or multiset
  template <template <typename T, typename Compare> typename Container, typename T, typename Compare, enable_if_t<(is_set_v<Container<T, Compare>> or is_multiset_v<Container<T, Compare>>)> * = nullptr>
  constexpr auto reversed(const Container<T, Compare> &st) {
    if constexpr (is_same_v<Compare, less<T>>) {
      Container<T, greater<T>> res;
      for (const auto &v: st) {
        res.emplace_hint(res.begin(), v);
      }
      return res;
    } else {
      Container<T, less<T>> res;
      for (const auto &v: st) {
        res.emplace_hint(res.begin(), v);
      }
      return res;
    }
  }

  // map or multimap
  template <template <typename T1, typename T2, typename Compare> typename Container,
            typename T1,
            typename T2,
            typename Compare,
            enable_if_t<(is_map_v<Container<T1, T2, Compare>> or is_multimap_v<Container<T1, T2, Compare>>)> * = nullptr>
  constexpr auto reversed(const Container<T1, T2, Compare> &mp) {
    if constexpr (is_same_v<Compare, less<T1>>) {
      Container<T1, T2, greater<T1>> res;
      for (const auto &p: mp) {
        res.emplace_hint(res.begin(), p);
      }
      return res;
    } else {
      Container<T1, T2, less<T1>> res;
      for (const auto &p: mp) {
        res.emplace_hint(res.begin(), p);
      }
      return res;
    }
  }
} // namespace tools