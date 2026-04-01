#include <exception>
#include <iostream>
#include <pthread.h>
#include <stdexcept>
#include <vector>

double devide(double a, double b) {
  if (b == 0.0) {
    throw std::runtime_error("Division by zero!");
  }
  return a / b;
}

int main() {
  try {
    std::cout << devide(10.0, 2.0) << '\n';
    std::cout << devide(10.0, 0.0) << '\n';
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }

  std::cout << "Program continues  after handling exception...\n";
  return 0;
}
