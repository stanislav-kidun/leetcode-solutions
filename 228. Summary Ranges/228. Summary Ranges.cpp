// https://leetcode.com/problems/summary-ranges/description/
#include <vector>
#include <string>


class Solution {
    std::string ConvertToAnswer(int left, int right) {
        if(left == right) {
            return std::to_string(left);
        }
        return std::to_string(left) + "->" + std::to_string(right);
    }

public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {\
        std::vector<std::string> results;
        if(nums.empty()) {
            return results;
        }    

        int left = nums[0];
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1] + 1) {
                results.push_back(ConvertToAnswer(left, nums[i - 1]));
                left = nums[i];
            }
        }

        results.push_back(ConvertToAnswer(left, nums.back()));

        return results;   
    }
};