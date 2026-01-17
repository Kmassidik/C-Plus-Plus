#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sptr = std::make_shared<int>(42);
  std::weak_ptr<int> wptr = sptr;
  if (auto locked = wptr.lock()) {
    std::cout << *locked << std::endl;
  }

  return 0;
}
