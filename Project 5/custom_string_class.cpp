#include <cstring> // for strlen, strcpy, etc.
#include <iostream>
#include <stdexcept> // for std::out_of_range

class MyString {
private:
  char *data;    // pointer to character array
  size_t length; // length of string (without null terminator)

  // Helper to allocate and copy
  void allocateAndCopy(const char *str) {
    length = str ? std::strlen(str) : 0;
    data = new char[length + 1];
    if (str) {
      std::strcpy(data, str);
    } else {
      data[0] = '\0';
    }
  }

public:
  // Default constructor
  MyString() : data(nullptr), length(0) { allocateAndCopy(""); }

  // Constructor from C-string
  MyString(const char *str) { allocateAndCopy(str); }

  // Copy constructor
  MyString(const MyString &other) { allocateAndCopy(other.data); }

  // Move constructor (efficient, no deep copy)
  MyString(MyString &&other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
  }

  // Destructor
  ~MyString() { delete[] data; }

  // Copy assignment
  MyString &operator=(const MyString &other) {
    if (this != &other) { // self-assignment check
      delete[] data;
      allocateAndCopy(other.data);
    }
    return *this;
  }

  // Move assignment
  MyString &operator=(MyString &&other) noexcept {
    if (this != &other) {
      delete[] data;
      data = other.data;
      length = other.length;
      other.data = nullptr;
      other.length = 0;
    }
    return *this;
  }

  // Concatenation: +
  MyString operator+(const MyString &other) const {
    MyString result;
    result.length = length + other.length;
    result.data = new char[result.length + 1];
    std::strcpy(result.data, data);
    std::strcat(result.data, other.data);
    return result;
  }

  // += operator
  MyString &operator+=(const MyString &other) {
    *this = *this + other; // reuse + operator
    return *this;
  }

  // Equality
  bool operator==(const MyString &other) const {
    if (length != other.length)
      return false;
    return std::strcmp(data, other.data) == 0;
  }

  // Subscript operator [] with bounds checking + exception
  char &operator[](size_t index) {
    if (index >= length) {
      throw std::out_of_range("MyString index out of range");
    }
    return data[index];
  }

  const char &operator[](size_t index) const {
    if (index >= length) {
      throw std::out_of_range("MyString index out of range");
    }
    return data[index];
  }

  // Get C-string (const)
  const char *c_str() const { return data; }

  size_t size() const { return length; }

  // Friend for output
  friend std::ostream &operator<<(std::ostream &os, const MyString &s) {
    os << s.data;
    return os;
  }
};

int main() {
  try {
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2; // operator+
    std::cout << "s3: " << s3 << '\n';

    s1 += s2; // operator+=
    std::cout << "s1 after += : " << s1 << '\n';

    std::cout << "s1 == s3? " << std::boolalpha << (s1 == s3) << '\n';

    // Test exception
    std::cout << "Character at index 10: " << s1[10] << '\n'; // will throw
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << '\n';
  }

  return 0;
}
