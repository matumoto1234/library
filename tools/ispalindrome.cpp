#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string &s){
  for(int i=0;i<(int)s.size()/2;i++){
    if(s[i]!=s[(int)s.size()-1-i]) return false;
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  cout<<(is_palindrome(s)?"Yes":"No")<<endl;
}