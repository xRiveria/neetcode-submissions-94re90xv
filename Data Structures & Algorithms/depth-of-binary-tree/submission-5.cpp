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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        std::stack<std::pair<TreeNode*, int>> s;
        s.push({root, 1});
        int depthThusFar = 0;

        while(!s.empty())
        {
            std::pair<TreeNode*, int> t = s.top();
            s.pop();
        
            depthThusFar = std::max(t.second, depthThusFar);

            if (t.first->left) s.push({t.first->left, t.second + 1});
            if (t.first->right) s.push({t.first->right, t.second + 1});
        }

        return depthThusFar;
    }
};
