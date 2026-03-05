// bank_system.cpp
// Compile: g++ -std=c++17 -Wall -Wextra bank_system.cpp -o bank && ./bank

#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// ────────────────────────────────────────────────
// Abstract base class – common interface
// ────────────────────────────────────────────────
class Account {
protected:
  std::string number_;
  double balance_ = 0.0;

public:
  Account(std::string number, double initial_balance)
      : number_(std::move(number)), balance_(initial_balance) {
    if (initial_balance < 0)
      throw std::invalid_argument("Initial balance cannot be negative");
  }

  virtual ~Account() = default; // Virtual dtor for polymorphic cleanup

  // Common behavior
  void deposit(double amount) {
    if (amount <= 0)
      throw std::invalid_argument("Deposit must be positive");
    balance_ += amount;
  }

  // Polymorphic behavior – derived classes override
  virtual void withdraw(double amount) = 0;

  // Optional polymorphic extension point
  virtual void apply_monthly() {} // e.g., interest or fees

  double get_balance() const { return balance_; }
  const std::string &get_number() const { return number_; }

  virtual std::string get_type() const = 0; // For display
};

// ────────────────────────────────────────────────
// Savings – no overdraft, has interest
// ────────────────────────────────────────────────
class SavingsAccount final : public Account {
private:
  double interest_rate_;

public:
  SavingsAccount(std::string number, double initial_balance, double rate)
      : Account(std::move(number), initial_balance), interest_rate_(rate) {
    if (rate < 0)
      throw std::invalid_argument("Interest rate cannot be negative");
  }

  void withdraw(double amount) override {
    if (amount <= 0)
      throw std::invalid_argument("Withdrawal must be positive");
    if (amount > balance_)
      throw std::runtime_error("Insufficient funds");
    balance_ -= amount;
  }

  void apply_monthly() override { balance_ += balance_ * interest_rate_; }

  std::string get_type() const override { return "Savings"; }
};

// ────────────────────────────────────────────────
// Checking – allows overdraft, no interest
// ────────────────────────────────────────────────
class CheckingAccount final : public Account {
private:
  double overdraft_limit_;

public:
  CheckingAccount(std::string number, double initial_balance, double overdraft)
      : Account(std::move(number), initial_balance),
        overdraft_limit_(overdraft) {
    if (overdraft < 0)
      throw std::invalid_argument("Overdraft limit cannot be negative");
  }

  void withdraw(double amount) override {
    if (amount <= 0)
      throw std::invalid_argument("Withdrawal must be positive");
    if (amount > balance_ + overdraft_limit_)
      throw std::runtime_error("Overdraft limit exceeded");
    balance_ -= amount;
  }

  std::string get_type() const override { return "Checking"; }
};

// ────────────────────────────────────────────────
// Interactive menu system
// ────────────────────────────────────────────────
void run_bank_system() {
  std::vector<std::unique_ptr<Account>> accounts;

  while (true) {
    std::cout << "\n=== Bank System Menu ===\n"
              << "1. Create Savings Account\n"
              << "2. Create Checking Account\n"
              << "3. Deposit to Account\n"
              << "4. Withdraw from Account\n"
              << "5. Apply Monthly Interest/Fees\n"
              << "6. View All Balances\n"
              << "7. Exit\n"
              << "Choose option: ";

    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      continue;
    }

    try {
      switch (choice) {
      case 1: { // Create Savings
        std::string num;
        double bal, rate;
        std::cout << "Account number: ";
        std::cin >> num;
        std::cout << "Initial balance: ";
        std::cin >> bal;
        std::cout << "Interest rate (e.g., 0.03): ";
        std::cin >> rate;
        accounts.emplace_back(std::make_unique<SavingsAccount>(num, bal, rate));
        std::cout << "Savings account created.\n";
        break;
      }
      case 2: { // Create Checking
        std::string num;
        double bal, od;
        std::cout << "Account number: ";
        std::cin >> num;
        std::cout << "Initial balance: ";
        std::cin >> bal;
        std::cout << "Overdraft limit: ";
        std::cin >> od;
        accounts.emplace_back(std::make_unique<CheckingAccount>(num, bal, od));
        std::cout << "Checking account created.\n";
        break;
      }
      case 3:
      case 4:
      case 5: { // Operations needing account selection
        if (accounts.empty()) {
          std::cout << "No accounts exist.\n";
          break;
        }
        std::cout << "Select account index (0 to " << accounts.size() - 1
                  << "): ";
        size_t idx;
        std::cin >> idx;
        if (idx >= accounts.size())
          throw std::out_of_range("Invalid index");

        if (choice == 3) { // Deposit
          double amt;
          std::cout << "Amount: ";
          std::cin >> amt;
          accounts[idx]->deposit(amt);
          std::cout << "Deposit successful.\n";
        } else if (choice == 4) { // Withdraw – polymorphic
          double amt;
          std::cout << "Amount: ";
          std::cin >> amt;
          accounts[idx]->withdraw(amt);
          std::cout << "Withdrawal successful.\n";
        } else { // Apply monthly – polymorphic
          accounts[idx]->apply_monthly();
          std::cout << "Monthly operation applied.\n";
        }
        break;
      }
      case 6: { // View all – polymorphic display
        if (accounts.empty()) {
          std::cout << "No accounts.\n";
          break;
        }
        std::cout << std::fixed << std::setprecision(2);
        for (size_t i = 0; i < accounts.size(); ++i) {
          const auto &acc = *accounts[i];
          std::cout << "[" << i << "] " << acc.get_type() << " #"
                    << acc.get_number() << ": $" << acc.get_balance() << "\n";
        }
        break;
      }
      case 7:
        std::cout << "Exiting...\n";
        return;
      default:
        std::cout << "Invalid option.\n";
      }
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << "\n";
      std::cin.clear();
      std::cin.ignore();
    }
  }
}

int main() {
  run_bank_system();
  return 0;
}
