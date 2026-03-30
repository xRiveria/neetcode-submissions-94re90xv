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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         while (root != nullptr)
         {
            if (std::max(p->val, q->val) < root->val)
            {
                root = root->left;
            }
            else if (std::min(p->val, q->val) > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
         }

         return root;
    }
};
