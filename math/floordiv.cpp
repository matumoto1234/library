#include <bits/stdc++.h>
using namespace std;

template <typename T>
T floor_div(T n, T d) {
  assert(d != 0);
  return n / d - (((n ^ d) < 0) && (n % d));
}

int main() {
  int n,d;
  cin>>n>>d;
  cout<<floor_div(n,d)<<endl;
}