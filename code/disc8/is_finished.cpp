
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

template <typename Iter> bool is_finished(Iter curr, Iter last) {
  return curr == last;
}

int main() {
  vector<int> xs{1, 2, 3, 4, 5};

  for (auto it = xs.begin();; it++) {
    bool finished = is_finished(it, xs.end());
    std::cout << *it << ": " << std::boolalpha << finished << std::endl;
    if (finished) {
      break;
    }
  }

  return 0;
}