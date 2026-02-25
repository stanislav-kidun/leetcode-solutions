// https://leetcode.com/problems/string-compression/description/

#include <vector>
#include <string>

class Solution {
    std::string Encode(char symbol, size_t count) {
        std::string answer(1, symbol);
        if(count > 1) {
            answer += std::to_string(count);
        }
        return answer;
    }

    void AddToAnswer(std::vector<char>& chars, size_t& pos, const std::string& encode) {
        for(const char& item : encode) {
            chars[pos++] = item;
        }
    }

public:
    int compress(std::vector<char>& chars) {
        size_t pos = 0;
        size_t counter = 1;
        for(size_t i = 1; i < chars.size(); ++i, ++counter) {
            if(chars[i] != chars[i-1]) {
                AddToAnswer(chars, pos, Encode(chars[i-1], counter));
                counter = 0; 
            }
        }
        AddToAnswer(chars, pos, Encode(chars.back(), counter));
        
        return pos;
    }
};