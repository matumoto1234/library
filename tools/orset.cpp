#include <bits/stdc++.h>
using namespace std;


template <typename T>
set<T> or_set(set<T> s, set<T> t) {
  set<T> res;
  for ( auto val : s ) {
    res.insert(val);
  }
  for ( auto val : t ) {
    res.insert(val);
  }
  return res;
}