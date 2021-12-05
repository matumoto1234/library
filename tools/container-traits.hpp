#pragma once

#include "./base.hpp"

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>


namespace tools {

  namespace traits_helper {
    template <template <typename...> typename Container, typename Type>
    struct IsTemplate: false_type {};

    template <template <typename...> typename Container, typename... Args>
    struct IsTemplate<Container, Container<Args...>>: true_type {};
  } // namespace traits_helper

  // Sequence containers
  template <typename T>
  struct IsArray: false_type {};

  template <typename T, size_t Size>
  struct IsArray<array<T, Size>>: true_type {};

  template <typename T>
  using IsVector = traits_helper::IsTemplate<vector, T>;

  template <typename T>
  using IsDeque = traits_helper::IsTemplate<deque, T>;

  template <typename T>
  using IsForwardList = traits_helper::IsTemplate<forward_list, T>;

  template <typename T>
  using IsList = traits_helper::IsTemplate<list, T>;

  // Associative containers
  template <typename T>
  using IsSet = traits_helper::IsTemplate<set, T>;

  template <typename T>
  using IsMap = traits_helper::IsTemplate<map, T>;

  template <typename T>
  using IsMultiSet = traits_helper::IsTemplate<multiset, T>;

  template <typename T>
  using IsMultiMap = traits_helper::IsTemplate<multimap, T>;

  // Unordered associative containers
  template <typename T>
  using IsUnorderedSet = traits_helper::IsTemplate<unordered_set, T>;

  template <typename T>
  using IsUnorderedMap = traits_helper::IsTemplate<unordered_map, T>;

  template <typename T>
  using IsUnorderedMultiset = traits_helper::IsTemplate<unordered_multiset, T>;

  template <typename T>
  using IsUnorderedMultimap = traits_helper::IsTemplate<unordered_multimap, T>;

  // Container adaptors
  template <typename T>
  using IsQueue = traits_helper::IsTemplate<queue, T>;

  template <typename T>
  using IsStack = traits_helper::IsTemplate<stack, T>;

  template <typename T>
  using IsPriorityQueue = traits_helper::IsTemplate<priority_queue, T>;

  // Container types
  template <typename T>
  using IsSequenceContainer = disjunction<IsArray<T>, IsVector<T>, IsDeque<T>, IsForwardList<T>, IsList<T>>;

  template <typename T>
  using IsAssociativeContainer = disjunction<IsSet<T>, IsMap<T>, IsMultiset<T>, IsMultimap<T>>;

  template <typename T>
  using IsUnorderedAssociativeContainer = disjunction<IsUnorderedSet<T>, IsUnorderedMap<T>, IsUnorderedMultiset<T>, IsUnorderedMultimap<T>>;

  template <typename T>
  using IsContainerAdaptor = disjunction<IsQueue<T>, IsStack<T>, IsPriorityQueue<T>>;

  template <typename T>
  using IsContainer = disjunction<IsSequenceContainer<T>, IsAssociativeContainer<T>, IsUnorderedAssociativeContainer<T>, IsContainerAdaptor<T>>;

} // namespace tools