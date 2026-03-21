// https://leetcode.com/problems/string-to-integer-atoi/

#include <string>
#include <limits>

class Solution {
public:
    int myAtoi(std::string s) {
        auto it = s.begin();
        auto it_end = s.end();
        SkipWhitespaces(it, it_end);
        int sign = ReadSign(it, it_end);
        long long number = ReadNumber(it, it_end);
        return ConstructNumber(number, sign);
    }

private:
    void SkipWhitespaces(std::string::iterator& it, std::string::iterator& end) {
        while(it != end && *it == ' ') {
            ++it;
        }
    }

    int ReadSign(std::string::iterator& it, std::string::iterator& end) {
        if(it != end && *it == '-') {
            ++it;
            return -1; 
        }  
        
        if(it != end && *it == '+') {
            ++it;
        }

        return 1;
    }

    long long ReadNumber(std::string::iterator& it, std::string::iterator& end) {
        long long result = 0;
        while(it != end && *it >= '0' && *it <= '9') {
            result *= 10;
            result += *it - '0';
            ++it;

            if(result > std::numeric_limits<int>::max()) {
                return -1;
            }
        }
        
        return result;
    }

    int ConstructNumber(long long num, int sign) {
        int result = 0;
        if(num == -1) {
            if(sign == -1) {
                return std::numeric_limits<int>::min();
            }

            return std::numeric_limits<int>::max();
        }

        result = num * sign;

        return result;
    }
};