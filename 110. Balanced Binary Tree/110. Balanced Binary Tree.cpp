// https://leetcode.com/problems/balanced-binary-tree/description/

#include <cmath>

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
    bool CheckIfBalanced(const size_t& left_hight, const size_t& right_hight) const {
        return std::pow(static_cast<int>(left_hight) - static_cast<int>(right_hight), 2) <= 1;
    }

public:
    bool isBalanced(TreeNode* root, size_t* subtree_hight = nullptr) {
        if(root == nullptr) {
            return true;
        }

        size_t subtree_hight_left = 0;
        size_t subtree_hight_right = 0;

        if (!isBalanced(root->left, &subtree_hight_left) || !isBalanced(root->right, &subtree_hight_right)) {
            return false;
        }

        if(subtree_hight != nullptr) {
            *subtree_hight = std::max(subtree_hight_left, subtree_hight_right) + 1;
        }

        return CheckIfBalanced(subtree_hight_left, subtree_hight_right);
    }
};