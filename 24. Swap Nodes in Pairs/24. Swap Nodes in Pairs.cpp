// https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = SwapPair(head);
        head = result;
        while(head != nullptr) {
            MoveForward(head);
            ListNode* old_head = head;

            MoveForward(head);
            head = SwapPair(head);
            if(old_head != nullptr) {
                old_head->next = head;
            }
        }

        return result;
    }

    ListNode* SwapPair(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* new_head = head->next;
        head->next = new_head->next;
        new_head->next = head;
        return new_head;
    }

    void MoveForward(ListNode*& head) {
        if(head == nullptr) {
            return;
        }
        head = head->next;
    }
};