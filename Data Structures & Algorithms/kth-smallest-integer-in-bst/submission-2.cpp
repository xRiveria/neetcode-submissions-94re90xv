/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> values;
        TreeNode* currentNode = root;

        while (!values.empty() || currentNode != nullptr)
        {
            // Ensures that we're always heading left in the tree.
            while (currentNode != nullptr)
            {
                values.push(currentNode); // Push current node.
                currentNode = currentNode->left; // Head left. 
            }

            // If we run out of left most values...
            // Start popping. The root of the subtreee is currently at the top.
            currentNode = values.top();
            values.pop();
            k--;
            // Exit immedietely once we find K. 
            if (k == 0)
            {
                return currentNode->val;
            }
            currentNode = currentNode->right; // Once we run out, push the right, repeat.
        }

        return -1;
    }
};
