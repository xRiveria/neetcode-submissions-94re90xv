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

        // Current = Current node from the end.
        // Root = Corresponding node from the front.
        root = Recurse(root, current->next); // Get to the end.

        // Stop signal for the recursion once the list has already been fully reordered.
        if (root == nullptr)
        {
            return nullptr;
        }

        // Once the middle is reached, we return nullptr here. This triggers the above for all subsequent calls.
        ListNode* temp = nullptr;
        // If root meets or crosses current, we set current->next to nullptr to finish and stop further links.
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

        // Return the next node (temp) as the updated front pointer.
        return temp;
    }

    void reorderList(ListNode* head) {
        head = Recurse(head, head->next);
    }
};
