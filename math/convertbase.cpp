#include <bits/stdc++.h>
using namespace std;

// from-ary n -> to-ary n
template<typename T>
vector<T> convert_base(vector<T> n, T from, T to) {
  auto to_base = [&](T n, T b) {
    if (n == 0 or b <= 1) return vector<T>{ 0 };
    vector<T> res;
    for (; n > 0; n /= b) {
      res.emplace_back(n % b);
    }
    reverse(res.begin(), res.end());
    return res;
  };

  auto to_decimal = [&](vector<T> n, T b) {
    T res = 0, x = 1;
    for (int i = n.size() - 1; i >= 0; i--, x *= b) {
      res += x * (n[i]);
    }
    return res;
  };

  T temp = to_decimal(n, from);
  return to_base(temp, to);
}

int main() {
  // 2-ary 101
  vector<int> a = { 1, 0, 1 };

  vector<int> decimals = convert_base(a, 2, 10);

  for (int v: decimals) {
    cout << v << endl;
  }
}