#include <bits/stdc++.h>
using namespace std;

template <typename T>
T mod_power(T a, T e, T p) {
  if ( e == 0 ) return 1;
  if ( e % 2 == 0 ) {
    T res = mod_power(a, e / 2, p);
    return (res * res) % p;
  }
  return (mod_power(a, e - 1, p) * a) % p;
}

int main() {
  int a;
  long long b;
  int c;
  cin >> a >> b >> c;
  cout << mod_power<long long>(a, b, c) << endl;
}