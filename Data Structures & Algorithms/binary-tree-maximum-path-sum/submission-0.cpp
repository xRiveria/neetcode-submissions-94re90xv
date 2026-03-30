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
    int currentMaxThusFar = INT_MIN;

    /*
        GetMax helps compute the best downward path by returning the maximum sum of a path that starts at the given node, 
        and goes downward only (left or right child), and chooses the better of the two directions but never includes a negative contribution.
    */
    int GetMax(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = GetMax(root->left);
        int right = GetMax(root->right);
        // Adds the best path between the left and right.
        int path = root->val + std::max(left, right);
        // Skips negative contributions.
        return std::max(0, path);
    }

    void DFS(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        int recurseLeft = GetMax(root->left);
        int recurseRight = GetMax(root->right);
        currentMaxThusFar = std::max(currentMaxThusFar, recurseLeft + recurseRight + root->val);

        DFS(root->left);
        DFS(root->right);
    }

    int maxPathSum(TreeNode* root) {
        DFS(root);
        return currentMaxThusFar;
    }
};
