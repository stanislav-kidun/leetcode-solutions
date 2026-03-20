// https://leetcode.com/problems/jewels-and-stones/description/

#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        size_t result = 0;
        std::unordered_set<char> jewels_set;
        for(const auto& jewel : jewels) {
            jewels_set.insert(jewel);
        }

        for(const auto& stone : stones) {
            if(jewels_set.contains(stone)) {
                ++result;
            }
        }

        return result;
    }
};