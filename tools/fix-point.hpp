#pragma once

#include "./base.hpp"

#include <utility>

namespace matumoto {
  template <typename F>
  struct FixPoint: F {
    FixPoint(F &&f) noexcept: F{ forward<F>(f) } {}

    template <typename... Args>
    decltype(auto) operator()(Args &&...args) const {
      return F::operator()(*this, forward<Args>(args)...);
    }
  };

  template <typename F>
  inline decltype(auto) make_fix_point(F &&f) {
    return FixPoint<F>{ forward<F>(f) };
  }
} // namespace matumoto