#pragma once

#include "./base.hpp"

#include <iostream>
#include <stack>
#include <string>

namespace matumoto {
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)

  int find_comma_not_bracketed(string_view s) {
    stack<char> bs;
    string lbs = "({[", rbs = ")}]";
    for (size_t i = 0; i < s.size(); i++) {
      if (lbs.find(s[i]) != string::npos)
        bs.push(s[i]);
      if (rbs.find(s[i]) != string::npos and !bs.empty())
        bs.pop();
      if (s[i] == ',' and bs.empty())
        return i;
    }
    return s.size();
  }

  template <typename T, typename... Ts>
  void debug_function(string_view name, const T &a, Ts &&...rest) {
    int end = find_comma_not_bracketed(name);
    cerr << name.substr(0, end) << ":" << a;
    if constexpr (sizeof...(rest) == 0) {
      cerr << '\n';
    } else {
      cerr << ' ';
      debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<Ts>(rest)...);
    }
  }
} // namespace matumoto