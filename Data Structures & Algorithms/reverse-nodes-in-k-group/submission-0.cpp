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
    // Moves k steps forward starting from head.
    // Notice how to increment before deducting.
    // This means we should do k-1.
    ListNode* GetKthNode(ListNode* head, int k)
    {
        while (head != nullptr && k > 0)
        {
            head = head->next;
            k--;
        }

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummyNode(0);        
        ListNode* headOfPreviousList = &dummyNode;
        ListNode* nextHead = nullptr;

        while (true)
        {   
            ListNode* dummyNode = head;
            ListNode* kthNode = GetKthNode(dummyNode, k - 1);
            if (kthNode == nullptr)
            {
                break;
            }

            nextHead = kthNode->next; // For reconnection.
            ListNode* newTailOfList = head;
            ListNode* previousNode = nullptr;
            while (head != nextHead)
            {
                ListNode* nextNode = head->next;
                head->next = previousNode;
                previousNode = head;
                head = nextNode;
            }
            // previousNode is now the head of the new list.
            headOfPreviousList->next = previousNode;
            // Reconnect tail of this reversed block to the rest.
            newTailOfList->next = nextHead;
            headOfPreviousList = newTailOfList;
            head = nextHead;
        }

        return dummyNode.next;
    }
};
