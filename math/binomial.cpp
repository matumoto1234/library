#include<bits/stdc++.h>
using namespace std;

template <typename T>
T Binomial(T n,T r){
  T res=1;
  for(T1 i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

int main(){
  int n,r;
  cin>>n>>r;
  cout<<Binomial(n,r)<<endl;
}