#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Abstract base -defines the interfaces
class PaymentMethod {
public:
  virtual ~PaymentMethod() = default;

  // Returns: success message or throws on failure
  virtual std::string pay(double amount) const = 0;

  // fol logging / receipt
  virtual std::string get_name() const = 0;

  // Non-virtual utility (static binding)
  void log_transaction(double amount) const {
    std::cout << "[LOG] " << get_name() << " transaction: $" << std::fixed
              << std::setprecision(int n)
  };
};
