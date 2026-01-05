#include <iostream>
using namespace std;

int main() {
  int x = 42;
  int *ptr = &x;

  cout << "Value of x: " << x << "\n";
  cout << "Through pointer: " << *ptr << "\n";

  *ptr = 100; // modify value x via pointer
  cout << "After modification: x = " << x << "\n";

  int *dynamic =
      new int(5); // Raw pointer owning dynamic memory (bad practice!)
  cout << "Dynamic value: " << *dynamic << "\n";
  delete dynamic;    // Must manually delete, east to forget -> memory leak!
  dynamic = nullptr; // Good practice: set to nullptr after delete

  // Best practice: Raw pinters for non-owning references only
  int *observer = &x; // observer does NOT own x
  // No deleted needed!

  return 0;
}
