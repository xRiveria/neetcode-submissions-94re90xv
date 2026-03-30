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
    int DFS(TreeNode* root, int currentMaxValue)
    {
        if (root == nullptr) return 0;

        int result = 0;
        if (root->val >= currentMaxValue)
        {
            result++;
        }

        result += DFS(root->left, std::max(currentMaxValue, root->val));
        result += DFS(root->right, std::max(currentMaxValue, root->val));

        return result;
    }

    int goodNodes(TreeNode* root) {
        return DFS(root, INT_MIN);
    }
};
