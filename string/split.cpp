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