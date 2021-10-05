#include <bits/stdc++.h>
using namespace std;

#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2>
void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < len(name); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos and !bs.empty() ) bs.pop();
    if ( name[i] == ',' and bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}

int main() {
  int a = 5;
  string s = "hello";
  debug(a, s);
}