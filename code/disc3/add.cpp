#include <iostream>

int add(int x, int y) {
  return x + y;
}

int operation(int x, int y, int (*func)(int, int)) {
  return func(x, y);
}

int main() {
  int a = 5, b = 3;
  std::cout << "Add: " << operation(a, b, add) << "\n";
  return 0;
}