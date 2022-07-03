#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <string>

namespace graph_library {
  // grid graph -> UnWeightedGraph
  UnWeightedGraph convert_graph(const vector<string> &s, const string &wall = "#") {
    int h = s.size(), w = s[0].size();
    constexpr int dy[] = { 1, 0, -1, 0 }, dx[] = { 0, 1, 0, -1 };
    UnWeightedGraph graph(h * w);

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int from = i * w + j;

        for (int k = 0; k < 4; k++) {
          int ny = i + dy[k], nx = j + dx[k];

          if (ny < 0 or nx < 0 or ny >= h or nx >= w)
            continue;

          if (wall.find(s[ny][nx]) != string::npos)
            continue;

          int to = ny * w + nx;
          graph.add_edge(UnWeightedEdge(from, to));
        }
      }
    }
    return graph;
  }
} // namespace graph_library