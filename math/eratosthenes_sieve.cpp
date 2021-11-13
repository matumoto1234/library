#include <bits/stdc++.h>
using namespace std;

struct EratosthenesSieve {
  vector<bool> prime_table;

  EratosthenesSieve() {}
  EratosthenesSieve(int N): prime_table(N + 1, true) { prime_table[0] = prime_table[1] = false; }

  void build() {
    int n = prime_table.size();
    for (long long i = 2; i * i < n; i++) {
      if (!prime_table[i]) continue;
      for (long long j = i * i; j < n; j += i) {
        prime_table[j] = false;
      }
    }
  }

  bool operator[](int k) { return prime_table[k]; }
};

int main() {
  int n;
  cin >> n;
  EratosthenesSieve sieve(n);
  sieve.build();

  for (int i = 0; i < static_cast<int>(sieve.prime_table.size()); i++) {
    if (sieve.prime_table[i]) { cout << i << ' '; }
  }
  cout << endl;
}