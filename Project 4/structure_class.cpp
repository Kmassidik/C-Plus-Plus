#include <cstdlib> // for std::abs   ← you were missing this
#include <iostream>
#include <stdexcept>

struct Point {
  int x = 0;
  int y = 0;

  Point(int x = 0, int y = 0) : x(x), y(y) {}

  int manhattan_distance_to(const Point &other) const {
    return std::abs(x - other.x) + std::abs(y - other.y);
  }
};

class Rectangle {
private:
  int width_;
  int height_;

public:
  Rectangle(int w, int h) : width_(w), height_(h) {
    if (w <= 0 || h <= 0) {
      throw std::invalid_argument("width and height must be positive");
    }
  }

  int area() const { return width_ * height_; }

  int width() const { return width_; }
  int height() const { return height_; }

  void resize(int new_w, int new_h) {
    if (new_w <= 0 || new_h <= 0) {
      throw std::invalid_argument("new dimensions must be positive");
    }
    width_ = new_w;
    height_ = new_h;
  }
};

int main() {
  Point p{3, 4};
  std::cout << "Point: (" << p.x << ", " << p.y << ")\n";

  try {
    Rectangle r(10, 5);
    std::cout << "Rectangle area: " << r.area() << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  std::cout << "Everything worked correctly.\n";
  return 0;
}
