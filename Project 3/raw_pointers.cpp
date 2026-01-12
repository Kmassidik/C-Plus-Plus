#include <iostream>
#include <string>
#include <string_view>

// 1) Pasti ada data → reference (non-owning)
void log_ref(const std::string &msg) { std::cout << "[ref] " << msg << '\n'; }

// 2) Opsional → pointer (non-owning, must check null)
void log_ptr(const std::string *msg) {
  if (!msg)
    return;
  std::cout << "[ptr] " << *msg << '\n';
}

// 3) Read-only super ringan → string_view (non-owning)
void log_view(std::string_view msg) { std::cout << "[view] " << msg << '\n'; }

int main() {
  // OWNER
  std::string text = "important data";

  // OBSERVER (pointer)
  const std::string *observer = &text;

  // ===== USE CASES =====

  // Reference: pasti ada
  log_ref(text);

  // Pointer: bisa null
  log_ptr(observer);
  log_ptr(nullptr);

  // string_view: read-only, no copy
  log_view(text);
  log_view("literal string");

  return 0;
}
