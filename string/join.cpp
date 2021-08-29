#include <bits/stdc++.h>
using namespace std;

string join(const vector<string> &strs, const string &sep) {
  string res = "";
  for ( int i = 0; i < (int)strs.size(); i++ ) {
    if ( i ) res += sep;
    res += strs[i];
  }
  return res;
}

int main() {
}