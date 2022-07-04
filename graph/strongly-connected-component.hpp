#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"
#include "./reverse-edges.hpp"

namespace graph_library {
  template <typename Graph>
  class StronglyConnectedComponent {
    Graph scc_graph_;
    vector<vector<int>> scc_;
    vector<bool> used_;
    vector<int> post_order_, group_;

  public:
    StronglyConnectedComponent(const Graph &graph) {
      int n = graph.size();

      // get post order
      used_.assign(n, false);
      auto adj_list = graph.graph();

      for (int i = 0; i < n; i++) {
        if (used_[i])
          continue;

        dfs(adj_list, i);
      }

      int scc_cnt = 0;
      group_.assign(n, 0);
      used_.assign(n, false);

      Graph rgraph = reverse_edges(graph);
      auto radj_list = rgraph.graph();

      // scc grouping
      for (int i = n - 1; i >= 0; i--) {
        int idx = post_order_[i];
        if (used_[idx])
          continue;

        rdfs(radj_list, idx, scc_cnt);
        scc_cnt++;
      }

      scc_.assign(scc_cnt, vector<int>(0));
      scc_graph_ = Graph(scc_cnt);

      for (int i = 0; i < n; i++) {
        // build scc
        scc_[group_[i]].push_back(i);

        // build scc graph
        for (auto e: adj_list[i]) {
          bool is_same_scc = group_[i] == group_[e.to()];
          if (is_same_scc)
            continue;

          if constexpr (is_same_v<Graph, UnWeightedGraph>) {
            scc_graph_.add_edge(UnWeightedEdge(group_[i], group_[e.to()]));
          } else {
            scc_graph_.add_edge(WeightedEdge(group_[i], group_[e.to()], e.cost()));
          }
        }
      }
    }

    vector<int> group() const {
      return group_;
    }

    vector<vector<int>> scc() const {
      return scc_;
    }

    Graph scc_graph() const {
      return scc_graph_;
    }

  private:
    template <typename Edges>
    void dfs(const vector<Edges> &adj_list, int idx) {
      used_[idx] = true;
      for (const auto &e: adj_list[idx]) {
        const int &to = e.to();
        if (used_[to])
          continue;

        dfs(adj_list, to);
      }
      post_order_.emplace_back(idx);
    }

    template <typename Edges>
    void rdfs(const vector<Edges> &adj_list, int idx, int group_id) {
      used_[idx] = true;
      group_[idx] = group_id;
      for (const auto &e: adj_list[idx]) {
        const int &to = e.to();
        if (used_[to])
          continue;

        rdfs(adj_list, to, group_id);
      }
    }
  };
} // namespace graph_library
