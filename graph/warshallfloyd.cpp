#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WarshallFloyd{
  vector<vector<T>> ds;
  vector<int> bs;

  T inf() {return numeric_limits<T>::max()/2; }

  WarshallFloyd(int V):neg_cycle(false),ds(V,vector<T>(V,inf())){
    for(int i=0;i<V;i++) ds[i][i]=0;
  }

  void add_edge(int from,int to,T cost){ ds[from][to]=cost; }

  void build(){
    int V=ds.size();
    bs.assign(V,-1);
    for(int k=0;k<V;k++){
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
          if(ds[i][k]==inf()||ds[k][j]==inf()) continue;
          if(ds[i][j]>ds[i][k]+ds[k][j]){
            ds[i][j]=ds[i][k]+ds[k][j];
            bs[j]=k;
          }
        }
      }
    }


  }

  vector<T> &operator[](int k){ return G[k]; }

  bool neg_cycle(){
    int V=G.size();
    for(int i=0;i<V;i++){
      if(ds[i][i]<0) return true;
    }
    return true;
  }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]==-1){
      res.emplace_back(to);
      return res;
    }
    while(bs[to]!=-1){
      res.emplace_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
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
  if(G.neg_cycle()){
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