// https://leetcode.com/problems/reverse-integer/description/

#include <limits>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int sign = x < 0 ? -1 : 1;

        while (x != 0) {
            if(result > std::numeric_limits<int>::max() / 10) {
                return 0;
            }
            result *= 10;
            result += (x % 10) * sign;
            x /= 10;
        }

        return result * sign;
    }
};