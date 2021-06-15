#include <bits/stdc++.h>
using namespace std;

template <typename vec>
vector<vec> rot_clockwise_2d(vector<vec> &s){
  int h=s.size(),w=s[0].size();
  vector<vec> res(w);
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      res[i].push_back(s[h-1-j][i]);
    }
  }
  return res;
}

template <typename vec>
vector<vec> rot_counterclockwise_2d(vector<vec> &s){
  int h=s.size(),w=s[0].size();
  vector<vec> res(w);
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      res[i].push_back(s[j][w-1-i]);
    }
  }
  return res;
}

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];

  vector<string> s2 = rot_clockwise_2d(s);
  for(int i=0;i<(int)s2.size();i++){
    cout<<s2[i]<<endl;
  }

  s2 = rot_counterclockwise_2d(s);
  for(int i=0;i<(int)s2.size();i++){
    cout<<s2[i]<<endl;
  }
}