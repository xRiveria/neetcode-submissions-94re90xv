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
        
        std::stack<TreeNode*> dfsStack;
        dfsStack.push(root);
        while (!dfsStack.empty())
        {
            TreeNode* topNode = dfsStack.top(); dfsStack.pop();
            std::swap(topNode->left, topNode->right);
            if (topNode->left != nullptr) { dfsStack.push(topNode->left); }
            if (topNode->right != nullptr) { dfsStack.push(topNode->right); }
        }

        return root;

        /*
        if (root == nullptr) return root;

        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty())
        {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();
            std::swap(node->left, node->right);
            if (node->left != nullptr) { bfsQueue.push(node->left); }
            if (node->right != nullptr) { bfsQueue.push(node->right); }
        }

        return root;

        */

        /*
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode* leftNode = invertTree(root->left);
        TreeNode* rightNode = invertTree(root->right);

        root->right = leftNode;
        root->left = rightNode;

        return root;
        */
    }
};
