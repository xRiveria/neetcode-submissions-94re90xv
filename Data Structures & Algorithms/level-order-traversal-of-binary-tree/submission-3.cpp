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
    std::vector<std::vector<int>> results;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int si = q.size();
            std::vector<int> r;
            while (si)
            {
                TreeNode* up = q.front();
                q.pop();
                r.push_back(up->val);

                if (up->left) q.push(up->left);
                if (up->right) q.push(up->right);
                si--;
            }
            results.push_back(r);
        }

        return results;
    }
};
