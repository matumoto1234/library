#include<bits/stdc++.h>
using namespace std;

template <unsigned long long BASE>
struct baseint{
  using ull = unsigned long long;
  using ll = long long;

  const ll base=BASE;
  const ll base_digit=(ll)log10(BASE);
  deque<ll> dat;
  int sign; // 1 or -1
  baseint():sign(1){}
  baseint(ll v){ *this=v; }

  ll digit(){ return (ll)dat.size(); }

  void trimming(){
    while(!dat.empty() && dat.back()==0) dat.pop_back();
    if(dat.empty()) sign=1;
  }

  void read(const string &s){
    sign=1;
    dat.clear();
    ll idx=0;
    while(idx<(ll)s.size() && (s[idx]=='-' || s[idx]=='+')){
      if(s[idx]=='-') sign=-sign;
      idx++;
    }
    for(l i=s.size()-1;i>=idx;i-=base_digit){
      ll x=0;
      for(ll j=max(idx,i-base_digit+1);j<=i;j++) x=x*10+s[j]-'0';
      dat.emplace_back(x);
    }
    trimming();
  }

  baseint<BASE> abs() const {
    baseint<BASE> res=*this;
    res.sign=1;
    return res;
  }

  void operator=(ll v){
    dat.clear();
    sign=1;
    if(v<0) sign=-1,v=-v;
    while(v>0){
      dat.emplace_back(v%base);
      v/=base;
    }
  }

  // datにvを足していく
  baseint<BASE> operator+(const baseint<BASE> &v) const {
    if(sign!=v.sign) return *this-(-v);

    baseint<BASE> res=*this;
    bool carry=0;
    ll N=max(dat.size(),v.dat.size());
    for(ll i=0;i<N || carry;i++){
      if(i==(ll)res.dat.size()) res.dat.emplace_back(0);
      res.dat[i]+=(i<(ll)v.dat.size()?v.dat[i]:0)+carry;
      carry=(res.dat[i]>=base);
      if(carry) res.dat[i]%=base;
    }
    return res;
  }

  // datからvを引いていく
  baseint<BASE> operator-(const baseint<BASE> &v) const {
    if(sign!=v.sign) return *this+(-v);
    if(abs()<v.abs()) return -(v-*this);

    baseint<BASE> res=*this;
    bool carry=0;
    ll N=max(dat.size(),v.dat.size());
    for(ll i=0;i<N || carry;i++){
      res.dat[i]-=(i<(ll)v.dat.size()?v.dat[i]:0)+carry;
      carry=(res.dat[i]<0);
      if(carry) res.dat[i]+=base;
    }
    res.trimming();
    return res;
  }

  baseint<BASE> operator-() const {
    baseint<BASE> res=*this;
    res.sign=-sign;
    return res;
  }

  baseint<BASE> operator*(ll v) const {
    baseint<BASE> res=*this;
    res*=v;
    return res;
  }

  void operator*=(ll v){
    if(v<0) sign=-sign,v=-v;
    ll carry=0;
    for(ll i=0;i<(ll)dat.size() || carry;i++){
      if(i==(ll)dat.size()) dat.emplace_back(0);
      ll cur=dat[i]*(ll)v+carry;
      carry=(ll)(cur/base);
      dat[i]=(ll)(cur%base);
    }
    trimming();
  }

  bool operator<(const baseint<BASE> &v) const {
    if(sign!=v.sign) return sign<v.sign;
    if(dat.size()!=v.dat.size()) return dat.size()*sign<v.dat.size()*v.sign;
    for(ll i=dat.size()-1;i>=0;i--){
      if(dat[i]!=v.dat[i]) return dat[i]*sign<v.dat[i]*v.sign;
    }
    return false;
  }

  friend istream &operator>>(istream &is,const baseint<BASE> &v){
    string s;
    is>>s;
    v.read(s);
    return is;
  }

  friend ostream &operator<<(ostream &os,const baseint<BASE> &v){
    if(v.sign==-1) os<<'-';
    for(int i=v.dat.size()-1;i>=0;i--) os<<v.dat[i];
    return os;
  }
};


int main(){
  int n;
  cin>>n;
  baseint<2> bi(n);
  int m;
  cin>>m;
  baseint<2> bi2(m);
  cout<<bi-bi2<<endl;
}