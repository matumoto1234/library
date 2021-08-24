#include <bits/stdc++.h>
using namespace std;


template <typename T>
set<T> and_set(set<T> s, set<T> t) {
  if ( s.size() < t.size() ) swap(s, t);
  set<T> res;
  for ( auto val : s ) {
    if ( t.find(val) != t.end() ) res.insert(val);
  }
  return res;
}