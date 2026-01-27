// oop_four_principles.cpp
// g++ -std=c++17 -Wall -Wextra oop_four_principles.cpp -o oop4 && ./oop4

#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// ======================================================================
// 1. ENCAPSULATION
//    → data + behavior together, hide internal state, protect invariants
// ======================================================================
class Employee {
private:
  std::string name_;
  double base_salary_;
  double bonus_multiplier_ = 1.0;

  // invariant: salary never negative
  void validate_salary(double s) const {
    if (s < 0) {
      throw std::invalid_argument("Salary cannot be negative");
    }
  }

public:
  Employee(std::string name, double base_salary)
      : name_(std::move(name)), base_salary_(base_salary) {
    validate_salary(base_salary_);
  }

  // controlled access + validation
  void set_bonus_multiplier(double m) {
    if (m < 0.5 || m > 2.5) {
      throw std::invalid_argument(
          "Bonus multiplier must be between 0.5 and 2.5");
    }
    bonus_multiplier_ = m;
  }

  double calculate_total_pay() const {
    return base_salary_ * bonus_multiplier_;
  }

  std::string get_name() const { return name_; }
  double get_base_salary() const { return base_salary_; }
};

// ======================================================================
// 2. INHERITANCE
//    → code reuse + "is-a" relationship
// ======================================================================
class Developer final : public Employee {
private:
  int lines_of_code_per_day_;

public:
  Developer(std::string name, double base_salary, int loc_per_day)
      : Employee(std::move(name), base_salary),
        lines_of_code_per_day_(loc_per_day) {
    if (loc_per_day < 0)
      throw std::invalid_argument("LOC cannot be negative");
  }

  // reusing base behavior + adding specific one
  double calculate_total_pay() const {
    // inheritance allows calling base logic if needed
    double base = Employee::calculate_total_pay();
    double productivity_bonus = lines_of_code_per_day_ * 0.05;
    return base + productivity_bonus;
  }

  int get_productivity() const { return lines_of_code_per_day_; }
};

// ======================================================================
// 3. POLYMORPHISM (runtime)
//    → same interface → different behavior depending on real type
// ======================================================================
class PaymentProcessor {
public:
  virtual ~PaymentProcessor() = default;
  virtual std::string process(double amount) const = 0;
};

class CreditCardProcessor final : public PaymentProcessor {
public:
  std::string process(double amount) const override {
    if (amount <= 0)
      throw std::invalid_argument("Amount must be positive");
    return "Credit card processed: $" + std::to_string(amount) +
           " (2.1% fee applied)";
  }
};

class PayPalProcessor final : public PaymentProcessor {
public:
  std::string process(double amount) const override {
    if (amount <= 0)
      throw std::invalid_argument("Amount must be positive");
    return "PayPal processed: $" + std::to_string(amount) +
           " (3.4% + $0.30 fee applied)";
  }
};

// ======================================================================
// 4. ABSTRACTION
//    → hide implementation details, expose only essential interface
// ======================================================================
class PayrollSystem {
private:
  std::vector<std::unique_ptr<Employee>> employees_;
  std::unique_ptr<PaymentProcessor> payment_processor_;

public:
  PayrollSystem(std::unique_ptr<PaymentProcessor> processor)
      : payment_processor_(std::move(processor)) {
    if (!payment_processor_) {
      throw std::invalid_argument("Payment processor required");
    }
  }

  void add_employee(std::unique_ptr<Employee> emp) {
    employees_.push_back(std::move(emp));
  }

  void run_payroll() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=== Payroll Report ===\n";

    double total_payout = 0.0;

    for (const auto &emp : employees_) {
      double pay = emp->calculate_total_pay();
      total_payout += pay;

      std::cout << emp->get_name() << " (base: $" << emp->get_base_salary()
                << ") → $" << pay << "\n";
    }

    std::cout << "Total payout: $" << total_payout << "\n";

    std::string result = payment_processor_->process(total_payout);
    std::cout << "Payment result: " << result << "\n";
  }
};

// ──────────────────────────────────────────────────────────────────────────

int main() {
  try {
    // 4. Abstraction: we don't care which processor is used
    auto payroll = PayrollSystem(std::make_unique<CreditCardProcessor>());

    // 2. Inheritance + 1. Encapsulation
    payroll.add_employee(std::make_unique<Developer>("Alice", 6500.0, 180));
    payroll.add_employee(std::make_unique<Employee>("Bob", 5200.0));

    // 3. Polymorphism: different pay calculation logic
    payroll.run_payroll();

    std::cout << "\n--- With PayPal instead ---\n";

    // swap payment processor → abstraction in action
    auto payroll2 = PayrollSystem(std::make_unique<PayPalProcessor>());
    payroll2.add_employee(std::make_unique<Developer>("Charlie", 7200.0, 220));
    payroll2.run_payroll();

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
