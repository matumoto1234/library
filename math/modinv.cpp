#include<bits/stdc++.h>
using namespace std;

// n and MOD are coprime
template <typename T1,typename T2>
T1 modinv(T1 n,T2 MOD){
  using ll = long long;
  function<T1(ll,ll,ll&,ll&)> extgcd = [&](ll a,ll b,ll &x,ll &y){
    if(b==0){
      x=1;
      y=0;
      return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
  };

  auto mod = [&](ll N){ return (N%MOD+MOD)%MOD; };

  ll X,Y;
  extgcd(n,MOD,X,Y);
  return mod(X);
}

int main(){
  using ll = long long;
  ll n;
  cin>>n;

  const int M=1e9+7;
  ll inv=modinv(n,M);

  ll result=(inv*n)%M;
  assert(result==1);
  cout<<result<<endl;
}