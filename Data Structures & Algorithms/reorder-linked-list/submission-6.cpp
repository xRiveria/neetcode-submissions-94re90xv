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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        // Classic solution to find the middle of the list.  
        // The idea is that when fast reaches the end of the list, slow would have travelled half as many nodes. 
        // This means fast/2=middle. 
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // When the approach above ends, slow is at the midpoint. We start reversing from slow->next. 
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Cut the list into 2 halves. 
        ListNode* previous = nullptr; 
        while (secondHalf != nullptr)
        {
            ListNode* temp = secondHalf->next;
            secondHalf->next = previous;
            previous = secondHalf;
            secondHalf = temp;
        }

        ListNode* firstHalf = head;
        secondHalf = previous;
        while (secondHalf != nullptr)
        {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
