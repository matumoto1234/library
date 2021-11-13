#include <bits/stdc++.h>
using namespace std;

template<typename T>
T ceil_div(T n, T d) {
  assert(d != 0);
  return n / d + ((n ^ d >= 0) and (n % d));
}

int main() {
  int x, y;
  cout << ceil_div(x, y) << endl;
}