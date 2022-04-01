#pragma once

#include "./base.hpp"
#include "./graph-type.hpp"

#include <string>
#include <vector>

namespace graph_library {
  int to_v(int w, int y, int x) {
    return y * w + x;
  }

  template <class Graph>
  Graph grid_to_graph(const vector<string> &grid, const string wall = "#") {
    constexpr int dy[] = { 1, 0, -1, 0 };
    constexpr int dx[] = { 0, 1, 0, -1 };

    Graph res;

    int h = grid.size();
    for (int y = 0; y < h; y++) {
      int w = grid[y].size();
      for (int x = 0; x < w; x++) {
        int from = to_v(w, y, x);

        for (int i = 0; i < 4; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];

          if (not(0 <= ny and ny < h and 0 <= nx and nx < w))
            continue;

          if (wall.find(grid[ny][nx]) != string::npos)
            continue;

          int to = to_v(w, ny, nx);
          res.add_edge(from, to);
        }
      }
    }

    return res;
  }
} // namespace graph_library
