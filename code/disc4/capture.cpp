#include <iostream>

int main() {
  int x = 5;

  // Capture nothing
  // auto f0 = [](int y) {
  //   return x + y;
  // };

  // Capture by value
  auto f1 = [=](int y) {
    return x + y;
  };

  // Capture by reference
  auto f2 = [&](int y) {
    x++;
    return x + y;
  };

  int y = f2(3);
  std::cout << "x: " << x << "\n";
  std::cout << "y: " << y << "\n";
  return 0;
}