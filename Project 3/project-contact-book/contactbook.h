#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "contact.h"
#include <memory>
#include <string>
#include <vector>

namespace contacts {

class ContactBook {

private:
  // Modern way: vector of unique_ptr
  std::vector<std::unique_ptr<Contact>> contacts;

public:
  ContactBook() = default;
  // Add contact - takes owenership via unique_ptr
  void addContact(std::unique_ptr<Contact> contact);
  // Factory method - safer then raw new
  void addContact(const std::string &name, const std::string &phone,
                  const std::string &email);
  // Search by name (returns references if found, throws if not)
  const Contact &findByName(const std::string &name) const;

  void printAll() const;

  size_t size() const { return contacts.size(); }

  // Rule of zero - no need for custom destructor, copy, move.
  // vector + unique_ptr clean up automatically
};

} // namespace contacts

#endif // !CONTACTBOOK_H
