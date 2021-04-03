#include<bits/stdc++.h>
using namespace std;

template <typename T1,typename T2,typename T3>
T1 modPow(T1 a,T2 e,T3 p){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=modPow(a,e/2,p);
    return (res*res)%p;
  }
  return (modPow(a,e-1,p)*a)%p;
}

int main(){
  int a;
  long long b;
  int c;
  cin>>a>>b>>c;
  cout<<modPow(a,b,c)<<endl;
}