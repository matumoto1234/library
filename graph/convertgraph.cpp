#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> convertGraph(const vector<string> &s){
  int h=s.size(),w=s[0].size();
  const int dy[]={1,0,-1,0},dx[]={0,1,0,-1};
  vector<vector<int>> res(h*w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int from=i*h+j;
      for(int k=0;k<4;k++){
        int ny=i+dy[k],nx=j+dx[k];
        if(ny<0||nx<0||h<=ny||w<=nx) continue;
        int to=ny*h+j;
        res[from].push_back(to);
      }
    }
  }
  return res;
}

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }

  auto G=convertGraph(s);
  for(int i=0;i<h*w;i++){
    cout<<"i:"<<i<<' ';
    for(int to:G[i]){
      cout<<to<<' ';
    }
    cout<<'\n';
  }
}