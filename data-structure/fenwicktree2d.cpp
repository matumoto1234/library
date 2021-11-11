#include <bits/stdc++.h>
using namespace std;

// 1-indexed
template <typename T>
class fenwick_tree_2d {
private:
  int H, W;
  vector<vector<T>> dat;

  // 1<=i<=y 1<=j<=x
  T internal_sum(int y, int x) {
    T res = 0;
    for ( int i = y; i > 0; i -= (i & -i) ) {
      for ( int j = x; j > 0; j -= (j & -j) ) {
        res += dat[i][j];
      }
    }
    return res;
  }

public:
  fenwick_tree_2d() {}
  fenwick_tree_2d(int H_, int W_) { init(H_, W_); }
  void init(int H_, int W_) {
    H = H_ + 1;
    W = W_ + 1;
    dat.assign(H, vector<T>(W, 0));
  }

  // {h,w} += x
  void add(int h, int w, T x) {
    assert(1 <= h and h <= H and 1 <= w and w <= W);
    for ( int i = h; i < H; i += (i & -i) ) {
      for ( int j = w; j < W; j += (j & -j) ) {
        dat[i][j] += x;
      }
    }
  }

  // [{sy,sx}, {gy,gx})
  T sum(int sy, int sx, int gy, int gx) {
    assert(1 <= sy and sy <= H and 1 <= sx and sx <= W and 2 <= gy and gy <= H + 1 and 2 <= gx and gx <= W + 1);
    return internal_sum(gy - 1, gx - 1) - internal_sum(gy - 1, sx - 1) - internal_sum(sy - 1, gx - 1) + internal_sum(sy - 1, sx - 1);
  }

  T get(int y, int x) { return sum(y, x, y + 1, x + 1); }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n));
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      cin >> d[i][j];
    }
  }

  fenwick_tree_2d<int> ft(n, n);
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      ft.add(i + 1, j + 1, d[i][j]);
    }
  }

  vector<int> vs(n * n, 0);

  for ( int i = 1; i <= n; i++ ) {
    for ( int j = 1; j <= n; j++ ) {
      for ( int k = i + 1; k <= n + 1; k++ ) {
        for ( int l = j + 1; l <= n + 1; l++ ) {
          int area = (k - i) * (l - j);
          vs[area] = max(vs[area], ft.sum(i, j, k, l));
        }
      }
    }
  }

  int q;
  cin >> q;
  for ( int i = 0; i < q; i++ ) {
    int p;
    cin >> p;
    int ans = 0;
    for ( int j = 0; j <= p; j++ ) {
      ans = max(ans, vs[j]);
    }

    cout << ans << endl;
  }
}