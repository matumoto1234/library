#include <bits/stdc++.h>
using namespace std;

template <typename iter>
vector<int> sorted_index(const iter &first, const iter &last) {
  auto tmp = *first;
  vector<decltype(tmp)> a(first, last);
  vector<int> res(a.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  return res;
}

int main() {
  vector<int> a = { 3, 1, 4, 1, 5 };
  auto idxs = sorted_index(a.begin(), a.end());
  // expected : 1, 3, 0, 2, 4
  for ( auto idx : idxs ) {
    cout << idx << ' ';
  }
  cout << endl;
}