#pragma once

#include "./base.hpp"

#include <set>

namespace matumoto {
  // verify:hhkb2020_C
  template <typename T = long long>
  struct MexSet {
    set<pair<T, T>> s;

    T inf() {
      return numeric_limits<T>::max() / 2;
    }

    MexSet() {
      s.emplace(inf(), inf());
      s.emplace(-inf(), -inf());
    }

    bool contains(T x) const {
      auto [lower, upper] = *prev(s.lower_bound(pair(x + 1, x + 1)));
      return lower <= x and x <= upper;
    }

    bool insert(T x) {
      if (contains(x))
        return false;
      auto nit = s.lower_bound(pair(x + 1, x + 1));
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (u == x - 1) {
        if (nl == x + 1) {
          s.erase(it);
          s.erase(nit);
          s.emplace(l, nu);
        } else {
          s.erase(it);
          s.emplace(l, x);
        }
      } else {
        if (nl == x + 1) {
          s.erase(nit);
          s.emplace(x, nu);
        } else {
          s.emplace(x, x);
        }
      }
      return true;
    }

    bool erase(T x) {
      if (!contains(x))
        return false;
      auto it = prev(s.lower_bound(pair(x + 1, x + 1)));
      auto [l, u] = *it;
      s.erase(it);
      if (x != l)
        s.emplace(l, x - 1);
      if (x != u)
        s.emplace(x + 1, u);
      return true;
    }

    T mex(T x = 0) const {
      auto [l, u] = *prev(s.lower_bound(pair(x + 1, x + 1)));
      if (l <= x and x <= u) {
        return u + 1;
      } else {
        return x;
      }
    }
  };
} // namespace matumoto