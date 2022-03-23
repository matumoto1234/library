#pragma once

#include "./base.hpp"

#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

namespace library_dp {
  // TODO verify:EDPC-V, ABC220-F, ABC160-F
  // add_node: 自身の値を追加して親方向へ渡す関数 (T result, int index) |-> T
  // op: 二項演算 (monoid)
  // e: opに関する単位元
  template <typename T, T (*add_node)(T, int), T (*op)(T, T), T (*e)()>
  class ReRootingDP {
    // order と parents の前計算
    void dfs(int root) {
      int index = 0;
      stack<int> s;
      s.push(root);
      m_parents[root] = -1;

      while (not s.empty()) {
        int node = s.top();
        s.pop();

        m_order[index++] = node;
        for (auto [adjacent, ignore]: m_tree[node]) {
          if (adjacent == m_parents[node])
            continue;
          s.push(adjacent);
          m_parents[adjacent] = node;
        }
      }
    }

    // 根の値を求めるために全頂点の子方向の値を帰りがけ順で求める
    // child_subtree_results[node][i] (頂点nodeのi番目の子部分木の値) が求まる
    // ただし、子方向を親としたときの child_subtree_results[node][i] は求まらない
    void post_order(int root) {
      vector<int> reversed_order = m_order;
      reverse(reversed_order.begin(), reversed_order.end());

      for (int node: reversed_order) {
        if (node == root)
          continue;

        int parent = m_parents[node];
        int parent_index = -1;
        T result = e();

        for (int i = 0; i < (int)m_tree[node].size(); i++) {
          int to = m_tree[node][i].first;
          if (to == parent) {
            parent_index = i;
            continue;
          }

          result = op(result, m_child_subtree_results[node][i]);
        }

        assert(parent_index != -1);
        m_child_subtree_results[parent][m_index_for_adjacents[node][parent_index]] = add_node(result, node);
      }
    }

    // 全頂点の親方向の値を両側累積を使って求める(行きがけ順)
    // node_results[node] が求まる
    void pre_order() {
      for (int node: m_order) {
        int size = m_tree[node].size();

        if (size == 0)
          continue;

        vector<T> accums_front(size + 1, e()), accums_back(size, e());

        for (int i = 0; i < size; i++) {
          T child_subtree_result = m_child_subtree_results[node][i];
          accums_front[i + 1] = op(accums_front[i], child_subtree_result);
        }
        for (int i = size - 1; i >= 1; i--) {
          T child_subtree_result = m_child_subtree_results[node][i];
          accums_back[i - 1] = op(accums_back[i], child_subtree_result);
        }

        for (int i = 0; i < size; i++) {
          T result = add_node(op(accums_front[i], accums_back[i]), node);

          int parent = m_tree[node][i].first;
          int index_from_parent = m_index_for_adjacents[node][i];

          m_child_subtree_results[parent][index_from_parent] = result;
        }
        T accum_child_subtree_result = accums_front.back();
        m_node_results[node] = add_node(accum_child_subtree_result, node);
      }
    }

  public:
    using Edge = pair<int, T>;
    vector<vector<Edge>> m_tree;
    vector<vector<int>> m_index_for_adjacents;
    vector<vector<T>> m_child_subtree_results;
    vector<int> m_parents, m_order;
    vector<T> m_node_results;

    ReRootingDP(int n): m_tree(n), m_index_for_adjacents(n), m_parents(n), m_order(n), m_node_results(n, e()) {}

    // Directed edge
    void add_edge(int from, int to, T cost) {
      m_tree[from].emplace_back(to, cost);
      m_index_for_adjacents[to].emplace_back(m_tree[from].size() - 1);
    }

    void build() {
      int size = m_tree.size();
      assert(size != 0);
      m_child_subtree_results.resize(size);
      for (int i = 0; i < size; i++) {
        m_child_subtree_results[i].assign(m_tree[i].size(), e());
      }

      dfs(/* root = */ 0);
      post_order(/* root = */ 0);
      pre_order();
    }

    T operator[](int node) {
      return m_node_results[node];
    }
  };
} // namespace library_dp