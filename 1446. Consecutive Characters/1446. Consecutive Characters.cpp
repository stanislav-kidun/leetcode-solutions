// https://leetcode.com/problems/consecutive-characters/description/

#include <string>

class Solution {
public:
    int maxPower(std::string s) {
        char cur_char = s[0];
        size_t power = 1;
        size_t max_power = power;
        for(size_t i = 1; i < s.size(); ++i) {
            if(s[i] == cur_char) {
                ++power;
                if(power > max_power) {
                    max_power = power;
                }
            } else {
                power = 1;
                cur_char = s[i];
            }
        }

        return max_power;
    }
};