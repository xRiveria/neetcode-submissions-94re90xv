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
    // For this question, we are only inserting into the leafs. 
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* rootCopy = root;
        while (true)
        {
            if (root->val > val)
            {
                if (root->left == nullptr)
                {
                    root->left = new TreeNode(val);
                    return rootCopy;
                }
                root = root->left;
            }
            else
            {
                if (root->right == nullptr)
                {
                    root->right = new TreeNode(val);
                    return rootCopy;
                }
                root = root->right;
            }
        }
    }
};