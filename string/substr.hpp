#include <bits/stdc++.h>
using namespace std;

string substr(const string &s, int l, int r) {
  string res = "";
  for (int i = l; i < r; i++) {
    res += s[i];
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << substr(s, 1, s.size() - 1) << endl;
}