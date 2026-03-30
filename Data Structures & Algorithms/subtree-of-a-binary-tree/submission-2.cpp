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
    bool IsSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (root != nullptr && subRoot != nullptr && root->val == subRoot->val)
        {
            return IsSameTree(root->left, subRoot->left) && IsSameTree(root->right, subRoot->right);
        }
        
        return false;
    }

    bool DFS(TreeNode* root, TreeNode* subRoot)
    {
        if (subRoot == nullptr)
        {
            return true; // Empty tree is always a subtree.
        }

        if (root == nullptr && subRoot != nullptr)
        {
            return false;
        }

        bool isSameTree = IsSameTree(root, subRoot);
        if (!isSameTree)
        {
            return DFS(root->left, subRoot) || DFS(root->right, subRoot);
        }
        else
        {
            return true;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       return DFS(root, subRoot);
    }
};
