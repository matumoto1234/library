#include <bits/stdc++.h>
using namespace std;

// 1-indexed
template <typename T>
class fenwick_tree {
private:
  int n;
  vector<T> dat;

  // [1,r]
  T sum(int r){
    T res=0;
    for(int k=r;k>0;k-=(k&-k)){
      res+=dat[k];
    }
    return res;
  }
public:
  fenwick_tree(int n_):n(n_+1),dat(n_+1,0){}

  void add(int i,T x){
    for(int k=i;k<n;k+=(k&-k)){
      dat[k]+=x;
    }
  }

  // [l,r)
  T sum(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  // min({x | sum(x) >= w})
  int lower_bound(T w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int len=r;len>0;len>>=1){
      if(x+len<n && dat[x+len]<w){
        w-=dat[x+len];
        x+=len;
      }
    }
    x++;
    return x;
  }

  // min({x | sum(x) > w})
  int upper_bound(T w){
    return lower_bound(w+1);
  }
};

// arc033_C
int main(){
  int q;
  cin>>q;

  fenwick_tree<int> tree(200000);
  for(int i=0;i<q;i++){
    int t,x;
    cin>>t>>x;
    if(t==1){
      tree.add(x,1);
    }else{
      int v=tree.lower_bound(x);
      cout<<v<<endl;
      tree.add(v,-1);
    }
  }
}