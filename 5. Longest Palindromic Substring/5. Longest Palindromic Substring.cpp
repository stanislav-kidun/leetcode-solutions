// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <vector>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if(s.empty()) {
            return "";
        }

        std::pair<size_t, size_t> answer_range = {0, 1};
        size_t size = s.size();
        std::vector<std::vector<bool>> dp(size, std::vector<bool>(size));

        for(size_t i = 0; i < size; ++i) {
            dp[i][i] = true;
        }
        for(size_t i = 0; i < size - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i+1]);
            if(dp[i][i + 1]) { 
                answer_range = {i, 2};
            }
        }

        for(size_t l = 2; l < size; ++l) {
            for(size_t i = 0; i < size - l; ++i) {
                dp[i][i + l] = ((s[i] == s[i + l]) && dp[i + 1][i + l - 1]);
                if(dp[i][i + l]) {
                    answer_range = {i, l + 1};
                }
            }
        }

        return s.substr(answer_range.first, answer_range.second);
    }
};