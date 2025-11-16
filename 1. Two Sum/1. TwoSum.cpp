#include <iostream>
#include <vector>

std::vector<int> code() {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;

  if (nums.size() == 2) return {0, 1};

  for (int i = 0; i < nums.size(); ++i)
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) return {i, j};
    }

  return {0, 0};
}

int main() {
  std::cout << code()[1] << ' ' << code()[2];
  return 0;
}
