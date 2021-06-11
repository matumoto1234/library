#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct CumulativeSum{
  vector<T> sum;
  CumulativeSum(){}
  CumulativeSum(const vector<T> &a){
    build(a);
  }

  void build(const vector<T> &a){
    sum.assign(a.size()+1,0);
    for(int i=0;i<(int)a.size();i++) sum[i+1]=a[i]+sum[i];
  }

  T query(int l,int r){ return sum[r]-sum[l]; }
};

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  CumulativeSum<int> sum(a);

  cout<<sum.query(0,n)<<endl;
}