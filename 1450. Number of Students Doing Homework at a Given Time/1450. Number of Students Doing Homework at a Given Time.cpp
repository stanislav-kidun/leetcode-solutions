// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/

#include <vector>

class Solution {
public:
    int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
        size_t result = 0;

        for(size_t i = 0; i < startTime.size(); ++i) {
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++result;
            }
        }

        return result;
    }
};