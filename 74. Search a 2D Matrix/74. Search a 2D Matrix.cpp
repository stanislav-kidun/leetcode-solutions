// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        size_t left = 0;
        size_t right = matrix.size() * matrix[0].size();

        auto accessMatrix = [&matrix](size_t index) {
            return matrix[index / matrix[0].size()][index % matrix[0].size()];
        };

        while (right - left > 1) {
            size_t middle = (left + right) / 2;
            if(accessMatrix(middle) == target) {
                return true; 
            }

            if(accessMatrix(middle) < target) {
                left = middle;
            }
            else {
                right = middle;
            }
        }

        if (accessMatrix(left) == target) {
            return true;
        }
        return false; 
    }
};