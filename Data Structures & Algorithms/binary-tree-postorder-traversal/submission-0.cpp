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
    vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> vals;
        std::vector<int> results;

        TreeNode* currentNode = root;
        while (currentNode != nullptr || !vals.empty())
        {
            if (currentNode)
            {
                results.push_back(currentNode->val);
                vals.push(currentNode);
                currentNode = currentNode->right;
            }
            else
            {
                currentNode = vals.top();
                vals.pop();
                currentNode = currentNode->left;
            }
        }

        std::reverse(results.begin(), results.end());
        return results;
    }
};