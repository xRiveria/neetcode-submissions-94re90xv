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
    bool Check(TreeNode* node, int leftBounds, int rightBounds)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->val <= leftBounds || node->val >= rightBounds)
        {
            return false;
        }

        return Check(node->left, leftBounds, node->val) && Check(node->right, node->val, rightBounds);
    }

    bool isValidBST(TreeNode* root) {
        return Check(root, INT_MIN, INT_MAX);
    }
};
