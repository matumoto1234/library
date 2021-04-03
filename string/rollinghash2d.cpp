#include<bits/stdc++.h>
using namespace std;

// MOD:2^61-1, B1:1e9+7, B2:1e8+7
template <typename T = long long,long long MOD = (1LL<<61)-1,T B1 = 1000000007,T B2 = 100000007>
struct RollingHash2D{
  using i128 = __int128_t;
  static constexpr long long mod = MOD;
  static constexpr T base1 = B1;
  static constexpr T base2 = B2;
  struct CumulativeSum2D{
    vector<vector<T>> data;
    CumulativeSum2D(){}
    CumulativeSum2D(int H,int W):data(H+1,vector<T>(W+1,0)){}

    void set(int y,int x,T v){ data[y+1][x+1]+=v; }

    void build(){
      for(int i=1;i<(int)data.size();i++){
        for(int j=1;j<(int)data[i].size();j++){
          data[i][j]+=(data[i][j-1]+data[i-1][j]-data[i-1][j-1])%mod;
          if(data[i][j]<0) data[i][j]+=mod;
        }
      }
    }

    // [ (sy,sx), (gy,gx) )
    T query(int sy,int sx,int gy,int gx){
      T res=(data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx])%mod;
      if(res<0) res+=mod;
      return res;
    }
  };

  CumulativeSum2D cumulative_sum;
  vector<vector<T>> inv;
  RollingHash2D(vector<vector<T>> vals){ build(vals); }
  RollingHash2D(vector<string> &s){
    vector<vector<T>> vals(s.size());
    for(int i=0;i<(int)s.size();i++){
      for(int j=0;j<(int)s[0].size();j++){
        T val=s[i][j]%mod;
        if(val<0) val+=mod;
        vals[i].emplace_back(val);
      }
    }
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

  void build(vector<vector<T>> vals){
    int h=vals.size(),w=vals[0].size();
    inv.assign(h+1,vector<T>(w+1,0));
    cumulative_sum.data.assign(h+1,vector<T>(w+1,0));
    i128 e=mod-2;
    inv[h][w]=modMul(pow(base1,h*e),pow(base2,w*e));
    for(int i=h-1;i>=0;i--) inv[i][w]=modMul(inv[i+1][w],base1);
    for(int j=w-1;j>=0;j--) inv[h][j]=modMul(inv[h][j+1],base2);
    for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--){
      inv[i][j]=modMul(inv[i+1][j+1],base1);
      inv[i][j]=modMul(inv[i][j],base2);
    }
    for(int i=0;i<h;i++) for(int j=0;j<w;j++){
      T val=modMul(vals[i][j],pow(base1,i));
      val=modMul(val,pow(base2,j));
      cumulative_sum.set(i,j,val);
    }
    cumulative_sum.build();
  }

  long long find(int sy,int sx,int gy,int gx){
    return (long long)modMul(cumulative_sum.query(sy,sx,gy,gx),inv[sy][sx]);
  }
};

// AOJ_ALDS1_14_C
int main(){
  int h1,w1;
  cin>>h1>>w1;
  vector<string> s(h1);
  for(int i=0;i<h1;i++) cin>>s[i];

  int h2,w2;
  cin>>h2>>w2;
  vector<string> t(h2);
  for(int i=0;i<h2;i++) cin>>t[i];

  RollingHash2D S(s);
  RollingHash2D T(t);

  for(int i=0;i<h1-h2+1;i++) for(int j=0;j<w1-w2+1;j++){
    if(S.find(i,j,i+h2,j+w2)==T.find(0,0,h2,w2)){
      cout<<i<<' '<<j<<'\n';
    }
  }
}