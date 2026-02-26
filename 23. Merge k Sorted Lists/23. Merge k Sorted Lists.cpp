// https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

template <>
struct std::greater<ListNode*> {
    constexpr bool operator()(const ListNode* rhd, const ListNode* lhd) const {
        return rhd->val > lhd->val;
    }
};

class Solution {
    using Queue = std::priority_queue<ListNode*, std::vector<ListNode*>, std::greater<ListNode*>>;

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        for (auto& item : lists) {
            if(item != nullptr) {
                min_queue.push(item);
            }
        }

        ListNode* result_start = nullptr;
        ListNode* current = nullptr;

        if(!min_queue.empty()) {
            result_start = ExtractNextKMin();
            current = result_start;
        }

        while (!min_queue.empty()) {
            current->next = ExtractNextKMin();
            current = current->next;
        }

        return result_start;
    }

private:
    Queue min_queue;

    ListNode* ExtractNextKMin() {
        ListNode* extracted = min_queue.top();
        min_queue.pop();
        if (extracted != nullptr && extracted->next != nullptr) {
            min_queue.push(extracted->next);
        }

        return extracted;
    }
};