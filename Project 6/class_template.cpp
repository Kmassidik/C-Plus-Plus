#include <iostream>

// Simple Pair class template
template <typename T1, typename T2> class Pair {
private:
  T1 first;
  T2 second;

public:
  Pair(const T1 &f, const T2 &s) : first(f), second(s) {}

  void print() const { std::cout << "(" << first << ", " << second << ")\n"; }

  T1 getFirst() const { return first; }
  T2 getSecond() const { return second; }
};

int main() {
  Pair<int, double> p1(10, 3.14);
  Pair<std::string, std::string> p2("key", "value");

  p1.print();
  p2.print();
  return 0;
}
