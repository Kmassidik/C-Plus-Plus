#ifndef CONCACT_H
#define CONCACT_H

#include <iostream>
#include <ostream>
#include <string>

namespace contacts {

class Contact {
private:
  std::string name;
  std::string phone;
  std::string email;

public:
  Contact() = default;
  Contact(std::string n, std::string p, std::string e);

  // Getters
  const std::string &getName() const { return name; }
  const std::string &getPhone() const { return phone; }
  const std::string &getEmail() const { return email; }

  void print() const;

  friend std::ostream &operator<<(std::ostream &os, const Contact &c);
};

} // namespace contacts

#endif // !CONCACT_H
