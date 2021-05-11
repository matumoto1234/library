#include<bits/stdc++.h>
using namespace std;

template <typename T = long long>
vector<T> divisor(T n){
  vector<T> res;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res.emplace_back(i);
      if(i*i!=n) res.emplace_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main(){
  long long n;
  cin>>n;
  vector<long long> v=divisor(n);
  for(int i=0;i<(int)v.size();i++){
    if(i) cout<<' ';
    cout<<v[i];
  }
  cout<<'\n';
}