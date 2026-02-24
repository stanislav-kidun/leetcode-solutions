// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> dp(size);
        dp[0] = -1;

        int current = nums[0];
        int result = current;
        for(int i = 1; i < size; ++i) {
            dp[i] = dp[i - 1];
            if(nums[i] == 1) {
                ++current;
                if(result < current) {
                    result = current;
                }
            } else {
                if(nums[i - 1] != 0) {
                    if(dp[i] != -1) {
                        current = i - dp[i];
                    }
                    dp[i] = i + 1;
                } else {
                    dp[i] = -1;
                    current = 0;
                }
            }
        }

        if(result == size) {
            --result;
        }
        return result;
    }   
};