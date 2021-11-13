#include <bits/stdc++.h>
using namespace std;

template<typename Iterator>
vector<int> sorted_index(Iterator first, Iterator last) {
  using T = remove_reference_t<decltype(*first)>;
  vector<T> a(first, last);
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
  for (auto idx: idxs) {
    cout << idx << ' ';
  }
  cout << endl;
}