#include <iostream>

int main() {
  {
    int scopedVar = 42;
    std::cout << scopedVar << std::endl;
  }

  return 0;
}
