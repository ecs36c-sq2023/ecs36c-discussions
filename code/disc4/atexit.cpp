#include <stdlib.h>
#include <iostream>

void bye(void){
  std::cout << "That works!\n";
}

int main() {
  atexit(bye);

  std::cout << "Hello World!\n";
  return 0;
}