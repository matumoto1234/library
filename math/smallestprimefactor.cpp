#include <bits/stdc++.h>
using namespace std;

class SmallestPrimeFactor {
public:
  vector<int> ps;
  SmallestPrimeFactor(int N):ps(N + 1,1){
    build();
  }

  vector<int> factorize(int x){
    vector<int> res;
    while(ps[x]!=1){
      res.push_back(ps[x]);
      x/=ps[x];
    }
    return res;
  }

  bool is_prime(int k){ return ps[k]==k; }

  int operator[](int i){ return ps[i]; }

private:
  void build() {
    for (long long i = 2; i < ps.size(); i++) {
      if (ps[i] != 1) continue;
      ps[i] = i;
      for (long long j = i * i; j < ps.size(); j += i) {
        if (ps[j] != 1) continue;
        ps[j] = i;
      }
    }
  }
};