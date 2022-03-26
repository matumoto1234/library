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


namespace tools_library {

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

  template <typename... Args>
  inline constexpr bool is_array_v = IsArray<Args...>::value;

  template <typename T>
  using IsVector = traits_helper::IsTemplate<vector, T>;

  template <typename T>
  inline constexpr bool is_vector_v = IsVector<T>::value;

  template <typename T>
  using IsDeque = traits_helper::IsTemplate<deque, T>;

  template <typename T>
  inline constexpr bool is_deque_v = IsDeque<T>::value;

  template <typename T>
  using IsForwardList = traits_helper::IsTemplate<forward_list, T>;

  template <typename T>
  inline constexpr bool is_forward_list_v = IsForwardList<T>::value;

  template <typename T>
  using IsList = traits_helper::IsTemplate<list, T>;

  template <typename T>
  inline constexpr bool is_list_v = IsList<T>::value;

  // Associative containers
  template <typename T>
  using IsSet = traits_helper::IsTemplate<set, T>;

  template <typename T>
  inline constexpr bool is_set_v = IsSet<T>::value;

  template <typename T>
  using IsMap = traits_helper::IsTemplate<map, T>;

  template <typename T>
  inline constexpr bool is_map_v = IsMap<T>::value;

  template <typename T>
  using IsMultiset = traits_helper::IsTemplate<multiset, T>;

  template <typename T>
  inline constexpr bool is_multiset_v = IsMultiset<T>::value;

  template <typename T>
  using IsMultimap = traits_helper::IsTemplate<multimap, T>;

  template <typename T>
  inline constexpr bool is_multimap_v = IsMultimap<T>::value;

  // Unordered associative containers
  template <typename T>
  using IsUnorderedSet = traits_helper::IsTemplate<unordered_set, T>;

  template <typename T>
  inline constexpr bool is_unordered_set_v = IsUnorderedSet<T>::value;

  template <typename T>
  using IsUnorderedMap = traits_helper::IsTemplate<unordered_map, T>;

  template <typename T>
  inline constexpr bool is_unordered_map_v = IsUnorderedMap<T>::value;

  template <typename T>
  using IsUnorderedMultiset = traits_helper::IsTemplate<unordered_multiset, T>;

  template <typename T>
  inline constexpr bool is_unordered_multiset_v = IsUnorderedMultiset<T>::value;

  template <typename T>
  using IsUnorderedMultimap = traits_helper::IsTemplate<unordered_multimap, T>;

  template <typename T>
  inline constexpr bool is_unordered_multimap_v = IsUnorderedMultimap<T>::value;

  // Container adaptors
  template <typename T>
  using IsQueue = traits_helper::IsTemplate<queue, T>;

  template <typename T>
  inline constexpr bool is_queue_v = IsQueue<T>::value;

  template <typename T>
  using IsStack = traits_helper::IsTemplate<stack, T>;

  template <typename T>
  inline constexpr bool is_stack_v = IsStack<T>::value;

  template <typename T>
  using IsPriorityQueue = traits_helper::IsTemplate<priority_queue, T>;

  template <typename T>
  inline constexpr bool is_priority_queue_v = IsPriorityQueue<T>::value;

  // Container types
  template <typename T>
  using IsSequenceContainer = disjunction<IsArray<T>, IsVector<T>, IsDeque<T>, IsForwardList<T>, IsList<T>>;

  template <typename T>
  inline constexpr bool is_sequence_container_v = IsSequenceContainer<T>::value;

  template <typename T>
  using IsAssociativeContainer = disjunction<IsSet<T>, IsMap<T>, IsMultiset<T>, IsMultimap<T>>;

  template <typename T>
  inline constexpr bool is_associative_container_v = IsAssociativeContainer<T>::value;

  template <typename T>
  using IsUnorderedAssociativeContainer = disjunction<IsUnorderedSet<T>, IsUnorderedMap<T>, IsUnorderedMultiset<T>, IsUnorderedMultimap<T>>;

  template <typename T>
  inline constexpr bool is_unordered_associative_container_v = IsUnorderedAssociativeContainer<T>::value;

  template <typename T>
  using IsContainerAdaptor = disjunction<IsQueue<T>, IsStack<T>, IsPriorityQueue<T>>;

  template <typename T>
  inline constexpr bool is_container_adaptor_v = IsContainerAdaptor<T>::value;

  template <typename T>
  using IsContainer = disjunction<IsSequenceContainer<T>, IsAssociativeContainer<T>, IsUnorderedAssociativeContainer<T>, IsContainerAdaptor<T>>;

  template <typename T>
  inline constexpr bool is_container_v = IsContainer<T>::value;

} // namespace tools_library