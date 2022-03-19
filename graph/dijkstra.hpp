#pragma once

#include "./base.hpp"
#include "./weighted-graph.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>


namespace graph {
  template <typename Cost>
  struct Dijkstra {
    using Edge = typename WeightedGraph<Cost>::WeightedEdge;
    vector<Cost> ds;
    vector<int> bs;

    static constexpr Cost inf() { return numeric_limits<Cost>::max() / 2; }

    Dijkstra(WeightedGraph<Cost> g, int start): ds(g.size(), inf()), bs(g.size(), -1) {
      assert(0 <= start and start < g.size());
      auto G = g.graph();
      priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
      ds[start] = 0;
      Q.emplace(start, ds[start]);

      while (!Q.empty()) {
        auto [v, dist] = Q.top();
        Q.pop();

        if (ds[v] < dist)
          continue;

        for (auto [to, cost]: G[v]) {
          if (ds[to] > ds[v] + cost) {
            ds[to] = ds[v] + cost;
            bs[to] = v;
            Q.emplace(to, ds[to]);
          }
        }
      }
    }

    Cost operator[](int k) { return ds.at(k); }

    vector<int> restore(int to) {
      vector<int> res;
      if (bs[to] == -1) {
        res.emplace_back(to);
        return res;
      }
      while (to != -1) {
        res.emplace_back(to);
        to = bs[to];
      }
      reverse(res.begin(), res.end());
      return res;
    }
  };
} // namespace graph
