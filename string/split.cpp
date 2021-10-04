#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &str, const string &sep,
    const int &max_split = INT32_MAX) {
  vector<string> res;
  string t = "";
  int cnt_split = 0;
  for ( auto c : str ) {
    if ( sep.find(c) != string::npos and cnt_split < max_split ) {
      res.emplace_back(t);
      t = "";
      cnt_split++;
      continue;
    }
    t += c;
  }
  if ( t != "" ) res.emplace_back(t);
  return res;
}

int main() {
  string s = "1,2,3,4,5";

  {
    vector<string> t = split(s, ",");
    for ( auto element : t ) {
      cout << element << endl;
    }
  }

  cout << "--------" << endl;

  {
    vector<string> t = split(s, ",", 3);
    for ( auto element : t ) {
      cout << element << endl;
    }
  }
}