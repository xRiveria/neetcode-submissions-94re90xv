/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next->next;

        while (fastPtr != nullptr && fastPtr->next != nullptr)
        {
            if (slowPtr == fastPtr)
            {
                return true;
            }

            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return false;
    }
};
