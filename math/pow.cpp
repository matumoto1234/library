#include<bits/stdc++.h>
using namespace std;

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

int main(){
  int a;
  long long b;
  cin>>a>>b;
  cout<<Pow(a,b)<<endl;
}