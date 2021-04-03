#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

struct Sieve{
  vector<bool> prime_table;

  Sieve(int N):prime_table(N+1,true){
    prime_table[0]=prime_table[1]=false;
  }

  void build(){
    int n=prime_table.size();
    for(long long i=2;i<n;i++){
      if(!prime_table[i]) continue;
      for(long long j=i*i;j<n;j+=i){
        prime_table[j]=false;
      }
    }
  }

  bool operator[](int k){ return prime_table[k]; }
};