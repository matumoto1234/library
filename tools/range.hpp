#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

using namespace std;

// begin,endを持つ構造体
template<typename Iterator>
class Range {
  const Iterator begin_;
  const Iterator end_;

public:
  Range(Iterator &&b, Iterator &&e) noexcept: begin_(forward<Iterator>(b)), end_(forward<Iterator>(e)) {}

  Iterator begin() const noexcept { return begin_; }

  Iterator end() const noexcept { return end_; }
}; // class Range

template<typename Iterator>
Range<Iterator> make_range(Iterator &&begin, Iterator &&end) noexcept {
  return Range<Iterator>{ forward<Iterator>(begin), forward<Iterator>(end) };
}

// initiaizer_list用
template<typename T>
decltype(auto) make_reversed_range(const initializer_list<T> &init_list) noexcept {
  return make_range(rbegin(init_list), rend(init_list));
}

// rbegin,rendを持っている方
template<typename T>
decltype(auto) make_reversed_range(T &&container) noexcept {
  return make_range(rbegin(container), rend(container));
}