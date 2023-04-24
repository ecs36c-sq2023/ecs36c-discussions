#include <functional>
#include <iostream>
#include <vector>

template <typename T> struct Sorter {
  std::function<bool(T, T)> cmp;

  Sorter(std::function<bool(T, T)> cmp) : cmp(cmp) {}

  void sort(std::vector<T> &v) { std::sort(v.begin(), v.end(), cmp); }
};

int main() {
  std::vector<int> xs{1, 3, 2, 7, 5, 10};
  Sorter<int> sorter([](int x, int y) { return x < y; });
  sorter.sort(xs);
  for (int x : xs) {
    std::cout << x << std::endl;
  }
  return 0;
}