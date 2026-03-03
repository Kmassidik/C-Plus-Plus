#include <iostream>
#include <type_traits>

class Device {
public:
  int id = 42;
  virtual ~Device() = default;
  virtual void reset() { std::cout << "Device reset (id=" << id << ")\n"; }
};

// Variant 1: Diamond without virtal machine inheritance -> duplication +
// ambiguity
class Scanner : public Device {};
class Printer : public Device {};

class Multifunction : public Scanner, public Printer {
public:
  void status() {
    // Ambiguous - which 'id' ?
    // std::cout << id << "\n"; // compile error

    // Must qualify
    std::cout << "Scanner id: " << Scanner::id << "\n";
    std::cout << "Printer id: " << Printer::id << "\n";
  }
};

// Variant 2: Diamond with virtual inheritance -> single copy, no ambiguity
class VirtualScanner : virtual public Device {};
class VirtualPrinter : virtual public Device {};

class VirtualMultifunction final : public VirtualScanner,
                                   public VirtualPrinter {
public:
  void status() {
    // Now unambiguous — only one Device subobject
    std::cout << "Shared id: " << id << "\n";
    reset(); // calls Device::reset() without qualification
  }
};

// Variant 3: Avoiding diamond
class DeviceHolder {
private:
  Device shared_device;

public:
  const Device &get_device() const { return shared_device; }
};

class CleanMultifunction final : public Scanner, public Printer {
private:
  DeviceHolder holder;

public:
  void status() {
    std::cout << "Shared id via composition: " << holder.get_device().id
              << "\n";
  }
};

int main() {
  std::cout << "=== Without virtual inheritance ===\n";
  Multifunction m;
  m.status(); // shows two different ids if you modify one path

  std::cout << "\n=== With virtual inheritance ===\n";
  VirtualMultifunction vm;
  vm.status(); // one id, clean access

  std::cout << "\n=== Avoiding diamond (composition) ===\n";
  CleanMultifunction cm;
  cm.status();

  return 0;
}
