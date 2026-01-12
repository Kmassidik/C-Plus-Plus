// 03-object-lifetime.cpp
#include <iostream>
#include <memory>

struct Tracer {
  Tracer() { std::cout << "constructed\n"; }
  ~Tracer() { std::cout << "destroyed\n"; }
};

int main() {
  std::cout << "Block start\n";

  {
    Tracer on_stack;                           // automatic (stack) lifetime
    auto on_heap = std::make_unique<Tracer>(); // dynamic (heap) + RAII
  } // both destroyed here, in reverse order of declaration

  std::cout << "Block end\n";
  return 0;
}
