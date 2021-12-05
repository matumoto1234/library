#pragma once

#include "./base.hpp"

#include <type_traits>
#include <algorithm>

namespace tools {
  template <typename Container>
  auto reversed(Container c){
    reverse(c.begin(), c.end());
    return c;
  }
}