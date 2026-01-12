#include <iostream>
#include <memory>

using namespace std;

// ================= STACK vs STATIC =================
void demoLifetime() {
  int numberOnStack = 1;       // stack (auto)
  static int numberStatic = 2; // static (program lifetime)

  cout << "Inside function:\n";
  cout << "  numberOnStack = " << numberOnStack
       << " | address = " << &numberOnStack << "\n";

  cout << "  numberStatic  = " << numberStatic
       << " | address = " << &numberStatic << "\n";

  numberStatic++; // value persists
}

// ================= HEAP (SAFE WAY) =================
void demoHeapSmartPointer() {
  auto numberOnHeap = make_unique<int>(100); // heap allocation

  cout << "Inside demoHeapSmartPointer:\n";
  cout << "  smartPointerObject (stack) address = " << &numberOnHeap << "\n";

  cout << "  heapNumber address = " << numberOnHeap.get() << "\n";

  cout << "  heapNumber value = " << *numberOnHeap << "\n";
}

// ================= HEAP (RAW - EDUCATION ONLY) =================
void demoHeapRaw() {
  int *dynamicNumber = new int(42); // heap allocation

  cout << "Inside demoHeapRaw:\n";
  cout << "  pointerVariable (stack) address = " << &dynamicNumber << "\n";

  cout << "  heapNumber address = " << dynamicNumber << "\n";

  cout << "  heapNumber value = " << *dynamicNumber << "\n";

  delete dynamicNumber; // manual cleanup
}

int main() {
  cout << "=== STACK & STATIC DEMO ===\n";
  cout << "First call:\n";
  demoLifetime();

  cout << "\nSecond call:\n";
  demoLifetime();

  cout << "\n=== HEAP (SMART POINTER) ===\n";
  demoHeapSmartPointer();

  cout << "\n=== HEAP (RAW POINTER) ===\n";
  demoHeapRaw();

  cout << "\n=== PROGRAM END ===\n";
  return 0;
}
