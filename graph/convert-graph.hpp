#pragma once

#include "base.hpp"

#include <string>

namespace matumoto {
  // grid graph -> adjacency list
  vector<vector<int>> grid_to_adjacency_list(const vector<string> &s, const string &wall = "#") {
    int h = s.size(), w = s[0].size();
    constexpr int dy[] = { 1, 0, -1, 0 }, dx[] = { 0, 1, 0, -1 };
    vector<vector<int>> adj_list(h * w);

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int from = i * w + j;

        for (int k = 0; k < 4; k++) {
          int ny = i + dy[k], nx = j + dx[k];

          if (ny < 0 or nx < 0 or ny >= h or nx >= w) {
            continue;
          }

          if (wall.find(s[ny][nx]) != string::npos) {
            continue;
          }

          int to = ny * w + nx;
          adj_list[from].push_back(to);
        }
      }
    }
    return adj_list;
  }
} // namespace matumoto
