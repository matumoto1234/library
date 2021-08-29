#include <bits/stdc++.h>
using namespace std;

// recomend:{ MOD:2^61-1, base1,base2:random }
struct rolling_hash_2d {
  using i128 = __int128_t;
  using ll = long long;
  ll mod, base1, base2;
  struct cumulative_sum_2d {
    vector<vector<ll>> data;
    cumulative_sum_2d() {}

    void set(int y, int x, ll v) { data[y + 1][x + 1] = v; }

    void build(ll mod) {
      for ( int i = 1; i < (int)data.size(); i++ ) {
        for ( int j = 1; j < (int)data[i].size(); j++ ) {
          data[i][j] += (data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1]) % mod;
          if ( data[i][j] < 0 ) data[i][j] += mod;
        }
      }
    }

    // [ (sy,sx), (gy,gx) )
    ll query(int sy, int sx, int gy, int gx, ll mod) {
      ll res = (data[gy][gx] - data[gy][sx] - data[sy][gx] + data[sy][sx]) % mod;
      if ( res < 0 ) res += mod;
      return res;
    }
  };

  cumulative_sum_2d sum;
  vector<vector<ll>> dat, inv;
  rolling_hash_2d(const vector<vector<ll>> &vs, ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL << 61) - 1) : dat(vs) {
    set_base(B1, B2);
    set_mod(MOD);
  }
  rolling_hash_2d(const vector<string> &s, ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL << 61) - 1) {
    set_base(B1, B2);
    set_mod(MOD);
    dat.resize(s.size());
    for ( int i = 0; i < (int)s.size(); i++ ) {
      for ( char c : s[i] ) {
        dat[i].emplace_back(c);
      }
    }
  }

  void set_mod(ll M) { mod = M; }
  void set_base(ll B1, ll B2) { base1 = B1, base2 = B2; }

  // mod multiprecation
  ll mod_mul(ll a, ll b) {
    i128 res = a;
    res *= b;
    res = (res >> 61) + (res & mod);
    if ( res >= mod ) res -= mod;
    return (ll)res;
  }

  ll pow(ll a, i128 e) {
    if ( e == 0 ) return 1;
    if ( e % 2 == 0 ) {
      ll res = pow(a, e / 2);
      return mod_mul(res, res);
    }
    return mod_mul(pow(a, e - 1), a);
  }

  void build() {
    int h = dat.size(), w = dat[0].size();
    inv.assign(h + 1, vector<ll>(w + 1, 0));
    sum.data.assign(h + 1, vector<ll>(w + 1, 0));
    vector<ll> pow_table1(h + 1), pow_table2(w + 1);

    i128 e = mod - 2;
    inv[h][w] = mod_mul(pow(base1, h * e), pow(base2, w * e));
    pow_table1[0] = 1;
    pow_table2[0] = 1;

    for ( int i = h - 1; i >= 0; i-- ) {
      pow_table1[h - i] = mod_mul(base1, pow_table1[h - i - 1]);
      inv[i][w] = mod_mul(base1, inv[i + 1][w]);
    }
    for ( int j = w - 1; j >= 0; j-- ) {
      pow_table2[w - j] = mod_mul(base2, pow_table2[w - j - 1]);
      inv[h][j] = mod_mul(base2, inv[h][j + 1]);
    }
    for ( int i = h - 1; i >= 0; i-- ) {
      for ( int j = w - 1; j >= 0; j-- ) {
        inv[i][j] = mod_mul(inv[i + 1][j + 1], base1);
        inv[i][j] = mod_mul(inv[i][j], base2);
      }
    }
    for ( int i = 0; i < h; i++ ) {
      for ( int j = 0; j < w; j++ ) {
        ll val = mod_mul(dat[i][j], pow_table1[i]);
        val = mod_mul(val, pow_table2[j]);
        sum.set(i, j, val);
      }
    }
    sum.build(mod);
  }

  ll find(int sy, int sx, int gy, int gx) {
    return mod_mul(sum.query(sy, sx, gy, gx, mod), inv[sy][sx]);
  }
};

template <typename T>
struct Random {
  mt19937 mt;
  Random() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  // [a, b)
  T operator()(T a, T b) {
    uniform_int_distribution<T> dist(a, b - 1);
    return dist(mt);
  }

  // [0, b)
  T operator()(T b) { return (*this)(0, b); }
};

// AOJ_ALDS1_14_C
int main() {
  int h1, w1;
  cin >> h1 >> w1;
  vector<string> s(h1);
  for ( int i = 0; i < h1; i++ )
    cin >> s[i];

  int h2, w2;
  cin >> h2 >> w2;
  vector<string> t(h2);
  for ( int i = 0; i < h2; i++ ) {
    cin >> t[i];
  }

  using ll = long long;
  Random<ll> rnd;
  ll base1 = rnd(2, (1LL << 61) - 1 - 2);
  ll base2 = rnd(2, (1LL << 61) - 1 - 2);

  rolling_hash_2d S(s, base1, base2);
  rolling_hash_2d T(t, base1, base2);

  S.build();
  T.build();

  for ( int i = 0; i < h1 - h2 + 1; i++ ) {
    for ( int j = 0; j < w1 - w2 + 1; j++ ) {
      if ( S.find(i, j, i + h2, j + w2) == T.find(0, 0, h2, w2) ) {
        cout << i << ' ' << j << '\n';
      }
    }
  }
}