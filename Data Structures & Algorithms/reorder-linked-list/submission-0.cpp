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
        std::vector<ListNode*> nodeList;
        ListNode* currentHead = head;
        while (currentHead != nullptr)
        {
            nodeList.push_back(currentHead);
            currentHead = currentHead->next;
        }

        int i = 0, j = nodeList.size() - 1;
        while (i < j)
        {
            nodeList[i]->next = nodeList[j];
            i++;
            if (i >= j) break; // We cannot set nodeList[j] to point to itself or next.
            nodeList[j]->next = nodeList[i];
            j--;
        }

        nodeList[i]->next = nullptr; // This implies that we're at the end of the list. Set next to nullptr.
    }
};
