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
            DFS(root, 0);
            return results;
        }

        void DFS(TreeNode* root, int currentLevel)
        {
            if (!root)
            {
                return;
            }

            if (results.size() == currentLevel)
            {
                results.push_back(std::vector<int>());
            }

            results[currentLevel].push_back(root->val);
            DFS(root->left, currentLevel + 1);
            DFS(root->right, currentLevel + 1);
        }
    

        /*
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
        */
};
