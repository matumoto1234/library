#include <bits/stdc++.h>
using namespace std;

template <typename T>
class interval_scheduling {
  vector<pair<T, T>> intervals_;
  vector<bool> used;

public:
  interval_scheduling() {}

  void add_interval(T l, T r) { intervals_.emplace_back(l, r); }

  int inf() { return numeric_limits<int>::max() / 2; }

  void build() {
    used.assign(intervals_.size(), false);

    sort(intervals_.begin(), intervals_.end(), [](pair<T, T> a, pair<T, T> b) {
      if (a.second != b.second) return a.second < b.second;
      return a.first < b.first;
    });

    int last = -inf();
    for (size_t i = 0; i < intervals_.size(); i++) {
      auto [l, r] = intervals_[i];

      if (last <= l) {
        used[i] = true;
        last = r;
      }
    }
  }

  bool is_used(int k) { return used[k]; }

  vector<pair<T, T>> intervals() {
    vector<pair<T, T>> res;
    for (size_t i = 0; i < intervals_.size(); i++) {
      if (!used[i]) continue;
      res.emplace_back(intervals_[i]);
    }
    return res;
  }
};

// https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
int main() {
  int n;
  cin >> n;

  interval_scheduling<int> vs;

  for (int i = 0; i < n; i++) {
    int x, l;
    cin >> x >> l;

    vs.add_interval(x - l, x + l);
  }

  vs.build();

  cout << vs.intervals().size() << endl;
}