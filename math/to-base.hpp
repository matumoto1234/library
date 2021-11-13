#include <bits/stdc++.h>
using namespace std;

// decimal n -> b-ary
template <typename T>
vector<T> to_base(T n, T b) {
  if (n == 0 or b <= 1) return vector<T>{ 0 };
  vector<T> res;
  for (; n > 0; n /= b) {
    res.emplace_back(n % b);
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n, b;
  cin >> n >> b;

  vector<int> base_b = to_base(n, b);

  for (int v: base_b) {
    cout << v;
  }
  cout << endl;
}