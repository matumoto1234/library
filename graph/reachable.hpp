#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <stack>

namespace graph_library {
  // s,t : 0-indexed.
  // reachable s -> t
  template <class Graph>
  bool reachable(const Graph &g, int s, int t) {
    const auto &graph = g.graph();

    stack<int> st;
    st.push(s);
    vector<char> used(g.size(), 0);

    while (not st.empty()) {
      int v = st.top();
      st.pop();

      used[v] = true;
      if (v == t)
        return true;

      for (const auto &edge: graph[v]) {
        const int &to = edge.to();
        if (used[to])
          continue;

        st.push(to);
      }
    }

    return false;
  }
} // namespace graph_library
