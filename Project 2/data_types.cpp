#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "=== Data Types Demo ===\n\n";

  int age = 25;
  double pi = 3.14159;
  float temperature = 98.6f;
  char grade = 'A';
  bool isStudent = true;
  string name = "Alice";

  cout << "int     age         = " << age << endl;
  cout << "double  pi          = " << pi << endl;
  cout << "float   temperature = " << temperature << endl;
  cout << "char    grade       = " << grade << endl;
  cout << "bool    isStudent   = " << isStudent << endl;
  cout << "string  name        = " << name << endl;

  // Sizes (in bytes)
  cout << "\nSize of types:\n";
  cout << "int:     " << sizeof(int) << " bytes\n";
  cout << "double:  " << sizeof(double) << " bytes\n";
  cout << "char:    " << sizeof(char) << " bytes\n";
  cout << "bool:    " << sizeof(bool) << " bytes\n";

  // C++ is statically typed — this would cause error if uncommented:
  // age = "twenty five";  // Compile error!

  return 0;
}
