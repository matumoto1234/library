#include <bits/stdc++.h>
using namespace std;

struct Sliced {
  static constexpr int init = INT32_MAX;
  Sliced() {}

  template <typename T>
  vector<T> operator()(const vector<T> &v, int l, int r = init, int stride = init) {
    assert(stride != 0);
    if ( r == init ) r = v.size();
    if ( stride == init ) stride = 1;
    vector<T> res;
    int start = (stride > 0 ? l : r - 1);
    for ( int i = start; (stride > 0 ? i < r : i >= l); i += stride ) {
      if ( i >= 0 ) {
        res.emplace_back(v[i]);
      } else {
        res.emplace_back(v.end()[i]);
      }
    }
    return res;
  }

  string operator()(const string &s, int l, int r = init, int stride = init) {
    assert(stride != 0);
    if ( r == init ) r = s.size();
    if ( stride == init ) stride = 1;
    string res;
    int start = (stride > 0 ? l : r - 1);
    for ( int i = start; (stride > 0 ? i < r : i >= l); i += stride ) {
      if ( i >= 0 ) {
        res.push_back(s[i]);
      } else {
        res.push_back(s.end()[i]);
      }
    }
    return res;
  }
} sliced;

void output(vector<int> v){
  for ( int i = 0; i < static_cast<int>(v.size()); i++ ) {
    if ( i ) cout << ' ';
    cout << v[i];
  }
}

int main() {
  vector<int> a = { 1, 2, 3, 4, 5 };
  output(sliced(a, 0));
  output(sliced(a, 0, 3));
  output(sliced(a, 0, 4, -1));
  output(sliced(a, -4, -1, 1));
}