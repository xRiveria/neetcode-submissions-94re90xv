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
            TreeNode* previous = root;

            if (root->val > val)
            {
                root = root->left;
                if (root == nullptr)
                {
                    previous->left = new TreeNode(val);
                    break;
                }
            }
            else if (root->val < val)
            {
                root = root->right;
                if (root == nullptr)
                {
                    previous->right = new TreeNode(val);
                    break;
                }
            }
        }

        return rootCopy;
    }
};