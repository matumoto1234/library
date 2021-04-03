#include<bits/stdc++.h>
using namespace std;

template <typename T>
T extgcd(T a,T b,T &x,T &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  T d=extgcd(b,a%b,y,x);
  y=y-(a/b)*x;
  return d;
}

int main(){
  long long a,b;
  cin>>a>>b;
  long long x,y;
  extgcd(a,b,x,y);
  cout<<x<<' '<<y<<endl;
}