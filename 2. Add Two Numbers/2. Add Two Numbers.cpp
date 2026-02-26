// https://leetcode.com/problems/add-two-numbers/

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
void Append(ListNode*& current, ListNode* source, int& leading1) {
    while(source != nullptr) {
        current->next = new ListNode(leading1 + source->val);
        current = current->next;
        
        leading1 = current->val / 10;
        current->val %= 10;
        
        source = source->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int leading1 = 0;

        ListNode* result_start = new ListNode(l1->val + l2->val);
        ListNode* current = result_start;
        
        leading1 = current->val / 10;
        current->val %= 10;
        
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != nullptr && l2 != nullptr) {
            current->next = new ListNode(leading1 + l1->val + l2->val);
            current = current->next;

            leading1 = current->val / 10;
            current->val %= 10;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        Append(current, l1, leading1);
        Append(current, l2, leading1);

        if(leading1 > 0) {
            current->next = new ListNode(leading1);
        }

        return result_start;
    }
};