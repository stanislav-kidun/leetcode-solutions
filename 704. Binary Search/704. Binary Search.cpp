// https://leetcode.com/problems/binary-search/

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        size_t left = 0;
        auto right = nums.size();
        while (right - left > 1) {
            size_t middle = (left + right) / 2;
            if(nums[middle] == target) {
                return middle; 
            }

            if(nums[middle] < target) {
                left = middle;
            }
            else {
                right = middle;
            }
        }

        if (nums[left] == target) {
            return left;
        }
        return -1;
    }
};