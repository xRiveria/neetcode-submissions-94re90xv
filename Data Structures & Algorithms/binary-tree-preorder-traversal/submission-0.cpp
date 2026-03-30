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
    std::vector<int> results;
    void DFS(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        results.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        DFS(root);
        return results;
    }
};