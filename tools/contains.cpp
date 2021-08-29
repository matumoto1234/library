#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool contains(const vector<T> &vs, T value) {
  for ( auto v : vs ) {
    if ( value == v ) return true;
  }
  return false;
}

bool contains(const string &s, char ch){
  for ( auto c : s ) {
    if ( c == ch ) return true;
  }
  return false;
}