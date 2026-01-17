#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> uptr = std::make_unique<int>(42);
  std::cout << *uptr << std::endl;
  return 0;
}
