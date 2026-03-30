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
    std::vector<int> values;

    void DFS(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left)
        {
            DFS(root->left);
        }

        values.push_back(root->val);

        if (root->right)
        {
            DFS(root->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
       DFS(root);
       return values[k - 1];
    }
};
