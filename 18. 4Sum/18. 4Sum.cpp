// https://leetcode.com/problems/3sum/description/

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> answer;

        if(nums.size() < 4) {
            return answer;
        }

        std::sort(nums.begin() , nums.end());
        std::unordered_map<long long, size_t> addition;
        for(size_t i = 0 ; i < nums.size() ; ++i){ 
            addition[nums[i]] = i;
        }

        for(size_t i = 0 ; i < nums.size() - 3 ; ++i){ 
            for(size_t j = i + 1 ; j < nums.size() - 2 ; ++j){
                for(size_t k = j + 1 ; k < nums.size() - 1 ; ++k){
                    long long required = static_cast<long long>(target) - (static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[k]));
                    if(addition.count(required) && addition.find(required)->second > k){ 
                        answer.push_back({nums[i] , nums[j], nums[k], static_cast<int>(required)});
                    }
                    k = addition.find(nums[k])->second; 
                }
                j = addition.find(nums[j])->second; 

            }
            i = addition.find(nums[i])->second;
        }
        return answer; 
    }
};