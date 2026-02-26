// https://leetcode.com/problems/valid-parentheses/description/

#include <vector>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> stack;

        for(const auto& symbol : s) {
            switch(symbol) {
                case '(':
                    stack.push_back(')');
                    break;
                case '[':
                    stack.push_back(']');
                    break;
                case '{':
                    stack.push_back('}');
                    break;
                default:
                    if(stack.empty() || stack.back() != symbol) {
                        return false;
                    }
                    stack.pop_back();
            }
        }

        return stack.empty();
    }
};