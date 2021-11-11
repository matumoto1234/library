#include <bits/stdc++.h>
using namespace std;

template <typename F>
struct fix_point : F {
  fix_point(F and f) noexcept : F{ forward<F>(f) } {}

  template <typename... Args>
  decltype(auto) operator()(Args and ...args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F>
inline decltype(auto) make_fix_point(F and f) {
  return fix_point<F>{ forward<F>(f) };
}

int main() {
  int n;
  cin >> n;
  auto result = make_fix_point([](auto f, int n) -> int {
    if ( n < 2 ) return n;
    return f(n - 1) + f(n - 2);
  })(n);
  cout << result << endl;
}