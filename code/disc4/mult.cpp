#include <iostream>
#include <functional>

int multiply(int x, int y) {
  return x * y;
}

int operation(int x, int y, std::function<int(int, int)> func) {
  return func(x, y);
}

std::function<int(int, int)> get_mult() {
  return multiply;
}

int main() {
  int a = 5, b = 3;
  std::function<int(int, int)> mul_f = get_mult();
  std::cout << "Multiply: " << operation(a, b, mul_f) << "\n";
  return 0;
}