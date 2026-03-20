// https://leetcode.com/problems/concatenation-of-array/description/

#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> result(nums.size() * 2, 0);
        for(size_t i = 0; i < nums.size(); ++i) {
            result[i] = nums[i];
            result[i + nums.size()] = nums[i];
        }

        return result;
    }
};