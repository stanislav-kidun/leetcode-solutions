// https://leetcode.com/problems/3sum/description/

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;

        std::sort(nums.begin() , nums.end());
        std::unordered_map<int , int> addition;
        for(int i = 0 ; i < nums.size() ; ++i){ 
            addition[nums[i]] = i;
        }

        for(int i = 0 ; i < nums.size() - 2 ; ++i){ 
            if(nums[i] > 0){ 
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){
                int required = -1*(nums[i] + nums[j]);
                if(addition.contains(required) && addition.find(required)->second > j){ 
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = addition.find(nums[j])->second; 
            }
            i = addition.find(nums[i])->second;
        }
        return answer; 
    }
};