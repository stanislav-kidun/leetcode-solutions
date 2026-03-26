// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
        while(head != nullptr) {
            if(head->next && head->val == head->next->val) {
                ListNode* for_del = head->next;
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return result;
    }
};