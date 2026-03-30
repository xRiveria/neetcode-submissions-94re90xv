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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyNode(0);
        dummyNode.next = head;

        ListNode* leftPtr = &dummyNode;
        ListNode* rightPtr = head;
        
        int countN = 0;
        while (countN != n)
        {
            rightPtr = rightPtr->next;
            countN++;
        }

        while (rightPtr != nullptr)
        {
            rightPtr = rightPtr->next;
            leftPtr = leftPtr->next;
        }

        leftPtr->next = leftPtr->next->next;
        return dummyNode.next;
    }
};
