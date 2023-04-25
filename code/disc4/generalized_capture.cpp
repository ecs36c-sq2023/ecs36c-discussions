#include <functional>
#include <iostream>
#include <vector>

std::function<int()> sum(std::vector<int> xs) {
  auto f = [ys = std::move(xs)] {
    int sum = 0;
    for (int y : ys) {
      sum += y;
    }
    return sum;
  };
  std::cout << "captured xs len: " << xs.size() << "\n";
  return f;
}

int main() {
  std::vector<int> xs({1, 2, 3, 4, 5});
  auto f = sum(xs);
  
  std::cout << "Sum: " << f() << "\n";
  std::cout << "xs len: " << xs.size() << "\n";

  return 0;
}