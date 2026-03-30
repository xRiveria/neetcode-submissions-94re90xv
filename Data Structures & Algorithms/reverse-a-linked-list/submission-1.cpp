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
    ListNode* reverseList(ListNode* head) {
        // Recursion
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next != nullptr)
        {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        
        head->next = nullptr;
        return newHead;

        /*
        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr)
        {
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }

        return previous;
        */
    }
};
