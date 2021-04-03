#include<bits/stdc++.h>
using namespace std;

// bool is_valid(T mid, T target)
template <class T,bool (*is_valid)(T, T)>
struct BinarySearch{
  T valid_;
  T invalid_;
  BinarySearch(){}
  BinarySearch(T v,T iv):valid_(v),invalid_(iv){}

  void set_valid(T v,T iv){
    valid_=v;
    invalid_=iv;
  }

  T build(T target){
    auto valid=valid_;
    auto invalid=invalid_;

    while(abs(invalid-valid)>1){
      auto mid = (valid + invalid) / 2;
      if (is_valid(mid,target)) valid = mid;
      else invalid = mid;
    }
    return valid;
  }
};

vector<int> s;

bool is_valid(int m,int t){
  return s[m]<=t;
}

// AOJ_ALDS1_4_B
int main(){
  int n;
  cin>>n;
  s.resize(n);
  for(int i=0;i<n;i++) cin>>s[i];
  int q;
  cin>>q;
  int ans=0;
  BinarySearch<int,is_valid> bs(-1,n);
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    int idx=bs.build(t);
    ans+=(s[idx]==t);
  }
  cout<<ans<<endl;
}