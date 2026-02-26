// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <iostream>

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        size_t left = 0;
        size_t right = n;
        
        if(guess(n) == 0) {
            return n;
        }

        while (right - left > 1) {
            size_t middle = (left + right) / 2;
            if(guess(middle) == 0) {
                return middle; 
            }

            if(guess(middle) == 1) {
                left = middle;
            }
            else {
                right = middle;
            }
        }

        return left;
    }
};