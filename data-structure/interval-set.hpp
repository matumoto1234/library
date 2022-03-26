#pragma once

#include "./base.hpp"

#include <cassert>
#include <set>

namespace data_structure_library {
  // verify:ABC228_D
  template <typename T = long long>
  struct IntervalSet {
    set<pair<T, T>> s;

    IntervalSet() {
      s.emplace(-inf(), -inf());
      s.emplace(inf(), inf());
    }

    T inf() const {
      return numeric_limits<T>::max() / 2;
    }

    bool empty() const {
      return static_cast<int>(s.size()) == 2;
    }

    bool contains(T x) const {
      if (empty())
        return false;
      auto [lower, upper] = *prev(s.lower_bound(pair(x + 1, x + 1)));
      return lower <= x and x <= upper;
    }

    // max({ (lower, upper) | lower <= x <= upper })
    pair<T, T> get(T x) const {
      assert(contains(x));
      return *prev(s.lower_bound(pair(x + 1, x + 1)));
    }

    bool insert(T x) {
      if (contains(x))
        return false;
      auto nit = s.lower_bound(pair(x + 1, x + 1));
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (u == x - 1 and nl == x + 1) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else if (u == x - 1 and nl != x + 1) {
        s.erase(it);
        s.emplace(l, x);
      } else if (u != x - 1 and nl == x + 1) {
        s.erase(nit);
        s.emplace(x, nu);
      } else if (u != x - 1 and nl != x + 1) {
        s.emplace(x, x);
      }
      return true;
    }

    bool insert(T x, T y) {
      if (x > y)
        swap(x, y);
      bool contains_x = contains(x);
      bool contains_y = contains(y);
      if (!contains_x and !contains_y) {
        s.emplace(x, y);
      } else if (!contains_x and contains_y) {
        auto yit = prev(s.lower_bound(pair(y + 1, y + 1)));
        auto [yl, yu] = *yit;
        s.erase(yit);
        s.emplace(x, yu);
      } else if (contains_x and !contains_y) {
        auto xit = prev(s.lower_bound(pair(x + 1, x + 1)));
        auto [xl, xu] = *xit;
        s.erase(xit);
        s.emplace(xl, y);
      } else {
        auto xit = prev(s.lower_bound(pair(x + 1, x + 1)));
        auto yit = prev(s.lower_bound(pair(y + 1, y + 1)));
        if (xit == yit)
          return false;
        auto [xl, xu] = *xit;
        auto [yl, yu] = *yit;
        s.erase(xit);
        s.erase(yit);
        s.emplace(xl, yu);
      }
      return true;
    }

    bool insert(pair<T, T> p) {
      return insert(p.first, p.second);
    }

    // { (l, u) | l <= x <= u } => { (l, x - 1), (x + 1, u) | l <= x <= u }
    bool erase(T x) {
      assert(x != -inf() and x != inf());
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

    // { (l, u) | l <= x <= u } => { (l, x), (x, u) | l <= x <= u }
    bool cut(T x) {
      assert(x != -inf() and x != inf());
      if (!contains(x))
        return false;
      auto it = prev(s.lower_bound(pair(x + 1, x + 1)));
      auto [l, u] = *it;
      s.erase(it);
      s.emplace(l, x);
      s.emplace(x, u);
      return true;
    }
  };
} // namespace data_structure_library