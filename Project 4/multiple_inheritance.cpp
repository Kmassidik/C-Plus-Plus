#include <iostream>
#include <memory>
#include <string>

// ────────────────────────────────────────────────
// Pattern 1: Multiple pure abstract bases (safe, interface-like)
// ────────────────────────────────────────────────
class Drawable {
public:
  virtual ~Drawable() = default;
  virtual void draw() const = 0;
};

class Clickable {
public:
  virtual ~Clickable() = default;
  virtual void on_click() const = 0;
};

// OK: class inherits behavior contracts, no data clash
class Button final : public Drawable, public Clickable {
public:
  void draw() const override {
    std::cout << "[Button] Rendering rounded rectangle + text\n";
  }

  void on_click() const override {
    std::cout << "[Button] Trigger action: Save document\n";
  }
};

// ────────────────────────────────────────────────
// Pattern 2: Diamond problem – WRONG way (non-virtual)
// ────────────────────────────────────────────────
class Engine {
public:
  int horsepower = 200;
  void start() { std::cout << "Engine started\n"; }
};

class Wheels {
public:
  int count = 4;
};

class Car : public Engine, public Wheels { // no diamond yet
};

class ElectricCar : public Car { // ← diamond!
  // Now two Engine subobjects → ambiguity
public:
  void status() {
    // Error: ambiguous access to horsepower
    // std::cout << horsepower << "\n";     // compile error
  }
};

// ────────────────────────────────────────────────
// Pattern 3: Diamond problem – CORRECT way (virtual inheritance)
// ────────────────────────────────────────────────
class Vehicle {
public:
  int weight_kg = 1500;
  virtual ~Vehicle() = default;
};

class Motorized : virtual public Vehicle { // ← virtual here
protected:
  int fuel_capacity_l = 60;
};

class Wheeled : virtual public Vehicle { // ← virtual here too
protected:
  int wheel_count = 4;
};

// Now only ONE Vehicle subobject
class HybridSUV final : public Motorized, public Wheeled {
public:
  void report() const {
    std::cout << "Weight: " << weight_kg << " kg\n" // unambiguous
              << "Wheels: " << wheel_count << "\n"
              << "Fuel:   " << fuel_capacity_l << " L\n";
  }
};

int main() {
  std::cout << "=== Safe multiple inheritance (interfaces) ===\n";
  Button btn;
  btn.draw();
  btn.on_click();

  std::cout << "\n=== Diamond with virtual inheritance ===\n";
  HybridSUV suv;
  suv.report();

  // This would fail without virtual inheritance:
  // std::cout << suv.horsepower << "\n";  // ambiguous if non-virtual

  return 0;
}
