#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sptr1 = std::make_shared<int>(42);
  std::shared_ptr<int> sptr2 = sptr1;
  std::cout << *sptr1 << std::endl;

  return 0;
}
