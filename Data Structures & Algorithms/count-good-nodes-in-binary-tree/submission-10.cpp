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
    int goodNodes(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> aPath;
        aPath.push({ root, INT_MIN });
        int totalValues = 0;
        while (!aPath.empty())
        {
            std::pair<TreeNode*, int> topValue = aPath.front();
            aPath.pop();

            if (topValue.first->val >= topValue.second)
            {
                totalValues++;
            }

            if (topValue.first->left != nullptr) aPath.push({ topValue.first->left, std::max(topValue.second, topValue.first->val) }); 
            if (topValue.first->right != nullptr) aPath.push({ topValue.first->right, std::max(topValue.second, topValue.first->val) }); 
        }

        return totalValues;
    }
};
