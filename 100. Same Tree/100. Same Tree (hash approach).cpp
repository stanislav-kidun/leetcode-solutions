// https://leetcode.com/problems/same-tree/description/

#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    class TreeCoder {
    public:
        std::string GetTreeCode(TreeNode* root) {
            if(root == nullptr) {
                return "";
            }
            result += std::to_string(root->val);

            if(root->left != nullptr) {
                result += '(';
                GetTreeCode(root->left);
                result += ')';
                GetTreeCode(root->right);
            }
            if(root->right != nullptr) {
                result += '{';
                GetTreeCode(root->right);
                result += '}';
            }
            
            return result;
        }
    
    private:
        std::string result = ""; 
    };

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return TreeCoder().GetTreeCode(p) == TreeCoder().GetTreeCode(q);
    }
};