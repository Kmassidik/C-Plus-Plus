// 03-new-delete-deep.cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age;

  Person(std::string n, int a) : name(std::move(n)), age(a) {
    std::cout << "Person " << name << " constructed\n";
  }

  ~Person() { std::cout << "Person " << name << " destroyed\n"; }
};

// ── Modern patterns ─────────────────────────────────────────────

void modern_single_object() {
  auto p = std::make_unique<Person>("Alice", 28);
  std::cout << p->name << " is " << p->age << "\n";
}

void modern_dynamic_array() {
  auto scores = std::make_unique<int[]>(1000);
  scores[0] = 95;

  // Almost always prefer this instead
  std::vector<int> v_scores(1000, 0);
  v_scores[0] = 95;
}

// Fixed: use deduced return type (cleanest)
auto create_person() { return std::make_unique<Person>("Factory Bob", 35); }

void modern_ownership_transfer() {
  auto employee = create_person(); // ownership transferred safely
  std::cout << "Employee: " << employee->name << "\n";
}

// ── Dangerous legacy patterns (commented out) ───────────────────

void classic_leaky_single() {
  Person *p = new Person("Leak Charlie", 40);

  // Simulate conditional leak
  // if (some_condition()) { return; }  // ← leak if uncommented without delete

  delete p;
}

void classic_array_mismatch() {
  int *data = new int[500];
  // delete data;           // WRONG – must be delete[] → heap corruption
  delete[] data; // correct legacy style
}

int main() {
  std::cout << "=== Modern style ===\n";
  modern_single_object();
  modern_ownership_transfer();

  std::cout << "\n=== Legacy patterns (commented out) ===\n";
  // classic_leaky_single();
  // classic_array_mismatch();

  std::cout << "\nDone — no manual delete needed\n";
  return 0;
}
