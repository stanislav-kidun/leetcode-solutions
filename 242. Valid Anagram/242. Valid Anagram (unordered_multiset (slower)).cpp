// https://leetcode.com/problems/valid-anagram/description/

#include <unordered_set>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_multiset<char> symbols;

        for(auto& symbol : s) {
            symbols.insert(symbol);
        }

        for(auto& symbol : t) {
            auto item = symbols.find(symbol);
            if(item != symbols.end()) {
                symbols.erase(item);
            } else {
                return false;
            }
        }

        return symbols.empty();
    }
};