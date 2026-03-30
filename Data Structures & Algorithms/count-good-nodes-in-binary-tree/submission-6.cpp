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
    int totalValues = 0;
    void DFS(TreeNode* root, int currentMaxValue)
    {
        if (root == nullptr) return;

        if (currentMaxValue <= root->val)
        {
            totalValues++;
        }

        DFS(root->left, std::max(currentMaxValue, root->val));
        DFS(root->right, std::max(currentMaxValue, root->val));
    }

    int goodNodes(TreeNode* root) {
        DFS(root, INT_MIN);
        return totalValues;
    }
};
