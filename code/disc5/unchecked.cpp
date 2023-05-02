// from
// https://stanford-cs242.github.io/f19/lectures/07-1-traits.html#comparison-with-c-templates
#include <iostream>

template <typename T> void print(T t) { t.print(); }

class Foo {
public:
  void print() { std::cout << "Foo"; }
};

int main() {
  print(Foo());
  return 0;
}