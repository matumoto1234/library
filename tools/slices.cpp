#include <bits/stdc++.h>
using namespace std;

struct slices {
  static constexpr int init = INT32_MAX;
  slices() {}

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
};

template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  for ( int i = 0; i < (int)v.size(); i++ ) {
    if ( i ) os << ' ';
    os << v[i];
  }
  return os;
}

void output(vector<int> v){
  for ( int i = 0; i < (int)v.size(); i++ ) {
    if ( i ) cout << ' ';
    cout << v[i];
  }
}

int main() {
  slices sl;
  vector<int> a = { 1, 2, 3, 4, 5 };
  output(sl(a, 0));
  output(sl(a, 0, 3));
  output(sl(a, 0, 4, -1));
  output(sl(a, -4, -1, 1));
}