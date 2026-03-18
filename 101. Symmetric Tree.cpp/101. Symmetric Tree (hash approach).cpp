// https://leetcode.com/problems/symmetric-tree/description/

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
        std::string GetTreeCode(TreeNode* root, bool is_reversed) {
            if(root == nullptr) {
                return "";
            }
            result += std::to_string(root->val);

            if(!is_reversed) {
                if(root->left != nullptr) {
                    result += '(';
                    GetTreeCode(root->left, is_reversed);
                    result += ')';
                }
                if(root->right != nullptr) {
                    result += '{';
                    GetTreeCode(root->right, is_reversed);
                    result += '}';
                }
            } else {
                if(root->right != nullptr) {
                    result += '(';
                    GetTreeCode(root->right, is_reversed);
                    result += ')';
                }
                if(root->left != nullptr) {
                    result += '{';
                    GetTreeCode(root->left, is_reversed);
                    result += '}';
                }
            }
            
            return result;
        }
    
    private:
        std::string result = ""; 
    };

public:
    bool isSymmetric(TreeNode* root) {
        return TreeCoder().GetTreeCode(root, false) == TreeCoder().GetTreeCode(root, true);
    }
};