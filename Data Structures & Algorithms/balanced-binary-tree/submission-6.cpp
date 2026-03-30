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
    bool isBalanced(TreeNode* root) {
        // Post order traversal is Left → Right → Node.
        std::stack<TreeNode*> dfsStack;
        TreeNode* node = root;
        TreeNode* last = nullptr; // Last stores the most recently processed node (the last node you fully visited).
        std::unordered_map<TreeNode*, int> depths;

        while (!dfsStack.empty() || node != nullptr)
        {
            if (node != nullptr)
            {
                dfsStack.push(node);
                node = node->left;
            }
            else // We have reached the end of a left subtree.
            {
                node = dfsStack.top();
                // “We just finished the right subtree, so now we can process this node.”
                // Without it, when the algorithm finishes the left subtree and returns to a node, 
                // it would immediately process the node—even though the right subtree has not yet been processed.
                // So, if last == node->right, it means we have returned from processing the right subtree.
                if (node->right == nullptr || last == node->right)
                {
                    dfsStack.pop();
                    int left = depths[node->left];
                    int right = depths[node->right];
                    if (std::abs(left - right) > 1) return false;
                    depths[node] = 1 + std::max(left, right);
                    last = node;
                    node = nullptr;
                }
                else
                {
                    node = node->right;
                }
            }
        }

        return true;
    }
};
