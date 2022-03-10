#pragma once

#include "./base.hpp"

#include <limits>
#include <vector>

namespace graph {
  // verify:AOJ_DPL_2_A
  // sから始めて1度だけ訪問し、sに戻ってきた閉路の最短経路距離
  // buildでinfinity()が帰ってきたらそのような経路はない
  template <typename T>
  struct ShortestHamiltonianCycle {
    struct edge {
      int to;
      T cost;
      edge(int to, T cost): to(to), cost(cost) {}
    };

    int V;
    int start;
    vector<vector<edge>> G;
    vector<vector<T>> dp;

    ShortestHamiltonianCycle(int V_): V(V_), G(V_) {}

    T inf() { return numeric_limits<T>::max() / 2; }

    void add_edge(int from, int to, T cost) { G[from].emplace_back(to, cost); }

    T build(int s) {
      start = s;
      dp.assign(V, vector<T>(1 << V, -1));
      return dfs(s, 0);
    }

    // private method
    T dfs(int v, int Set) {
      T &res = dp[v][Set];
      if (Set + 1 == 1 << V and v == start)
        res = 0;
      if (res != -1)
        return res;
      res = inf();
      for (auto [to, cost]: G[v]) {
        int bit = 1 << to;
        if (Set & bit)
          continue;
        res = min(res, dfs(to, Set | bit) + cost);
      }
      return res;
    }
  };
} // namespace graph