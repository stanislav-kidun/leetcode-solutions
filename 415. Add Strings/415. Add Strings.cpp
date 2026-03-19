// https://leetcode.com/problems/add-strings/description/

#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int leading_one = 0;

        auto iter1 = num1.rbegin();
        auto iter2 = num2.rbegin();

        for(; iter1 != num1.rend() && iter2 != num2.rend(); ++iter1, ++iter2) {
            CalculatePart(FromCharToNum(*iter1), FromCharToNum(*iter2), leading_one);
        }

        for(; iter1 != num1.rend(); ++iter1) {
            CalculatePart(FromCharToNum(*iter1), 0, leading_one);
        }

        for(; iter2 != num2.rend(); ++iter2) {
            CalculatePart(0, FromCharToNum(*iter2), leading_one);
        }

        if(leading_one) {
            result.push_back('1');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    std::string result;

    int FromCharToNum(const char& symbol) {
        return static_cast<int>(symbol - '0');
    }

    void CalculatePart(const int& first, const int& second, int& leading_one) {
        auto part_result = first + second + leading_one;
        leading_one = part_result / 10;
        result += std::to_string(part_result % 10);
    }
};