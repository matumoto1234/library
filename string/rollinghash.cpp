#include<bits/stdc++.h>
using namespace std;

// MOD:2^61-1, B:1e9+7
template<typename T = long long,long long MOD = (1LL<<61)-1,T B = 1000000007>
struct RollingHash{
  using i128 = __int128_t;
  static constexpr long long mod = MOD;
  static constexpr T base = B;
  vector<T> hash,cumulative_sum,inv;
  RollingHash(vector<T> vals){build(vals);}
  RollingHash(string &s){
    vector<T> vals;
    for(char c:s) vals.emplace_back(c);
    build(vals);
  }

  // mod multiprecation
  T modMul(T a,T b){
    i128 res=a;
    res*=b;
    res=(res >> 61) + (res & mod);
    if(res >= mod) res-=mod;
    return (T)res;
  }

  T pow(T a,i128 e){
    if(e==0) return 1;
    if(e%2==0){
      T res=pow(a,e/2);
      return modMul(res,res);
    }
    return modMul(pow(a,e-1),a);
  }

  void build(vector<T> vals){
    int n=vals.size();
    hash.assign(n,0);
    cumulative_sum.assign(n+1,0);
    inv.assign(n+1,0);
    i128 e=mod-2;
    inv[n]=pow(base,n*e);
    for(int i=n-1;i>=0;i--) inv[i]=modMul(inv[i+1],base);
    for(int i=0;i<n;i++) hash[i]=modMul(vals[i],pow(base,i));
    for(int i=0;i<n;i++) cumulative_sum[i+1]=(hash[i]+cumulative_sum[i])%mod;
  }

  // [l,r)
  long long find(int l,int r){
    T res=cumulative_sum[r]-cumulative_sum[l];
    if(res<0) res+=mod;
    res=modMul(res,inv[l]);
    return (long long)res;
  }
};

// AOJ_ALDS1_14_B
int main(){
  string s,t;
  cin>>s>>t;

  RollingHash a(s);
  RollingHash b(t);

  int n=s.size(),m=t.size();
  for(int i=0;i<n-m+1;i++){
    if(a.find(i,i+m)==b.find(0,m)){
      cout<<i<<'\n';
    }
  }
}