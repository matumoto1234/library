#include <bits/stdc++.h>
using namespace std;

// 1-indexed
template <typename T>
class range_fenwick_tree {
private:
  int n;
  vector<T> dat[2];

  void init(int n_){
    n=n_+1;
    for(int p=0;p<2;p++) dat[p].assign(n,0);
  }

  void internal_add(int p,int i,T x){
    for(int k=i;k<n;k+=k&-k){
      dat[p][k]+=x;
    }
  }

  T internal_sum(int p,int i){
    T res=0;
    for(int k=i;k>0;k-=k&-k){
      res+=dat[p][k];
    }
    return res;
  }

  // [1,r)
  T sum(int r){
    r--;
    return internal_sum(0,r)+internal_sum(1,r)*r;
  }
public:
  range_fenwick_tree(int n_){init(n_);}

  // [l, r)
  void add(int l,int r,T x){
    internal_add(0,l,-x*(l-1));
    internal_add(0,r,x*(r-1));
    internal_add(1,l,x);
    internal_add(1,r,-x);
  }

  // [l,r)
  T sum(int l,int r){
    return sum(r)-sum(l);
  }
};

int main(){
  int n,q;
  cin>>n>>q;
  range_fenwick_tree<int> tree(n);
  for(int i=0;i<q;i++){
    int ord;
    cin>>ord;
    if(ord==0){
      int s,t,x;
      cin>>s>>t>>x;
      t++;
      tree.add(s,t,x);
    }else{
      int p;
      cin>>p;
      cout<<tree.sum(p,p+1)<<endl;
    }
  }
}