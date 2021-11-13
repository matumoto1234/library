#include <bits/stdc++.h>
using namespace std;

namespace helper {
  template <typename T>
  class HasIterator {
    template <typename Container>
    static true_type test(typename Container::iterator *);

    template <typename Container>
    static false_type test(...);

  public:
    static const bool value = decltype(test<T>(0))::value;
  };

  template <typename Container, typename T>
  class HasFind {
    template <typename InnerContainer,
              int dummy = (static_cast<typename enable_if<HasIterator<InnerContainer>::value, InnerContainer>::type::iterator (InnerContainer::*)(const T &)>(&InnerContainer::find), 0)>
    static true_type check(InnerContainer *);
    static false_type check(...);
    static Container *container;

  public:
    static const bool value = decltype(check(container))::value;
  };
} // namespace helper

template <typename Container, typename T>
bool contains(const Container &container, const T &x) {
  if constexpr (helper::HasFind<Container, T>::value) {
    return container.find(x) != end(container);
  } else {
    return find(begin(container), end(container), x) != end(container);
  }
}

int main() {
  cout << boolalpha;

  {
    cout << "set-------------" << endl;
    set<int> s;
    s.insert(10);
    cout << contains(s, 10) << endl;
    cout << contains(s, 3) << endl;
  }
  {
    cout << "map-------------" << endl;
    map<int, int> mp;
    mp[2] = 3;
    cout << contains(mp, 3) << endl;
    cout << contains(mp, 2) << endl;
  }
  {
    cout << "vector-------------" << endl;
    vector<int> vs = { 1, 4, 3 };
    cout << contains(vs, 5) << endl;
    cout << contains(vs, 4) << endl;
    cout << contains(vs, 1) << endl;
  }
  {
    // expect : string uses std::find
    cout << "string-------------" << endl;
    string s = "341";
    cout << contains(s, '5') << endl;
    cout << contains(s, '4') << endl;
    cout << contains(s, '1') << endl;
  }
}