#include<bits/stdc++.h>
using namespace std;

template <typename T>
class WeightedUnionFind{
public:
  WeightedUnionFind(){}
  WeightedUnionFind(int N):par(N),siz(N,1),w(N,0){
    for(int i=0;i<N;i++){
      par[i]=i;
    }
  }

  void init(int N){
    par.assign(N,0);
    siz.assign(N,1);
    w.assign(N,0);
    for(int i=0;i<N;i++){
      par[i]=i;
    }
  }

  bool same(int x,int y){
    return root(x)==root(y);
  }

  void unite(int x,int y,T z){
    z+=weight(x);
    z-=weight(y);
    x=root(x);
    y=root(y);
    if(x==y) return;
    if(x<y){
      swap(x,y);
      z=-z;
    }
    siz[x]+=siz[y];
    par[y]=x;
    w[y]=z;
  }

  int size(int x){
    return siz[x];
  }

  T diff(int x,int y){
    return weight(y)-weight(x);
  }

private:
  vector<int> par;
  vector<int> siz;
  vector<T> w;

  int root(int x){
    if(x==par[x]) return x;
    int rx=root(par[x]);
    w[x]+=w[par[x]];
    par[x]=rx;
    return rx;
  }

  T weight(int x){
    root(x);
    return w[x];
  }
};