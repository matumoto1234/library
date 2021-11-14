#pragma once

#include "./base.hpp"

#include <algorithm>
#include <vector>

namespace graph {
  template <typename T>
  class BellmanFord {
  public:
    struct edge {
      int from, to;
      T cost;
      edge() {}
      edge(int f, int t, T c): from(f), to(t), cost(c) {}
    };

  private:
    bool neg_cycle;
    bool neg_cycle_to_goal;

  public:
    int V;
    vector<edge> es;
    vector<T> ds;
    vector<int> bs;

    BellmanFord(int N): V(N), neg_cycle(false), neg_cycle_to_goal(false) {}

    void add_edge(int from, int to, T cost) { es.emplace_back(from, to, cost); }

    bool neg() { return neg_cycle; }

    bool neg_to_goal() { return neg_cycle_to_goal; }

    T inf() { return numeric_limits<T>::max() / 2; }

    void build(int s, int g = -1) {
      if (g == -1) g = V - 1;
      ds.assign(V, inf());
      bs.assign(V, -1);
      ds[s] = 0;

      for (int i = 0; i < 2 * V; i++) {
        for (edge e: es) {
          if (ds[e.from] >= inf()) continue;
          if (ds[e.to] <= ds[e.from] + e.cost) continue;

          ds[e.to] = ds[e.from] + e.cost;
          bs[e.from] = e.to;
          if (i >= V - 1) {
            ds[e.to] = -inf();
            neg_cycle = true;
            if (e.to == g) {
              neg_cycle_to_goal = true;
              return;
            }
          }
        }
      }
    }

    T operator[](int k) { return ds[k]; }

    vector<int> restore(int to) {
      vector<int> res;
      if (bs[to] == -1) {
        res.emplace_back(to);
        return res;
      }
      while (bs[to] != -1) {
        res.emplace_back(to);
        to = bs[to];
      }
      reverse(res.begin(), res.end());
      return res;
    }
  };
} // namespace graph