// https://leetcode.com/problems/isomorphic-strings/description/

#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.size() != t.size()) return false;
        
        std::unordered_map<char, char> isomorphism_f;
        std::unordered_map<char, char> isomorphism_b;
    
        for(int i = 0; i < s.size(); ++i) {
            if(isomorphism_f.find(s[i]) == isomorphism_f.end()) {
                isomorphism_f[s[i]] = t[i];
            }

            if(isomorphism_b.find(t[i]) == isomorphism_b.end()) {
                isomorphism_b[t[i]] = s[i];
            }
            
            if(isomorphism_f[s[i]] != t[i] || isomorphism_b[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};