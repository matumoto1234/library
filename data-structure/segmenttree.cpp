#include<iostream>
#include<vector>
#include<cstdint>
#include<limits>
using namespace std;

// 0-indexed
template <typename T> class segment_tree{
private:
  vector<T> t;
  T len;

  T inf() {return numeric_limits<T>::max();}

  T search(const int& l,const int& r,int i,int now_l,int now_r){
    if(r<=now_l||now_r<=l) return inf();
    if(l<=now_l&&now_r<=r) return t[i];

    T lv=search(l,r,i*2+1,now_l,(now_l+now_r)/2);
    T rv=search(l,r,i*2+2,(now_l+now_r)/2,now_r);
    return min(lv,rv);
  }

public:
  segment_tree(int siz){
    len=1;
    while(len<siz){
      len*=2;
    }
    t.assign(len+len-1,inf());
  }

  void init(int siz){
    len=1;
    while(len<siz){
      len*=2;
    }
    t.assign(len+len-1,inf());
  }

  void update(int i,T key){
    i+=len-1;
    t[i]=key;
    while(i>0){
      i=(i-1)/2;
      t[i]=min(t[i*2+1],t[i*2+2]);
    }
  }

  /* [l,r) */
  T find(const int& l,const int& r){
    return search(l,r,0,0,len);
  }
};

int main(){
  int n,q;
  cin>>n>>q;
  segment_tree<int> segt(n);
  for(int i=0;i<q;i++){
    int com,x,y;
    cin>>com>>x>>y;
    if(com==0){
      segt.update(x,y);
    }else{
      cout<<segt.find(x,y+1)<<endl;
    }
  }
  return 0;
}