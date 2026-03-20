// https://leetcode.com/problems/max-consecutive-ones/description/

#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        size_t max_1s_current = nums[0];
        size_t max_1s = max_1s_current;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                if(max_1s_current > max_1s) {
                    max_1s = max_1s_current;
                }
                max_1s_current = 0;
            } else {
                ++max_1s_current;
            }
        }

        max_1s = std::max(max_1s_current, max_1s);
        return max_1s;
    }
};