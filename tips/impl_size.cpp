#include <bits/stdc++.h>

template <class T> constexpr auto size(const T &t) -> decltype(t.size()) {
  return t.size();
}
int main() {
  std::vector<int> v = {3, 1, 4};
  std::cout << size(v) << '\n';

  int a[] = {-5, 10, 15};
  std::cout << size(a) << '\n';
}
