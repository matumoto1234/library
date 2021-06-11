#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <typename T>
class fenwick_tree{
private:
  vector<T> dat;
  T query(int idx){
    T res=0;
    for(int i=idx;i>=0;i=(i&(i+1))-1){
      res+=dat[i];
    }
    return res;
  }
public:
  fenwick_tree(int n):dat(n+1,0){}

  void add(int idx,T v){
    int n=dat.size();
    for(int i=idx;i<n;i|=i+1){
      dat[i]+=v;
    }
  }

  // [l, r)
  T sum(int l,int r){
    return query(r)-query(l-1);
  }
};

template <typename T>
long long inversion(vector<T> vs){
  int n=vs.size();
  long long res=0;
  fenwick_tree<long long> ft(n+1);
  for(T v : vs){
    assert(v<=n);
    res+=ft.sum(v+1, n);
    ft.add(v,1);
  }
  return res;
}

template <typename T>
vector<T> compress(vector<T> a){
  vector<T> res=a;
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  for(T &v:res){
    v=lower_bound(a.begin(),a.end(),v)-a.begin();
  }
  return res;
}

// AOJ_ALDS1_5_D
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int &A:a) cin>>A;
  a=compress(a);
  cout<<inversion(a)<<endl;
}