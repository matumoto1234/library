#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>


namespace matumoto {
  template <typename Cost>
  struct Dijkstra {
    using Edge = WeightedEdge<Cost>;
    vector<Cost> ds;
    vector<int> bs;

    static constexpr Cost inf() {
      return numeric_limits<Cost>::max() / 2;
    }

    Dijkstra(vector<pair<Cost, int>> g, int start): ds(g.size(), inf()), bs(g.size(), -1) {
      assert(0 <= start and start < g.size());
      auto G = g.graph();
      priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
      ds[start] = 0;
      Q.emplace(start, ds[start]);

      while (!Q.empty()) {
        Edge p = Q.top();
        int v = p.to();
        Q.pop();

        if (ds[v] < p.cost())
          continue;

        for (Edge e: G[v]) {
          int to = e.to();
          Cost cost = e.cost();
          if (ds[to] > ds[v] + cost) {
            ds[to] = ds[v] + cost;
            bs[to] = v;
            Q.emplace(to, ds[to]);
          }
        }
      }
    }

    Cost operator[](int k) {
      return ds.at(k);
    }

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
} // namespace matumoto
