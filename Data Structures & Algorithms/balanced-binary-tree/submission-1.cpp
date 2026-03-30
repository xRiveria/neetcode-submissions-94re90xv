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
    int Height(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }        

        return 1 + std::max(Height(node->left), Height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }

        int heightOfLeftTree = Height(root->left);
        int heightOfRightTree = Height(root->right);

        if (std::abs(heightOfLeftTree - heightOfRightTree) > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
