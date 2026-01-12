#include <iostream>
using namespace std;

void demoLifetime() {
  int autoVar = 1;
  static int staticVar = 2;
  cout << "Inside function: auto=" << autoVar << " static=" << staticVar++
       << "\n";
}

int main() {
  cout << "First call:\n";
  demoLifetime();
  cout << "Second call:\n";
  demoLifetime();

  int *dyn = new int(42);
  cout << "Dynamic object: " << *dyn << "\n";
  delete dyn;

  return 0;
}
