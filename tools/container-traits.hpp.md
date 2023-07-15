---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/base.hpp
    title: tools/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/reversed.hpp
    title: tools/reversed.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tools/container-traits.hpp\"\n\n#line 2 \"tools/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"tools/container-traits.hpp\"\
    \n\n#include <array>\n#include <deque>\n#include <forward_list>\n#include <list>\n\
    #include <map>\n#include <queue>\n#include <set>\n#include <stack>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\n\nnamespace matumoto {\n\n  namespace\
    \ traits_helper {\n    template <template <typename...> typename Container, typename\
    \ Type>\n    struct IsTemplate: false_type {};\n\n    template <template <typename...>\
    \ typename Container, typename... Args>\n    struct IsTemplate<Container, Container<Args...>>:\
    \ true_type {};\n  } // namespace traits_helper\n\n  // Sequence containers\n\
    \  template <typename T>\n  struct IsArray: false_type {};\n\n  template <typename\
    \ T, size_t Size>\n  struct IsArray<array<T, Size>>: true_type {};\n\n  template\
    \ <typename... Args>\n  inline constexpr bool is_array_v = IsArray<Args...>::value;\n\
    \n  template <typename T>\n  using IsVector = traits_helper::IsTemplate<vector,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_vector_v = IsVector<T>::value;\n\
    \n  template <typename T>\n  using IsDeque = traits_helper::IsTemplate<deque,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_deque_v = IsDeque<T>::value;\n\
    \n  template <typename T>\n  using IsForwardList = traits_helper::IsTemplate<forward_list,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_forward_list_v =\
    \ IsForwardList<T>::value;\n\n  template <typename T>\n  using IsList = traits_helper::IsTemplate<list,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_list_v = IsList<T>::value;\n\
    \n  // Associative containers\n  template <typename T>\n  using IsSet = traits_helper::IsTemplate<set,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_set_v = IsSet<T>::value;\n\
    \n  template <typename T>\n  using IsMap = traits_helper::IsTemplate<map, T>;\n\
    \n  template <typename T>\n  inline constexpr bool is_map_v = IsMap<T>::value;\n\
    \n  template <typename T>\n  using IsMultiset = traits_helper::IsTemplate<multiset,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_multiset_v = IsMultiset<T>::value;\n\
    \n  template <typename T>\n  using IsMultimap = traits_helper::IsTemplate<multimap,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_multimap_v = IsMultimap<T>::value;\n\
    \n  // Unordered associative containers\n  template <typename T>\n  using IsUnorderedSet\
    \ = traits_helper::IsTemplate<unordered_set, T>;\n\n  template <typename T>\n\
    \  inline constexpr bool is_unordered_set_v = IsUnorderedSet<T>::value;\n\n  template\
    \ <typename T>\n  using IsUnorderedMap = traits_helper::IsTemplate<unordered_map,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_unordered_map_v =\
    \ IsUnorderedMap<T>::value;\n\n  template <typename T>\n  using IsUnorderedMultiset\
    \ = traits_helper::IsTemplate<unordered_multiset, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_unordered_multiset_v = IsUnorderedMultiset<T>::value;\n\
    \n  template <typename T>\n  using IsUnorderedMultimap = traits_helper::IsTemplate<unordered_multimap,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_unordered_multimap_v\
    \ = IsUnorderedMultimap<T>::value;\n\n  // Container adaptors\n  template <typename\
    \ T>\n  using IsQueue = traits_helper::IsTemplate<queue, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_queue_v = IsQueue<T>::value;\n\n  template <typename\
    \ T>\n  using IsStack = traits_helper::IsTemplate<stack, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_stack_v = IsStack<T>::value;\n\n  template <typename\
    \ T>\n  using IsPriorityQueue = traits_helper::IsTemplate<priority_queue, T>;\n\
    \n  template <typename T>\n  inline constexpr bool is_priority_queue_v = IsPriorityQueue<T>::value;\n\
    \n  // Container types\n  template <typename T>\n  using IsSequenceContainer =\
    \ disjunction<IsArray<T>, IsVector<T>, IsDeque<T>, IsForwardList<T>, IsList<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_sequence_container_v = IsSequenceContainer<T>::value;\n\
    \n  template <typename T>\n  using IsAssociativeContainer = disjunction<IsSet<T>,\
    \ IsMap<T>, IsMultiset<T>, IsMultimap<T>>;\n\n  template <typename T>\n  inline\
    \ constexpr bool is_associative_container_v = IsAssociativeContainer<T>::value;\n\
    \n  template <typename T>\n  using IsUnorderedAssociativeContainer = disjunction<IsUnorderedSet<T>,\
    \ IsUnorderedMap<T>, IsUnorderedMultiset<T>, IsUnorderedMultimap<T>>;\n\n  template\
    \ <typename T>\n  inline constexpr bool is_unordered_associative_container_v =\
    \ IsUnorderedAssociativeContainer<T>::value;\n\n  template <typename T>\n  using\
    \ IsContainerAdaptor = disjunction<IsQueue<T>, IsStack<T>, IsPriorityQueue<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_container_adaptor_v = IsContainerAdaptor<T>::value;\n\
    \n  template <typename T>\n  using IsContainer = disjunction<IsSequenceContainer<T>,\
    \ IsAssociativeContainer<T>, IsUnorderedAssociativeContainer<T>, IsContainerAdaptor<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_container_v = IsContainer<T>::value;\n\
    \n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <array>\n#include <deque>\n\
    #include <forward_list>\n#include <list>\n#include <map>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\n\nnamespace matumoto {\n\n  namespace traits_helper {\n \
    \   template <template <typename...> typename Container, typename Type>\n    struct\
    \ IsTemplate: false_type {};\n\n    template <template <typename...> typename\
    \ Container, typename... Args>\n    struct IsTemplate<Container, Container<Args...>>:\
    \ true_type {};\n  } // namespace traits_helper\n\n  // Sequence containers\n\
    \  template <typename T>\n  struct IsArray: false_type {};\n\n  template <typename\
    \ T, size_t Size>\n  struct IsArray<array<T, Size>>: true_type {};\n\n  template\
    \ <typename... Args>\n  inline constexpr bool is_array_v = IsArray<Args...>::value;\n\
    \n  template <typename T>\n  using IsVector = traits_helper::IsTemplate<vector,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_vector_v = IsVector<T>::value;\n\
    \n  template <typename T>\n  using IsDeque = traits_helper::IsTemplate<deque,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_deque_v = IsDeque<T>::value;\n\
    \n  template <typename T>\n  using IsForwardList = traits_helper::IsTemplate<forward_list,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_forward_list_v =\
    \ IsForwardList<T>::value;\n\n  template <typename T>\n  using IsList = traits_helper::IsTemplate<list,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_list_v = IsList<T>::value;\n\
    \n  // Associative containers\n  template <typename T>\n  using IsSet = traits_helper::IsTemplate<set,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_set_v = IsSet<T>::value;\n\
    \n  template <typename T>\n  using IsMap = traits_helper::IsTemplate<map, T>;\n\
    \n  template <typename T>\n  inline constexpr bool is_map_v = IsMap<T>::value;\n\
    \n  template <typename T>\n  using IsMultiset = traits_helper::IsTemplate<multiset,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_multiset_v = IsMultiset<T>::value;\n\
    \n  template <typename T>\n  using IsMultimap = traits_helper::IsTemplate<multimap,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_multimap_v = IsMultimap<T>::value;\n\
    \n  // Unordered associative containers\n  template <typename T>\n  using IsUnorderedSet\
    \ = traits_helper::IsTemplate<unordered_set, T>;\n\n  template <typename T>\n\
    \  inline constexpr bool is_unordered_set_v = IsUnorderedSet<T>::value;\n\n  template\
    \ <typename T>\n  using IsUnorderedMap = traits_helper::IsTemplate<unordered_map,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_unordered_map_v =\
    \ IsUnorderedMap<T>::value;\n\n  template <typename T>\n  using IsUnorderedMultiset\
    \ = traits_helper::IsTemplate<unordered_multiset, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_unordered_multiset_v = IsUnorderedMultiset<T>::value;\n\
    \n  template <typename T>\n  using IsUnorderedMultimap = traits_helper::IsTemplate<unordered_multimap,\
    \ T>;\n\n  template <typename T>\n  inline constexpr bool is_unordered_multimap_v\
    \ = IsUnorderedMultimap<T>::value;\n\n  // Container adaptors\n  template <typename\
    \ T>\n  using IsQueue = traits_helper::IsTemplate<queue, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_queue_v = IsQueue<T>::value;\n\n  template <typename\
    \ T>\n  using IsStack = traits_helper::IsTemplate<stack, T>;\n\n  template <typename\
    \ T>\n  inline constexpr bool is_stack_v = IsStack<T>::value;\n\n  template <typename\
    \ T>\n  using IsPriorityQueue = traits_helper::IsTemplate<priority_queue, T>;\n\
    \n  template <typename T>\n  inline constexpr bool is_priority_queue_v = IsPriorityQueue<T>::value;\n\
    \n  // Container types\n  template <typename T>\n  using IsSequenceContainer =\
    \ disjunction<IsArray<T>, IsVector<T>, IsDeque<T>, IsForwardList<T>, IsList<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_sequence_container_v = IsSequenceContainer<T>::value;\n\
    \n  template <typename T>\n  using IsAssociativeContainer = disjunction<IsSet<T>,\
    \ IsMap<T>, IsMultiset<T>, IsMultimap<T>>;\n\n  template <typename T>\n  inline\
    \ constexpr bool is_associative_container_v = IsAssociativeContainer<T>::value;\n\
    \n  template <typename T>\n  using IsUnorderedAssociativeContainer = disjunction<IsUnorderedSet<T>,\
    \ IsUnorderedMap<T>, IsUnorderedMultiset<T>, IsUnorderedMultimap<T>>;\n\n  template\
    \ <typename T>\n  inline constexpr bool is_unordered_associative_container_v =\
    \ IsUnorderedAssociativeContainer<T>::value;\n\n  template <typename T>\n  using\
    \ IsContainerAdaptor = disjunction<IsQueue<T>, IsStack<T>, IsPriorityQueue<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_container_adaptor_v = IsContainerAdaptor<T>::value;\n\
    \n  template <typename T>\n  using IsContainer = disjunction<IsSequenceContainer<T>,\
    \ IsAssociativeContainer<T>, IsUnorderedAssociativeContainer<T>, IsContainerAdaptor<T>>;\n\
    \n  template <typename T>\n  inline constexpr bool is_container_v = IsContainer<T>::value;\n\
    \n} // namespace matumoto"
  dependsOn:
  - tools/base.hpp
  isVerificationFile: false
  path: tools/container-traits.hpp
  requiredBy:
  - tools/reversed.hpp
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/container-traits.hpp
layout: document
redirect_from:
- /library/tools/container-traits.hpp
- /library/tools/container-traits.hpp.html
title: tools/container-traits.hpp
---
