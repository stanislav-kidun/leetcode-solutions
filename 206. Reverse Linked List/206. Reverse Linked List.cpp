// https://leetcode.com/problems/reverse-linked-list/description/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* ReverseNext(ListNode* prev, ListNode* current) {
    ListNode* next = current->next;
    current->next = prev;
    return next;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head != nullptr) {
            prev = ReverseNext(prev, head);
            std::swap(prev, head);
        }
        
        return prev;
    }
};