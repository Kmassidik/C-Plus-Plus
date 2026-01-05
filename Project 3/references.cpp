#include <iostream>
using namespace std;

void modifyByReferences(int &ref) { ref += 100; }

int main() {
  int x = 10;
  int &ref = x;

  cout << "x = " << x << "\n";
  cout << "ref = " << ref << "\n";

  ref = 20;
  cout << "Aftrer ref = 20: x = " << x << "\n";

  modifyByReferences(ref);
  cout << "After function: x = " << x << "\n";

  // int& badRef;  // ERROR: references must be initialized
  // ref = someOtherVar;  // ERROR: cannot rebind reference

  return 0;
}
