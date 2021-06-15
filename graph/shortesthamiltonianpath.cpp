#include <bits/stdc++.h>
using namespace std;

// 全頂点を1度だけ訪問したときの最短経路距離
// buildでinfが帰ってきたらそのような経路はない
template <typename T>
struct shortest_hamiltonian_path{
  struct edge{
    int to;
    T cost;
    edge(int to,T cost):to(to),cost(cost){}
  };

  int V;
  vector<vector<edge>> G;
  vector<vector<T>> dp;

  shortest_hamiltonian_path(int V_):V(V_),G(V_){}

  T inf(){ return numeric_limits<T>::max() / 2; }

  void add_edge(int from,int to,T cost){ G[from].emplace_back(to,cost); }

  T build(){
    T res=inf();
    dp.assign(V,vector<T>(1<<V,-1));
    for(int sv=0;sv<V;sv++){
      res=min(res,dfs(sv,1<<sv));
    }
    return res;
  }

  // private method
  T dfs(int v,int Set){
    T &res=dp[v][Set];
    if(Set+1==1<<V) res=0;
    if(res!=-1) return res;
    res=inf();
    for(auto [to,cost]:G[v]){
      int bit=1<<to;
      if(Set&bit) continue;
      res=min(res,dfs(to,Set|bit)+cost);
    }
    return res;
  }
};

int main(){
  int V,E;
  cin>>V>>E;

  shortest_hamiltonian_path<long long> G(V);
  for(int i=0;i<E;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G.add_edge(s,t,d);
  }

  int ans=G.build();
  if(ans==G.inf()) ans=-1;
  cout<<ans<<endl;
}