#include <bits/stdc++.h>
using namespace std;

vector<int> count_factor(int N) {
  constexpr int INF = INT32_MAX / 2;
  vector<int> table(N + 1, 0);

  for ( int i = 2; i <= N; i++ ) {
    if ( table[i] ) continue;
    table[i] = 1;
    for ( int j = 2 * i; j <= N; j += i ) {
      if ( j % (i * i) == 0 )
        table[j] = -INF;
      else
        table[j]++;
    }
  }
  return table;
}

// Θ(NloglogN)
vector<int> alternative_euler_phi_table(int N) {
  vector<int> table = count_factor(N);

  vector<int> alt(N + 1, 0);
  alt[1] = N;
  for ( int i = 2; i <= N; i++ ) {
    alt[i] = N - i;
  }

  for ( int i = 2; i <= N; i++ ) {
    if ( table[i] < 0 ) continue;

    for ( int j = i; j < N; j += i ) {
      if ( table[i] % 2 ) {
        alt[j] -= (N - j) / i;
      } else {
        alt[j] += (N - j) / i;
      }
    }
  }
  return alt;
}