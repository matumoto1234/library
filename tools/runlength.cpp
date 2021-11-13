#include <bits/stdc++.h>
using namespace std;

template<typename iter>
auto runlength(iter first, iter last) {
  vector<pair<decltype(*first), int>> res;
  for (auto it = first; it != last; it++) {
    if (res.empty() or res.back().first != *it) res.emplace_back(*it, 0);
    res.back().second++;
  }
  return res;
}

int main() {
  {
    vector<int> a = { 1, 1, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4 };
    auto ps = runlength(a.begin(), a.end());
    for (auto p: ps) {
      cout << p.first << ' ' << p.second << endl;
    }
  }

  {
    string s = "<>>><<<<<<>>";
    auto ps = runlength(s.begin(), s.end());
    for (auto p: ps) {
      cout << p.first << ' ' << p.second << endl;
    }
  }
}