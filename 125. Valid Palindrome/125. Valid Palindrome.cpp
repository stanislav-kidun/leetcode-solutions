// https://leetcode.com/problems/valid-palindrome/description/

#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if(s.size() <= 1) {
            return true;
        }

        auto left = 0;
        auto right = s.size() - 1;

        while(left < right) {
            while(left < right && !std::isalnum(s[left])) {
                ++left;
            }
            while(left < right && !std::isalnum(s[right])) {
                --right;
            }

            if(left >= right) {
                break;
            }

            if(std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};