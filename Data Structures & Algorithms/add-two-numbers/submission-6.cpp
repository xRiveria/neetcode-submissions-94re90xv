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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryBits = 0;
        ListNode newList(0);
        ListNode* headOfNodeList = &newList;

        // Continue as long as either list still has numbers.
        while (l1 != nullptr || l2 != nullptr)
        {
            int currentValue = 0;
            currentValue += (l1 != nullptr ? l1->val : 0);
            currentValue += (l2 != nullptr ? l2->val : 0);
            currentValue += carryBits;

            carryBits = currentValue / 10;
            headOfNodeList->next = new ListNode(currentValue % 10);
            headOfNodeList = headOfNodeList->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (carryBits != 0)
        {
            headOfNodeList->next = new ListNode(carryBits);
        }

        return newList.next;


        /*
        int firstNumber = 0;
        int secondNumber = 0;

        ListNode* previousNodeL1 = nullptr;
        ListNode* currentNodeL1 = l1;

        while (currentNodeL1 != nullptr)
        {
            ListNode* nextNode = currentNodeL1->next;
            currentNodeL1->next = previousNodeL1;
            previousNodeL1 = currentNodeL1;
            currentNodeL1 = nextNode;
        }

        ListNode* previousNodeL2 = nullptr;
        ListNode* currentNodeL2 = l2;
        while (currentNodeL2 != nullptr)
        {
            ListNode* nextNode = currentNodeL2->next;
            currentNodeL2->next = previousNodeL2;
            previousNodeL2 = currentNodeL2;
            currentNodeL2 = nextNode;
        }

        // Now, simply do the logic.
        while (currentNodeL1 != nullptr)
        {
            firstNumber = firstNumber * 10 + currentNodeL1->val;
            currentNodeL1 = currentNodeL1->next;
        }

        while (currentNodeL2 != nullptr)
        {
            secondNumber = secondNumber * 10 + currentNodeL2->val;
            currentNodeL2 = currentNodeL2->next;
        }

        return firstNumber + secondNumber;
        */
    }
};
