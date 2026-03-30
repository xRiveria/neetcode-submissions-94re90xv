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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        std::stack<TreeNode*> vals;
        std::vector<int> results;
        vals.push(root);

        while (!vals.empty())
        {
            TreeNode* current = vals.top(); vals.pop();
            results.push_back(current->val);
            if (current->right != nullptr) vals.push(current->right);
            if (current->left != nullptr) vals.push(current->left);
        }
        
        return results;
    }
};