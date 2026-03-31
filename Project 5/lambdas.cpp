#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};

  // Lambda with capture by reference [&]
  int sum = 0;
  auto addToSum = [&](int n) { sum += n; };

  std::for_each(nums.begin(), nums.end(), addToSum);
  std::cout << "Sum = " << sum << '\n';

  // Lambda that captures nothing, returns bool (predicate)
  auto isEven = [](int n) { return n % 2 == 0; };

  int evenCount = std::count_if(nums.begin(), nums.end(), isEven);
  std::cout << "Even numbers: " << evenCount << '\n';

  return 0;
}
