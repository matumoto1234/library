#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s){
  for(int i=0;i<(int)s.size()/2;i++){
    if(s[i]!=s[(int)s.size()-1-i]) return false;
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  cout<<(isPalindrome(s)?"Yes":"No")<<endl;
}