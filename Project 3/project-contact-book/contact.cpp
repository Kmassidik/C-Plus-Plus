#include "contact.h"
#include <ostream>

namespace contacts {

Contact::Contact(std::string n, std::string p, std::string a)
    : name(std::move(n)), phone(std::move(p)), email(std::move(a)) {
  // move semantic -> cheap transfer of string
}

void Contact::print() const {
  std::cout << "Name  : " << name << "\n"
            << "Phone : " << phone << "\n"
            << "Email : " << email << "\n\n";
}

std::ostream &operator<<(std::ostream &os, const Contact &c) {
  os << c.name << " | " << c.phone << " | " << c.email;
  return os;
}

} // namespace contacts
