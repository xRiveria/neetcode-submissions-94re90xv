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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyNode(0); // Used to return value. 
        ListNode* node = &dummyNode;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                node->next = list1; // If at the start, node->next will be the start of the list.
                list1 = list1->next; // Update.
            }
            else
            {
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        // Attach remaining list if it exists.
        if (list1)
        {
            node->next = list1;
        }
        else
        {
            node->next = list2;
        }

        return dummyNode.next;
    }
};
