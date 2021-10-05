#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
vector<pair<T1, T2>> aggregate(const vector<T1> &a, const vector<T2> &b) {
  vector<pair<T1, T2>> res;
  int mi = min(a.size(), b.size());
  int ma = max(a.size(), b.size());
  res.reserve(ma);
  for ( int i = 0; i < mi; i++ ) {
    res.emplace_back(a[i], b[i]);
  }

  for ( int i = mi; i < ma; i++ ) {
    if ( a.size() > b.size() ) {
      res.emplace_back(a[i]);
    } else {
      res.emplace_back(b[i]);
    }
  }
  return res;
}

int main() {
}