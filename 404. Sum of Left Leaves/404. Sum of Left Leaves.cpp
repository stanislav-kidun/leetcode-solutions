// https://leetcode.com/problems/sum-of-left-leaves/description/

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
    int sumOfLeftLeaves(TreeNode* root, bool is_left = false) {
        if(root == nullptr) {
            return 0;
        }

        if(IsLeaf(root) && is_left) {
            return root->val;
        }

        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }

private:
    bool IsLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};