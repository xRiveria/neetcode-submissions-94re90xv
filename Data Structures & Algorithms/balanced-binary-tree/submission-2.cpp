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
    // Return [isBalanced, Height]
    std::vector<int> DFS(TreeNode* root)
    {
        if (!root)
        {
            return { 1, 0 };
        }

        std::vector<int> left = DFS(root->left);
        std::vector<int> right = DFS(root->right);

        bool balanced = (left[0] == 1 && right[0] == 1) &&
                        (std::abs(left[1] - right[1]) <= 1);
        int height = 1 + std::max(left[1], right[1]);

        return { balanced ? 1 : 0, height };
    }

    bool isBalanced(TreeNode* root) {
        return DFS(root)[0] == 1;
    }
};
