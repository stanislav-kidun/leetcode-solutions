// https://leetcode.com/problems/find-k-closest-elements/description/

#include <vector>
#include <cmath>

class Solution {
    size_t Dist(size_t left, size_t right) {
        int dist = right - left;
        return std::abs(dist);
    }
    
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        auto x_pos = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int left = x_pos - k;
        if(left < 0) { 
            left = 0;
        }
        size_t right = left + k;
        
        for(size_t i = 0; i < k; ++i) {
            if(right == arr.size()) {
                break;
            }
            if(Dist(arr[left], x) > Dist(x, arr[right])) {
                ++left;
                ++right;
            }
        }
        
        std::vector<int> answer;

        for(; left < right; ++left) {
            answer.push_back(arr[left]);
        }
        
        return answer;
    }
};