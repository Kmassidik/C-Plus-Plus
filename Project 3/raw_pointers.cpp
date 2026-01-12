// Raw_Pointers.cpp
// Raw pointers hold addresses. No automatic memory management!

#include <iostream>

int main() {
  std::cout << "=== Raw Pointers Demo ===\n\n";

  int x = 42;
  std::cout << "1. Created int x = 42\n";
  std::cout << "   Address of x: " << &x << "\n\n";

  int *ptr = &x; // ptr points to x
  std::cout << "2. Created raw pointer ptr pointing to x\n";
  std::cout << "   Value of ptr (address): " << ptr << "\n";
  std::cout << "   Value pointed to (*ptr): " << *ptr << "\n\n";

  *ptr = 100; // Modify x through pointer
  std::cout << "3. Changed *ptr = 100\n";
  std::cout << "   Now x became: " << x << "\n";
  std::cout << "   *ptr is now: " << *ptr << "\n\n";

  std::cout
      << "4. Allocating dynamic memory with new (raw pointer owning it)\n";
  int *dynamic = new int(5);
  std::cout << "   dynamic pointer address: " << dynamic << "\n";
  std::cout << "   Value at dynamic memory: " << *dynamic << "\n\n";

  std::cout << "5. Manually deleting the dynamic memory\n";
  delete dynamic;
  dynamic = nullptr;
  std::cout << "   dynamic pointer set to nullptr: " << dynamic << "\n\n";

  std::cout << "6. Creating a non-owning (observing) raw pointer\n";
  int *observer = &x;
  std::cout << "   observer points to x: " << *observer << "\n";
  std::cout << "   No delete needed — x is on stack!\n";

  std::cout
      << "\nEnd of program. Notice: no memory leaks if we delete properly!\n";
  return 0;
}
