#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int logarithm(ll base, ll n) {
  assert(base != 0);
  int cnt = 0;
  while (n % base == 0) {
    n /= base;
    cnt++;
  }
  return cnt;
}

int main() {
}