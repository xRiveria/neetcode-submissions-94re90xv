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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize != 0)
            {
                TreeNode* temp = q.front(); q.pop();
                std::swap(temp->left, temp->right);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                qSize--;
            }
        }

        return root;
    }
};
