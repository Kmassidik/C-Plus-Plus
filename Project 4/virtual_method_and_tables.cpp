#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ────────────────────────────────────────────────
// Base with virtual interface
// ────────────────────────────────────────────────
class Animal {
public:
  Animal() = default;

  // Rule #1: virtual destructor = must-have
  virtual ~Animal() = default;

  // Pure virtual → Animal is abstract
  virtual void make_sound() const = 0;

  // Regular virtual with default
  virtual std::string get_type() const { return "Generic Animal"; }

  // Non-virtual → always calls this version (static binding)
  void print_identity() const {
    std::cout << "I am at address: " << this << "\n";
  }
};

// ────────────────────────────────────────────────
// Derived – note final + override everywhere
// ────────────────────────────────────────────────
class Dog final : public Animal {
public:
  void make_sound() const override { std::cout << "Woof!\n"; }

  std::string get_type() const override { return "Dog"; }
};

class Cat final : public Animal {
public:
  void make_sound() const override { std::cout << "Meow.\n"; }

  std::string
  get_type() const override final { // final → nobody can override this again
    return "Cat";
  }
};

// ────────────────────────────────────────────────
// Polymorphic usage – the classic pattern
// ────────────────────────────────────────────────
int main() {
  std::vector<std::unique_ptr<Animal>> zoo;

  zoo.emplace_back(std::make_unique<Dog>());
  zoo.emplace_back(std::make_unique<Cat>());
  zoo.emplace_back(std::make_unique<Dog>());

  std::cout << "=== Zoo sounds & types ===\n";
  for (const auto &animal : zoo) {
    std::cout << animal->get_type() << " says: ";
    animal->make_sound();     // ← dynamic dispatch here
    animal->print_identity(); // ← static dispatch
    std::cout << "----------------------------------------\n";
  }

  // Demonstrate safe polymorphic deletion
  // No leak, no UB — because virtual dtor
  zoo.clear();

  return 0;
}
