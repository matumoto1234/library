#include <bits/stdc++.h>
using namespace std;

template<typename Iterator>
auto counter(Iterator first, Iterator last) {
  using T = remove_reference_t<decltype(*first)>;
  map<T, int> res;
  for (auto it = first; it != last; it++) {
    T value = *it;
    res[value]++;
  }
  return res;
}

int main() {
  {
    vector<int> a = { 2, 4, 4, 3, 5, 5, 5, 5 };
    auto mp = counter(a.begin(), a.end());
    for (auto [val, cnt]: mp) {
      cout << val << ' ' << cnt << endl;
    }
  }
  {
    string s = "aaabbbcccccd";
    auto mp = counter(s.begin(), s.end());
    for (auto [val, cnt]: mp) {
      cout << val << ' ' << cnt << endl;
    }
  }
}