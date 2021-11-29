#define PROBLEM "https://atcoder.jp/contests/2019yahoo_qual/tasks/2019yahoo_qual_a"
#include <bits/stdc++.h>
using namespace std;

#include "math/ceil-div.hpp"
using namespace math;

int main() {
  int n, k;
  cin >> n >> k;

  cout << (ceil_div(n, 2) >= k ? "YES" : "NO") << endl;
}