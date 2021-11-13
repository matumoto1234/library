#include <bits/stdc++.h>
using namespace std;

template<typename F>
struct FixPoint: F {
  FixPoint(F &&f) noexcept: F{ forward<F>(f) } {}

  template<typename... Args>
  decltype(auto) operator()(Args &&...args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
inline decltype(auto) make_fix_point(F &&f) {
  return FixPoint<F>{ forward<F>(f) };
}

int main() {
  int n;
  cin >> n;
  auto result = make_fix_point([](auto f, int n) -> int {
    if (n < 2) return n;
    return f(n - 1) + f(n - 2);
  })(n);
  cout << result << endl;
}