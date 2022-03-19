#pragma once

#include "./base.hpp"

#include <iostream>
#include <string>

namespace library_data_structure {
  template <typename T, T (*op)(T, T), T (*e)()>
  class DynamicSegmentTree {
  private:
    using ll = long long;
    struct node {
      node *left, *right;
      T v;

      node(): left(nullptr), right(nullptr), v(e()) {}
    };

    ll n;

    T prod(ll a, ll b, node *now, ll l, ll r) {
      if (a <= l and r <= b) {
        return now->v;
      }
      if (r <= a or b <= l) {
        return e();
      }

      T lv = e(), rv = e();
      if (now->left)
        lv = prod(a, b, now->left, l, (l + r) / 2);
      if (now->right)
        rv = prod(a, b, now->right, (l + r) / 2, r);
      return op(lv, rv);
    }

    void debug_dfs(node *now, string spaces) {
      if (now->right) {
        debug_dfs(now->right, spaces + "   ");
      }
      cerr << spaces << now->v << "\n";
      if (now->left) {
        debug_dfs(now->left, spaces + "   ");
      }
    }

  public:
    node *root;
    DynamicSegmentTree(ll n_) {
      n = 1;
      while (n < n_) {
        n *= 2;
      }
      root = new node();
    }

    void add(ll k, T x) {
      node *now = root;
      ll l = 0, r = n;
      now->v = op(now->v, x);
      while (r - l > 1) {
        ll m = (l + r) / 2;
        if (k < m) {
          if (!now->left)
            now->left = new node();
          now = now->left;
          r = m;
        } else {
          if (!now->right)
            now->right = new node();
          now = now->right;
          l = m;
        }
        now->v = op(now->v, x);
      }
    }

    void debug() { debug_dfs(root, ""); }

    T prod(ll l, ll r) { return prod(l, r, root, 0, n); }
  };
} // namespace library_data_structure