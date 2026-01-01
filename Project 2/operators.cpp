#include <iostream>
using namespace std;

int main() {
  cout << "== Operators Demo ==\n\n";

  cout << "-- Arithmetic Operators --\n";
  cout << "-- A = 10, B = 3 -- \n";
  int a = 10, b = 3;
  cout << "a + b = " << a + b << endl;
  cout << "a - b = " << a - b << endl;
  cout << "a * b = " << a * b << endl;
  cout << "a / b = " << a / b << endl;
  cout << "a % b = " << a % b << endl;
  cout << "a++ = " << a++ << endl;
  cout << "a-- = " << a-- << endl;

  cout << "\n";

  cout << "-- Logical Operators: -- \n";
  cout << "-- P = True, Q = false -- \n";
  bool p = true, q = false;
  cout << "p && q = " << (p && q) << endl;
  cout << "p || q = " << (p || q) << endl;
  cout << "!p     = " << (!p) << endl << endl;

  cout << "\n";

  cout << "-- Bitwise Operators -- \n";
  cout << "-- C = 5, D = 3 -- \n";
  int c = 5;                               // binary 0101
  int d = 3;                               // binary 0011
  cout << "a & b  = " << (c & d) << endl;  // AND
  cout << "a | b  = " << (c | d) << endl;  // Or
  cout << "a ^ b  = " << (c ^ d) << endl;  // Xor
  cout << "~a     = " << (~c) << endl;     // Not / invert bits
  cout << "a << 1 = " << (c << 1) << endl; // left shift
  cout << "a >> 1 = " << (c << 1) << endl; // right shift

  return 0;
}
