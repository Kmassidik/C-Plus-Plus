#include <cerrno>
#include <ios>
#include <iostream>
#include <ostream>
#include <sched.h>

class Point {
public:
  int x, y;

  Point(int x = 0, int y = 0) : x(x), y(y) {}

  // Overload + operator (binary)
  Point operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
  }

  // Overload == operator
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }

  // Overload << for easy printing (friend so it can access private if needed)
  friend std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

int main() {
  Point p1(2, 3);
  Point p2(4, 5);

  Point p3 = p1 + p2;
  std::cout << "p1 + p2 = " << p3 << '\n';

  std::cout << "p1 == p2? " << std::boolalpha << (p1 == p2) << '\n';
  return 0;
}
