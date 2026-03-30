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
            leftPtr = leftPtr->next; // On first run, leftPtr goes to the start of the list. 
        }

        // LeftPtr ends up right before the node we wish to delete.
        // This is because countN ensures we're always N spaces (+ 1 for LeftPtr) apart from rightPtr.
        leftPtr->next = leftPtr->next->next;
        return dummyNode.next;
    }
};
