#include <iostream>
#include <string>

void print(int value) { std::cout << "Integer: " << value << '\n'; }

void print(double value) { std::cout << "Double: " << value << '\n'; }

void print(const std::string &value) {
  std::cout << "String: " << value << '\n';
}

int main() {
  print(42);
  print(3.14);
  print("Hello C++");
  return 0;
}
