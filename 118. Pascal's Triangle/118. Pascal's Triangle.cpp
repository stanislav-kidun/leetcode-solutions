// https://leetcode.com/problems/pascals-triangle/description/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        results.push_back(std::vector<int>{1});
        for(size_t i = 1; i < numRows; ++i) {
            AddRow();
        }

        return results;
    }

private:
    std::vector<std::vector<int>> results;

    void AddRow() {
        auto& last_row = results.back();
        auto next_row = std::vector<int>{1};
        for(size_t i = 1; i < last_row.size(); ++i) {
            next_row.push_back(last_row[i] + last_row[i-1]);
        }
        next_row.push_back(1);

        results.push_back(next_row);
    }
};