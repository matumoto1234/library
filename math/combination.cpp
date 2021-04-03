#include<bits/stdc++.h>
using namespace std;

template <typename T1,typename T2>
T1 combination(T1 n,T2 r){
  T1 res=1;
  for(T1 i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

int main(){
  int n,r;
  cin>>n>>r;
  cout<<combination(n,r)<<endl;
}