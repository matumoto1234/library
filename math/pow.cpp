#include <bits/stdc++.h>
using namespace std;

template <typename T>
T power(T a, T e, T p = 0) {
  if ( p <= 1 ) return 0;
  if ( p == 0 ) p = numeric_limits<T>::max();
  T res = 1;
  while ( e > 0 ) {
    if ( e & 1 ) res = (res * a) % p;
    a = (a * a) % p;
    e >>= 1;
  }
  return res;
}

// AOJ_NTL_1_B
int main() {
  long long a, b;
  cin >> a >> b;
  cout << power(a, b, (long long)1e9 + 7) << endl;
}