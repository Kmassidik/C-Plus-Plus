#include <iostream>

// Function template
template <typename T> T maxValue(const T &a, const T &b) {
  return (a > b) ? a : b;
}

// you can also use 'class' instead of 'typename' (same thing)
template <class T> void printTwice(const T &value) {
  std::cout << value << " " << value << '\n';
}

int main() {
  std::cout << maxValue(5, 12) << '\n';      // T = int
  std::cout << maxValue(3.14, 2.71) << '\n'; // T = double
  printTwice("Hello");                       // T = const char*
  printTwice(std::string("C++"));            // T = std::string
  return 0;
}
