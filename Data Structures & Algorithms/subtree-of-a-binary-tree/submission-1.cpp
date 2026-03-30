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
    bool IsSame(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (root && subRoot && root->val == subRoot->val)
        {
            bool leftSame = IsSame(root->left, subRoot->left);
            bool rightSame = IsSame(root->right, subRoot->right);
            return leftSame && rightSame;
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if (IsSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
