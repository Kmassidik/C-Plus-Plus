#include <iostream>
#include <memory>

void safe_no_leak() {
  auto data = std::make_unique<int[]>(10000);
  // automatically freed at end of scope (RAII)
  // You can even use the array here if needed:
  // data[0] = 42;
}

void classic_leak() {
  // int* data = new int[10000];     // allocates 40 KB
  // never deleted → memory leak every call
  // repeated calls in loop → program slowly consumes all available RAM
}

int main() {
  for (int i = 0; i < 10000; ++i) { // increased iterations to make leak obvious
    safe_no_leak();
    // classic_leak();              // uncomment → will eventually crash / OOM
  }

  std::cout << "Done (no leak with smart pointers)\n";
  return 0;
}
