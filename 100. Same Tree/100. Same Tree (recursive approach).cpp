// https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool empty_p = (p == nullptr);
        bool empty_q = (q == nullptr);
        if(empty_p || empty_q) {
            return empty_p == empty_q;
        }

        if(p->val == q->val) {
            if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) {
                return false;
            }
            return true;
        }

        return false;
    }
};