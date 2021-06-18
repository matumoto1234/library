#include <bits/stdc++.h>
using namespace std;

template <typename T>
T binomial(T n, T r) {
  T res = 1;
  for ( T i = 0; i < r; i++ ) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  int n, r;
  cin >> n >> r;
  cout << binomial(n, r) << endl;
}