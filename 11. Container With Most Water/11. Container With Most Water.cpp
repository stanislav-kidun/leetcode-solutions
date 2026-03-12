// https://leetcode.com/problems/container-with-most-water/description/

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        auto left = height.begin();
        auto right = --height.end();
        
        int answer = 0;
        int answer_cand = 0;
        while (answer_cand != -1) {
            answer_cand = CalculateResultAndMove(left, right);
            if(answer_cand > answer) {
                answer = answer_cand;
            }
        }
        
        return answer;
    }
    
private:
    int CalculateResultAndMove(auto& left, auto& right) {
        if(left == right) {
            return -1; 
        }
        
        int result = std::min(*left, *right) * (right - left);
        if(*left < *right) {
            ++left;
        } else {
            --right;
        }
        return result;
    }
};