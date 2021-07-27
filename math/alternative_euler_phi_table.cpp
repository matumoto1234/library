#include <bits/stdc++.h>
using namespace std;

struct prime_factor_table {
  vector<int> ps;
  prime_factor_table() {}

  void build(int N) {
    ps.assign(N + 1, 1);
    for ( long long i = 2; i <= N; i++ ) {
      if ( ps[i] != 1 ) continue;
      ps[i] = i;
      for ( long long j = i * i; j <= N; j += i ) {
        if ( ps[j] != 1 ) continue;
        ps[j] = i;
      }
    }
  }

  vector<int> factorize(int x) {
    vector<int> res;
    while ( ps[x] != 1 ) {
      res.push_back(ps[x]);
      x /= ps[x];
    }
    return res;
  }

  bool is_prime(int k) {
    if ( k <= 1 ) return false;
    return ps[k] == k;
  }

  int operator[](int i) { return ps[i]; }
};

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for ( T v : vs )
    res[v]++;
  return res;
}

template <typename T>
T floor_div(T n, T d) {
  assert(d != 0);
  return n / d - (((n ^ d) < 0) && (n % d));
}


// Θ(NlogN)
vector<int> alternative_euler_phi_table(int n) {
  prime_factor_table table;
  table.build(n);

  vector<int> alt(n + 1, 0);
  for ( int i = 1; i <= n; i++ )
    alt[i] = n - i;

  for ( int i = 2; i <= n; i++ ) {
    // O(logN)
    map<int, int> ps = counter(table.factorize(i));

    bool is_square = false;
    for ( auto [p, cnt] : ps ) {
      if ( cnt >= 2 ) {
        is_square = true;
        break;
      }
    }
    if ( is_square ) continue;

    for ( int j = i; j < n; j += i ) {
      if ( ps.size() % 2 )
        alt[j] -= floor_div(n - j, i);
      else
        alt[j] += floor_div(n - j, i);
    }
  }
  return alt;
}

int main() {
  int n;
  cin >> n;

  vector<int> ans = alternative_euler_phi_table(n);

  for ( int i = 1; i < (int)ans.size() - 1; i++ ) {
    cout << ans[i] << "\n";
  }
}