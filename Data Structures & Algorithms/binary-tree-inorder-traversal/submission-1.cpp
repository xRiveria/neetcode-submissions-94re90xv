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
    vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> results;
        std::stack<TreeNode*> vals;
        TreeNode* currentNode = root;

        while (currentNode != nullptr || !vals.empty())
        {
            // Go as far left as possible, process the current node, and move to the right subtree.
            while (currentNode)
            {
                vals.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = vals.top();
            vals.pop();
            results.push_back(currentNode->val);
            currentNode = currentNode->right;
        }

        return results;
    }
};