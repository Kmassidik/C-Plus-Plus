#include <iostream>
using namespace std;

int main() {
  cout << "== Control Flow Demo ===\n\n";

  cout << "For loop (0 to 9):\n";
  for (int i = 0; i < 10; i++) {
    cout << i << " ";
  }
  cout << "\n\n";

  cout << "While Loop";
  int i = 0;
  while (i <= 10) {
    cout << i << " ";
    i += 2;
  }
  cout << "\n\n";

  // If-else
  cout << "If-else exmaple";
  int score = 90;
  if (score > 90) {
    cout << "Grade: A\n";
  } else {
    cout << "Grdee Others\n";
  }
  cout << "\n\n";

  cout << "\nSwitch example (day of week):\n";
  int day = 3;
  switch (day) {
  case 1:
    cout << "Monday\n";
    break;
  case 3:
    cout << "Wednesday\n";
    break;
  default:
    cout << "Invalid day\n";
  }

  return 0;
}
