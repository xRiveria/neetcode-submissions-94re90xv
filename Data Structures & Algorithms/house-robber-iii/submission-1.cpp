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
    std::unordered_map<TreeNode*, int> cache;
    int Recurse(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        if (cache.count(root))
        {
            return cache[root];
        }

        int robCurrentNode = root->val;
        if (root->left)
        {
            robCurrentNode += Recurse(root->left->left) + Recurse(root->left->right);
        }

        if (root->right)
        {
            robCurrentNode += Recurse(root->right->left) + Recurse(root->right->right);
        }

        int robChildren = Recurse(root->left) + Recurse(root->right);
        cache[root] = std::max(robCurrentNode, robChildren);
        return cache[root];
    }

    int rob(TreeNode* root) {
        return Recurse(root);
    }
};