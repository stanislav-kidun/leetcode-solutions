#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> strs) {
  std::string ans = "";

  for (int i = 0; i < strs[0].length(); ++i) {
    for (int j = 1; j < strs.size(); ++j) {
      if (!strs[j][i] || strs[0][i] != strs[j][i]) return ans;
    }
    ans += strs[0][i];
  }

  return ans;
}

int main() { std::cout << longestCommonPrefix({"flower", "flow", "flowht"}); }