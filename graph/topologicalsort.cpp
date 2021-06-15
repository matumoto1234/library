#include <bits/stdc++.h>
using namespace std;

struct topological_sort{
  vector<int> in_degree;
  vector<vector<int>> G;

  topological_sort(int V):G(V),in_degree(V,0){}

  void add_edge(int from,int to){
    G[from].emplace_back(to);
    in_degree[to]++;
  }

  vector<int> build(){
    int V=G.size();
    queue<int> q;
    for(int i=0;i<V;i++){
      if(in_degree[i]==0) q.push(i);
    }

    vector<int> res;
    while(!q.empty()){
      int v=q.front();
      q.pop();
      res.emplace_back(v);
      for(int to:G[v]){
        in_degree[to]--;
        if(in_degree[to]==0) q.push(to);
      }
    }

    return res;
  }
};

int main(){
  int V,E;
  cin>>V>>E;

  topological_sort G(V);

  for(int i=0;i<E;i++){
    int s,t;
    cin>>s>>t;
    G.add_edge(s,t);
  }

  auto vs=G.build();
  for(int i=0;i<vs.size();i++){
    cout<<vs[i]<<'\n';
  }
}