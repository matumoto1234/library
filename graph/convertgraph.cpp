#include <bits/stdc++.h>
using namespace std;

// grid graph -> adjacency list
vector<vector<int>> convert_graph(const vector<string> &s) {
  int h = s.size(), w = s[0].size();
  constexpr int dy[] = { 1, 0, -1, 0 }, dx[] = { 0, 1, 0, -1 };
  vector<vector<int>> res(h * w);
  for ( int i = 0; i < h; i++ ) {
    for ( int j = 0; j < w; j++ ) {
      int from = i * w + j;
      for ( int k = 0; k < 4; k++ ) {
        int ny = i + dy[k], nx = j + dx[k];
        if ( ny < 0 or nx < 0 or ny >= h or nx >= w ) continue;
        int to = ny * w + j;
        res[from].push_back(to);
      }
    }
  }
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for ( int i = 0; i < h; i++ ) {
    cin >> s[i];
  }

  auto G = convert_graph(s);
  for ( int i = 0; i < h * w; i++ ) {
    cout << "i:" << i << ' ';
    for ( int to : G[i] ) {
      cout << to << ' ';
    }
    cout << '\n';
  }
}