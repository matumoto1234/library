#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &str, const string &sep) {
  vector<string> res;
  string t = "";
  for ( auto c : str ) {
    if ( sep.find(c) == string::npos ) {
      t += c;
      continue;
    }
    res.emplace_back(t);
    t = "";
  }
  if ( t != "" ) res.emplace_back(t);
  return res;
}

vector<string> split(const string &str, int k) {
  assert(k >= 1);
  int cnt = 0;
  vector<string> res;
  string t = "";
  for ( auto c : str ) {
    cnt++;
    t += c;
    if ( cnt >= k ) {
      res.emplace_back(t);
      cnt = 0;
      t = "";
    }
  }
  if ( t != "" ) res.emplace_back(t);
  return res;
}