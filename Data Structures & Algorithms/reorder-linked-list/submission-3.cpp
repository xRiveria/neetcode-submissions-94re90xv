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
    ListNode* Recurse(ListNode* root, ListNode* current)
    {
        if (current == nullptr)
        {
            return root;
        }

        root = Recurse(root, current->next); // Get to the end.
        if (root == nullptr)
        {
            return nullptr;
        }

        ListNode* temp = nullptr;
        if (root == current || root->next == current)
        {
            current->next = nullptr;
        }
        else
        {
            temp = root->next;
            root->next = current;
            current->next = temp;
        }

        return temp;
    }

    void reorderList(ListNode* head) {
        head = Recurse(head, head->next);
    }
};
