#include "contactbook.h"
#include <iostream>
#include <string>

using namespace contacts;

int main() {
  ContactBook book;

  // Modern & safe way
  book.addContact("Budi Santoso", "+628123456789", "budi@gmail.com");
  book.addContact("Ani Wijaya", "+628987654321", "ani@work.co.id");
  book.addContact("Citra Lestari", "+628111222333", "citra@yahoo.com");

  std::cout << "All contacts:\n";
  book.printAll();

  // Demonstrate reference usage + exception safety
  try {
    const Contact &found = book.findByName("Budi Santoso");
    std::cout << "Found: " << found << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  // Demonstrate not-found case
  try {
    book.findByName("Nobody");
  } catch (const std::exception &e) {
    std::cout << "Expected error: " << e.what() << "\n";
  }

  std::cout << "\nEnd of program → all memory auto-released\n";
  return 0;
}
