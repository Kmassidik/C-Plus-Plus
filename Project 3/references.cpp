#include "iostream"

void increseBy100(int &ref) { ref += 100; }

int main() {
  int value = 50;
  int &alias = value;

  std::cout << "Before: value = " << value << "\n";

  alias = 200;
  std::cout << "After alias = 200 -> value = " << value << "\n";

  increseBy100(alias);
  std::cout << "After increseBy100 -> value = " << value << "\n";

  // Dangerous / invalid patterns:
  // int& bad;
  // int x = 1, y = 2;
  // alias = y;

  return 0;
}
