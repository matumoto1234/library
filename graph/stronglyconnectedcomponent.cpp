#include <bits/stdc++.h>
using namespace std;

struct SCC{
  vector<vector<int>> G,rG;
  vector<int> scc;
  vector<int> post_order;
  vector<bool> arrived;

  int cnt;

  SCC(int V):G(V),rG(V){}

  void add_edge(int from,int to){
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
  }

  int build(){
    int V=G.size();
    arrived.assign(V,false);

    for(int i=0;i<V;i++){
      if(arrived[i]) continue;
      dfs(i);
    }

    cnt=0;
    scc.assign(V,0);
    arrived.assign(V,false);

    for(int i=V-1;i>=0;i--){
      int idx=post_order[i];
      if(arrived[idx]) continue;
      rdfs(idx,cnt);
      cnt++;
    }
    return cnt;
  }

  void dfs(int idx){
    arrived[idx]=true;
    for(int to:G[idx]){
      if(arrived[to]) continue;
      dfs(to);
    }
    post_order.emplace_back(idx);
  }

  void rdfs(int idx,int num){
    arrived[idx]=true;
    scc[idx]=num;
    for(int to:rG[idx]){
      if(arrived[to]) continue;
      rdfs(to,num);
    }
  }

  int size() { return cnt; }

  bool issame(int a,int b){ return scc[a]==scc[b]; }

  int operator[](int k){ return scc[k]; }
};


int main(){
  int V,E;
  cin>>V>>E;

  SCC G(V);
  for(int i=0;i<E;i++){
    int s,t;
    cin>>s>>t;
    G.add_edge(s,t);
  }

  G.build();

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    cout<<(int)(G[a]==G[b])<<'\n';
  }
}