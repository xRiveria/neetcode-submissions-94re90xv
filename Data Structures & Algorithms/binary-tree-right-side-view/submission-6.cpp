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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        std::vector<int> results;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int currentSize = q.size();
            while (currentSize != 0)
            {
                TreeNode* currentNode = q.front();
                if ((currentSize - 1 == 0))
                {
                    results.push_back(currentNode->val);
                }
                q.pop();

                if (currentNode->left != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
                currentSize--;
            }
        }

        return results;
    }
};
