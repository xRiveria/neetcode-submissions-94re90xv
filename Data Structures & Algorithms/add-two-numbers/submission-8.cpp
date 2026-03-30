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
    ListNode* Add(ListNode* l1, ListNode* l2, int carryDigit)
    {
        if (!l1 && !l2 && carryDigit == 0)
        {
            return nullptr;
        }

        int v1 = 0;
        int v2 = 0;
        if (l1) { v1 = l1->val; }
        if (l2) { v2 = l2->val; }

        int sum = v1 + v2 + carryDigit;
        int newCarry = sum / 10;
        int nodeValue = sum % 10;

        ListNode* newNode = Add((l1 ? l1->next : nullptr), (l2 ? l2->next : nullptr), newCarry);
        return new ListNode(nodeValue, newNode);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return Add(l1, l2, 0);
        
        /*
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
        */
    }
};
