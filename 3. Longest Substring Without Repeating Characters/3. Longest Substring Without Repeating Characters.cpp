// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> symbols;
        size_t cur_answer = 0;
        size_t answer = 0;

        for(size_t right = 0, left = 0; right < s.size(); ++right) {
            if(!symbols.contains(s[right])) {
                symbols.insert(s[right]);
                ++cur_answer;

                if(cur_answer > answer) {
                    answer = cur_answer;
                }
            } else {
                while(s[left] != s[right]) {
                    symbols.erase(s[left++]);
                    --cur_answer;
                }
                ++left;
            }
        }

        return answer;
    }
};