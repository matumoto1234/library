#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gridBFS(vector<string> &s,char start,const string &wall = "#"){
  const int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
  int h=s.size(),w=s[0].size();
  vector<vector<int>> res(h,vector<int>(w,-1));
  queue<pair<int,int>> q;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]==start){
        q.emplace(i,j);
        res[i][j]=0;
      }
    }
  }
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int ny=p.first+dy[i],nx=p.second+dx[i];
      if(ny<0||nx<0||ny>=h||nx>=w) continue;
      if(res[ny][nx]!=-1) continue;
      if(wall.find(s[ny][nx])!=string::npos) continue;
      res[ny][nx]=res[p.first][p.second]+1;
      q.emplace(ny,nx);
    }
  }
  return res;
}

int main(){
  
}