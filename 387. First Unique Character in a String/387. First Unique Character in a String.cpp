// https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <string>
#include <map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::map<char, int> characters;
        for (ssize_t i = 0; i < s.size(); ++i) {
            characters[s[i]] += 1;
        }

        for (ssize_t i = 0; i < s.size(); ++i) {
            if(characters[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};