#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
T1 ceil_division(T1 a, T2 b) {
  return (a + (b - 1)) / b;
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << ceil_division(x, y) << endl;
}