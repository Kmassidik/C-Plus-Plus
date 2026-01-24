#include "contactbook.h"
#include <algorithm>
#include <stdexcept>

namespace contacts {

void ContactBook::addContact(std::unique_ptr<Contact> contact) {
  if (!contact) {
    throw std::invalid_argument("Cannot add null contact");
  }
  contacts.push_back(std::move(contact));
}

void ContactBook::addContact(const std::string &name, const std::string &phone,
                             const std::string &email) {
  auto contact = std::make_unique<Contact>(name, phone, email);
  contacts.push_back(std::move(contact));
}

const Contact &ContactBook::findByName(const std::string &name) const {
  auto it =
      std::find_if(contacts.begin(), contacts.end(),
                   [&](const auto &ptr) { return ptr->getName() == name; });

  if (it == contacts.end()) {
    throw std::runtime_error("Contact not found: " + name);
  }

  return **it; // deferences unique_ptr -> get reference to Contact
}

void ContactBook::printAll() const {
  if (contacts.empty()) {
    std::cout << "Contact book is empty.\n";
  }

  std::cout << "=== Contacts (" << contacts.size() << ") ===\n";
  for (const auto &ptr : contacts) {
    ptr->print();
  }
}

} // namespace contacts
