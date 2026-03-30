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
    int rob(TreeNode* root) {
        std::pair<int, int> result = DFS(root);
        return std::max(result.first, result.second); // First = With Root, Second = Skip Root
    }
    
    std::pair<int, int> DFS(TreeNode* root)
    {
        if (!root)
        {
            return { 0, 0 };
        }

        std::pair<int, int> leftPair = DFS(root->left);
        std::pair<int, int> rightPair = DFS(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        // Because sometimes skipping a child gives more money than robbing it (due to grandchildren).
        int withoutRoot = std::max(leftPair.first, leftPair.second) + std::max(rightPair.first, rightPair.second);

        return { withRoot, withoutRoot };


    }
};