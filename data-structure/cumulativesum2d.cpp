#include<iostream>
#include<vector>
using namespace std;

template <class T>
struct CumulativeSum2D{
  vector<vector<T>> data;
  CumulativeSum2D(int H,int W):data(H+1,vector<T>(W+1,0)){}

  void set(int y,int x,T v){ data[y+1][x+1]+=v; }

  void build(){
    for(int i=1;i<(int)data.size();i++){
      for(int j=1;j<(int)data[i].size();j++){
        data[i][j]+=data[i][j-1]+data[i-1][j]-data[i-1][j-1];
      }
    }
  }

  // [ (sy,sx), (gy,gx) )
  T query(int sy,int sx,int gy,int gx){
    return data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx];
  }
};

int main(){
  int h,w;
  cin>>h>>w;
  CumulativeSum2D<int> r(h,w);
  vector<vector<int>> a(h,vector<int> (w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      r.set(i,j,a[i][j]);
    }
  }
  r.build();
  for(int i=0;i<=h;i++){
    for(int j=0;j<=w;j++){
      cout<<r.query(0,0,i,j)<<' ';
    }
    cout<<endl;
  }
  return 0;
}