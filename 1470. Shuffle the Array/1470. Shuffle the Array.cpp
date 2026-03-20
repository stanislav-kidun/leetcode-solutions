// https://leetcode.com/problems/shuffle-the-array/description/

#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> result(2*n);
        for(size_t i = 0; i < n; ++i) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[i + n];
        }

        return result;
    }
};