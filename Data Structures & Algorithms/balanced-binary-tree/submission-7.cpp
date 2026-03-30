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
    bool isBalancedd = true;
    int DFS(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftNode = DFS(node->left);
        int rightNode = DFS(node->right);

        if (std::abs(leftNode - rightNode) > 1)
        {
            isBalancedd = false;
        }

        return 1 + std::max(leftNode, rightNode);
    }

    bool isBalanced(TreeNode* root) {
        DFS(root);
        return isBalancedd;
    }
};
