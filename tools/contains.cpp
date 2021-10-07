#include <bits/stdc++.h>
using namespace std;

#define contains(container, x) (find(begin(container), end(container), x) != end(container))

int main() {
  vector<int> a = { 4, 2, 5, 10 };

  if (contains(a, 10)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  if (contains(a, 1)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}