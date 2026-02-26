// https://leetcode.com/problems/linked-list-cycle/

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* rabbit = head;
        ListNode* turtle = head;
        
        Jump(turtle);
        Jump(rabbit);
        Jump(rabbit);
        
        while(rabbit != nullptr && turtle != nullptr) {
            if(rabbit == turtle) {
                return true;
            }
            Jump(turtle);
            Jump(rabbit);
            Jump(rabbit);
        }
        
        return false;
    }

private:
    void Jump(ListNode*& node) {
        if(node != nullptr) {
            node = node->next;
        }
    }
};