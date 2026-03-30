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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        std::queue<TreeNode*> levels;
        levels.push(root);
        std::vector<std::vector<int>> results;
        while (!levels.empty())
        {
            int currentLevelSize = levels.size();
            std::vector<int> values;
            for (int i = 0; i < currentLevelSize; ++i)
            {
                TreeNode* topNode = levels.front();
                levels.pop();
                values.push_back(topNode->val);
                if (topNode->left) levels.push(topNode->left);
                if (topNode->right) levels.push(topNode->right);
            }
            results.push_back(values);
        }

        return results; 
    }
};
