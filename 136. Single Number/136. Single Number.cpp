// https://leetcode.com/problems/single-number/description/

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int answer = 0;
        for(const auto& num : nums) {
            answer ^= num;
        }

        return answer;
    }
};