// https://leetcode.com/problems/integer-to-roman/

#include <string>
#include <map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result;
        std::map<int, std::string, std::greater<int>> symbols = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for(auto [value, symbol] : symbols) {
            while (num >= value) {
                num -= value;
                result += symbol;
            }
        }

        return result;
    }
};