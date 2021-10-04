#include <bits/stdc++.h>
using namespace std;

long long euler_phi(long long n) {
  long long res = n;
  for ( long long i = 2; i * i <= n; i++ ) {
    if ( n % i == 0 ) {
      res -= res / i;
      while ( n % i == 0 )
        n /= i;
    }
  }
  if ( n > 1 ) res -= res / n;
  return res;
}

int main() {
  long long n;
  cin >> n;
  cout << euler_phi(n) << endl;
}