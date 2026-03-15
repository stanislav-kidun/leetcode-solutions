// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include <algorithm>

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
public:
    int maxDepth(TreeNode* root, int depth = 0) {
        if(!root) {
            return depth;
        }
        ++depth;
        int left_depth = maxDepth(root->left, depth);
        int right_depth = maxDepth(root->right, depth);
        
        return std::max(left_depth, right_depth);
    }
};