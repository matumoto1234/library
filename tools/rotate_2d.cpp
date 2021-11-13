#include <bits/stdc++.h>
using namespace std;

template<typename ArrayType>
vector<ArrayType> rotate_cw(const vector<ArrayType> &s) {
  int h = s.size(), w = s[0].size();
  vector<ArrayType> res(w);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      res[i].push_back(s[h - 1 - j][i]);
    }
  }
  return res;
}

template<typename ArrayType>
vector<ArrayType> rotate_ccw(const vector<ArrayType> &s) {
  int h = s.size(), w = s[0].size();
  vector<ArrayType> res(w);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      res[i].push_back(s[j][w - 1 - i]);
    }
  }
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];

  vector<string> s2 = rotate_cw(s);
  for (int i = 0; i < static_cast<int>(s2.size()); i++) {
    cout << s2[i] << endl;
  }

  s2 = rotate_ccw(s);
  for (int i = 0; i < static_cast<int>(s2.size()); i++) {
    cout << s2[i] << endl;
  }
}