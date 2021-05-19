#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
  int cnt;
  vector<int> siz,par;
  UnionFind(int N):cnt(N),siz(N,1),par(N){
    iota(par.begin(),par.end(),0);
  }

  int root(int x){
    if(x==par[x]) return x;
    return par[x]=root(par[x]);
  }

  int group_count(){ return cnt; }

  int size(int x){ return siz[root(x)]; }

  bool same(int x,int y){ return root(x)==root(y); }

  void merge(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    cnt--;
  }

  /*
  vector<int> same_group_count(const UnionFind &uf){
    for(int i=0;i<(int)par.size();i++){
      
    }
  }
  */
};