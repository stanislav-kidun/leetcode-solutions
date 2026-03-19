// https://leetcode.com/problems/missing-number/description/

#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        unsigned long long sum = (nums.size() * (nums.size() + 1)) / 2;

        for(const int& num : nums) {
            sum -= num;
        }

        return sum;
    }
};