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
    ListNode* MergeTwoLists(ListNode* firstList, ListNode* secondList)
    {
        ListNode dummyNode(0);
        ListNode* newHead = &dummyNode;

        while (firstList != nullptr && secondList != nullptr)
        {
            if (firstList->val < secondList->val)
            {
                newHead->next = firstList;
                firstList = firstList->next;
            }
            else
            {
                newHead->next = secondList;
                secondList = secondList->next;
            }

            newHead = newHead->next;
        }

        if (firstList != nullptr)
        {
            newHead->next = firstList;
        }
        else if (secondList != nullptr)
        {
            newHead->next = secondList;
        }

        return dummyNode.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return nullptr;
        }

        for (int i = 1; i < lists.size(); ++i)
        {
            lists[i] = MergeTwoLists(lists[i], lists[i - 1]);
        }

        return lists[lists.size() - 1];
    }
};
