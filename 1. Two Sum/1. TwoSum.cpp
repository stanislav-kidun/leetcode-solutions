// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for(size_t i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if(map.contains(target - num)) {
                return {static_cast<int>(i), map[target - num]};
            }
            map[num] = i;
        }

        return {-1, -1};
    }
};