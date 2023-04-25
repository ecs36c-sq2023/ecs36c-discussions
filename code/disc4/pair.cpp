#include <iostream>
#include <utility>

bool cmp(int a, int b) { return a < b; }

template <typename T>
bool cmp_pair(std::pair<int, T> a, std::pair<int, T> b) {
  return a.first < b.first;
}

int main() {
  std::pair<int, std::string> p1(1, "hello");
  std::pair<int, std::string> p2(2, "world");
  std::cout << cmp_pair(p1, p2) << std::endl;
  return 0;
}