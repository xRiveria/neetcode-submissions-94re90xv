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
    // The trick to this question is to understand that if at any point, p and q splits into different trees, the current node is the LCA.
    // Then, we need to note that if p and q's values are both lesser than root, then the LCM is in the left subtree.
    // We dive left.
    // If both are more than root, then the LCM is in the right subtree.
    // Else its the first condition, return it.
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
