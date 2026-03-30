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
    int maxPathSum(TreeNode* root)
    {
        int result = root->val;
        DFS(root, result);
        return result;
    }
    
    int DFS(TreeNode* root, int& result)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // If the downward path from a child is negative, discard it. Negative paths only hurt the total, so treat them as 0.
        int leftMax = std::max(DFS(root->left, result), 0);
        int rightMax = std::max(DFS(root->right, result), 0);

        result = std::max(result, root->val + leftMax + rightMax); // Save max results.

        // This forces DFS to return only a single-branch downward path because a parent can only extend down one direction, not both.
        return root->val + std::max(leftMax, rightMax);
    }
};
