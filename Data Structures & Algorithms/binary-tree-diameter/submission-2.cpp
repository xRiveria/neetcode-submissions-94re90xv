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
    int DFS(TreeNode* root, int& diameterResult)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = DFS(root->left, diameterResult);
        int rightHeight = DFS(root->right, diameterResult);
        // At Node 2, the path 5, 3, 2, 4 forms the length of the path (3 edges).
        diameterResult = std::max(diameterResult, leftHeight + rightHeight);
        // Return the max of either the left or right as our parent node is only interested in that to form a long path.
        return 1 + std::max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameterResult = 0;
        DFS(root, diameterResult);
        return diameterResult;
    }
};
