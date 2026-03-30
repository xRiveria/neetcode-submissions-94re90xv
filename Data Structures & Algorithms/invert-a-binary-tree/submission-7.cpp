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
    TreeNode* Invert(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        std::swap(root->left, root->right);
        Invert(root->left);
        Invert(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return Invert(root);
    }
};
