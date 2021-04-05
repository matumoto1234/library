#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WarshallFloyd{
  bool neg_cycle;
  vector<vector<T>> G;

  T inf() {return numeric_limits<T>::max()/2; }

  WarshallFloyd(int V):neg_cycle(false),G(V,vector<T>(V,inf())){
    for(int i=0;i<V;i++) G[i][i]=0;
  }

  void add_edge(int from,int to,T cost){ G[from][to]=cost; }

  void build(){
    int V=G.size();
    for(int k=0;k<V;k++){
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
          if(G[i][k]==inf()||G[k][j]==inf()) continue;
          G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
        }
      }
    }

    for(int i=0;i<V;i++){
      if(G[i][i]<0){
        neg_cycle=true;
        break;
      }
    }
  }

  vector<T> &operator[](int k){ return G[k]; }
};

int main() {
  int V,E;
  cin>>V>>E;
  WarshallFloyd<long long> G(V);
  for(int i=0;i<E;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G.add_edge(s,t,d);
  }
  G.build();
  if(G.neg_cycle){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  }

  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(G[i][j]==G.inf()){
        cout<<"INF";
      }else{
        cout<<G[i][j];
      }
      cout<<(j==V-1?"\n":" ");
    }
  }
}