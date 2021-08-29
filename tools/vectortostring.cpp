#include <bits/stdc++.h>
using namespace std;

template <typename T>
string vector_to_string(const vector<T> &vs, const string &sep = " ") {
  stringstream ss;
  ss << boolalpha;
  for ( int i = 0; i < (int)vs.size(); i++ ) {
    if ( i ) ss << sep;
    ss << vs[i];
  }
  return ss.str();
}

int main() {
  vector<bool> vs = { false, true, false };
  cout << vector_to_string(vs) << endl;
}