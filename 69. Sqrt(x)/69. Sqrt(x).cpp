// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(long long x) {
        long long middle = 0;
        long long lbound = 0;
        long long rbound = x + 1;
        while (lbound < rbound - 1) {
            middle = (lbound + rbound) / 2;
            if (middle * middle <= x) {
                lbound = middle;
            } else if (middle * middle > x) {
                rbound = middle;
            }
        }

        return lbound;
    }
};