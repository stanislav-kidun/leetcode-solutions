// https://leetcode.com/problems/valid-anagram/description/

#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> symbols;

        for(auto& symbol : s) {
            symbols[symbol] += 1;
        }

        for(auto& symbol : t) {
            auto item = symbols.find(symbol);
            if(item != symbols.end()) {
                if(item->second > 1) {
                    --item->second;
                } else {
                    symbols.erase(item);
                }
            } else {
                return false;
            }
        }

        return symbols.empty();
    }
};