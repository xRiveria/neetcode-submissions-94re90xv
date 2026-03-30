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
    TreeNode* invertTree(TreeNode* root) {
      if (!root) return nullptr;
      
      std::stack<TreeNode*> s;
      s.push(root);

      while (!s.empty())
      {
        TreeNode* t = s.top();
        s.pop();
        std::swap(t->left, t->right);
        if (t->left) s.push(t->left);
        if (t->right) s.push(t->right);
      }

      return root;
    }
};
