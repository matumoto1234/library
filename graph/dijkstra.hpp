#pragma once

#include "./base.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

namespace graph {
  template <typename T>
  struct Dijkstra {
    struct edge {
      int to;
      T cost;
      edge() {}
      edge(int to, T cost): to(to), cost(cost) {}
      bool operator<(const edge &e) const { return cost > e.cost; }
    };

    T inf() { return numeric_limits<T>::max() / 2; }

    vector<vector<edge>> G;
    vector<T> ds;
    vector<int> bs;
    vector<pair<int, pair<int, T>>> es;
    Dijkstra(int n): G(n) {}

    void add_edge(int from, int to, T cost) {
      G[from].emplace_back(to, cost);
      es.emplace_back(from, to, cost);
    }

    void build(int start) {
      int n = G.size();
      ds.assign(n, inf());
      bs.assign(n, -1);

      priority_queue<edge> Q;
      ds[start] = 0;
      Q.emplace(start, ds[start]);

      while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        int v = p.to;
        if (ds[v] < p.cost)
          continue;
        for (auto e: G[v]) {
          if (ds[e.to] > ds[v] + e.cost) {
            ds[e.to] = ds[v] + e.cost;
            bs[e.to] = v;
            Q.emplace(e.to, ds[e.to]);
          }
        }
      }
    }

    T operator[](int k) { return ds[k]; }

    pair<int, pair<int, T>> get_edge(int k) { return es[k]; }

    vector<pair<int, pair<int, T>>> edges() { return es; }

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