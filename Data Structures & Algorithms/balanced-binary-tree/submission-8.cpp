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
    bool isBalanced(TreeNode* root) {
        std::stack<TreeNode*> s;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        std::unordered_map<TreeNode*, int> depths;

        while (!s.empty() || node != nullptr)
        {
            if (node != nullptr)
            {
                s.push(node);
                node = node->left; // Traverse left as much as possible. When left is done, try right.
            }
            else
            {
                node = s.top();
                if (node->right == nullptr || last == node->right)
                {
                    s.pop();
                    int left = depths[node->left];
                    int right = depths[node->right];
                    if (std::abs(left - right) > 1) return false;
                    depths[node] = 1 + std::max(left, right);
                    last = node;
                    node = nullptr;
                }
                else
                {
                    node = node->right;
                }
            }
        }

        return true;
    }
};
