#include <iostream>

namespace MyNameSpace {
int value = 42;
}

int main() {
  std::cout << MyNameSpace::value << std::endl;
  return 0;
}
