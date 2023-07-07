#pragma once

#include "./base.hpp"

#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

namespace matumoto {
  // verify:ABC001_D
  // verify:ABC228_D

  /**
   * @brief [l, r)の区間を管理する
   *        2つの区間[l1, r1), [l2, r2)は重複、連結していない
   *        任意の整数xを含む区間の数は高々1つ
   */
  template <typename T = long long>
  struct IntervalSet {
    set<pair<T, T>> s;

    IntervalSet() {
      s.emplace(-inf(), -inf() + 1);
      s.emplace(inf(), inf() + 1);
    }

    T inf() const {
      return numeric_limits<T>::max() / 2;
    }

    bool is_inf(const pair<T, T> &p) const {
      return p.first == inf() or p.second == inf() or p.first == -inf() or p.second == -inf();
    }

    bool empty() const {
      return s.size() <= 2;
    }

    // contains { (l, r) | l <= x < r }
    bool contains(T x) const {
      if (empty()) {
        return false;
      }

      auto [l, r] = *(this->find(x));
      return l <= x and x < r;
    }

    // find { (l, r) | l <= x < r }
    typename set<pair<T, T>>::iterator find(int x) const {
      // 1以上の正整数nについてpair(x, x+n) < pair(x+1, x+2)が成り立つ
      // また、pair(x, x+n) < a < pair(x+1, x+2)なるaは存在しないので
      // contains(x)が成り立つならばlower_boundを取ったprevにxが含まれている
      return prev(s.lower_bound(pair(x + 1, x + 2)));
    }

    pair<typename set<pair<T, T>>::iterator, bool> insert(T x) {
      return insert(pair(x, x + 1));
    }

    // insert [l, r)
    // もし[l, r)に重複or連続する区間が存在するならばそれらを削除する
    // 計算量 : ならし対数時間
    // 返り値 : std::set::insertに準拠
    pair<typename set<pair<T, T>>::iterator, bool> insert(pair<T, T> p) {
      assert(p.first < p.second);

      auto l_itr = find(p.first);
      while (intersect(*l_itr, p) or continuous(*l_itr, p)) {
        p = extend_interval(*l_itr, p);
        s.erase(l_itr);
        l_itr = find(p.first);
      }

      auto r_itr = find(p.second);
      while (intersect(*r_itr, p) or continuous(*r_itr, p)) {
        p = extend_interval(*r_itr, p);
        s.erase(r_itr);
        r_itr = find(p.second);
      }

      return s.insert(p);
    }

    // erase { (l, r) | l <= x < r }
    void erase_interval(T x) {
      if (not contains(x)) {
        return;
      }

      auto it = find(x);
      s.erase(it);
    }

    // { (l, r) | l <= x < r } => { (l, x), (x+1, r) | l < x && x+1 < r}
    void cut(T x) {
      if (not contains(x)) {
        return;
      }

      auto it = find(x);
      auto [l, r] = *it;
      s.erase(it);
      if (l < x) {
        s.emplace(l, x);
      }
      if (x + 1 < r) {
        s.emplace(x + 1, r);
      }
    }

    template <typename T1>
    friend ostream &operator<<(ostream &os, const IntervalSet<T1> &rhs) {
      os << "{";
      bool is_first = true;
      for (const pair<T, T> &p: rhs.s) {
        if (rhs.is_inf(p)) {
          continue;
        }
        if (not is_first) {
          os << ", ";
        }
        is_first = false;
        os << "[" << p.first << "," << p.second << ")";
      }
      os << "}";
      return os;
    }

    pair<T, T> extend_interval(const pair<T, T> &p1, const pair<T, T> &p2) const {
      assert(intersect(p1, p2) or continuous(p1, p2));

      vector<T> a{ p1.first, p1.second, p2.first, p2.second };
      sort(a.begin(), a.end());
      return { a.front(), a.back() };
    }

    bool intersect(pair<T, T> p1, pair<T, T> p2) const {
      if (p1 > p2) {
        swap(p1, p2);
      }
      const auto &[a, b] = p1;
      const auto &[c, d] = p2;
      return (a <= c and c < b) or (c <= a and a < d);
    }

    bool continuous(pair<T, T> p1, pair<T, T> p2) const {
      if (p1 > p2) {
        swap(p1, p2);
      }
      return p1.second == p2.first;
    }
  };
} // namespace matumoto
