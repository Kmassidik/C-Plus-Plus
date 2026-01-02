#include <iostream>
using namespace std;

// Function declarations
int add(int a, int b);
double calculateAverage(double a, double b, double c);
char getLetterGrade(double avg);
bool isPrime(int n);
void greet(string name = "Guest");

int main() {
  cout << "=== Functions Demo ===\n\n";

  cout << "add(5, 7) = " << add(5, 7) << endl;

  double avg = calculateAverage(85.5, 90.0, 78.0);
  cout << "Average = " << avg << endl;
  cout << "Letter Grade = " << getLetterGrade(avg) << endl;

  cout << "\nisPrime checks:\n";
  cout << "7 is prime? " << (isPrime(7) ? "Yes" : "No") << endl;
  cout << "15 is prime? " << (isPrime(15) ? "Yes" : "No") << endl;

  cout << "\nGreetings:\n";
  greet("Bob");
  greet(); // uses default parameter

  return 0;
}

// Function definitions
int add(int a, int b) { return a + b; }

double calculateAverage(double a, double b, double c) {
  return (a + b + c) / 3.0;
}

char getLetterGrade(double avg) {
  if (avg >= 90)
    return 'A';
  if (avg >= 80)
    return 'B';
  if (avg >= 70)
    return 'C';
  if (avg >= 60)
    return 'D';
  return 'F';
}

bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

void greet(string name) { cout << "Hello, " << name << "!\n"; }
