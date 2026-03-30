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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<std::pair<TreeNode*, TreeNode*>> s;
        s.push({ p, q });

        while (!s.empty())
        {
            auto up = s.top();
            s.pop();

            if (up.first == nullptr && up.second == nullptr)
            {
                continue;
            }

            if (up.first == nullptr || up.second == nullptr)
            {
                return false;
            }

            if (up.first->val != up.second->val)
            {
                return false;
            }

            s.push({ up.first->left, up.second->left });
            s.push({ up.first->right, up.second->right });
        }

        return true;
    }
};
