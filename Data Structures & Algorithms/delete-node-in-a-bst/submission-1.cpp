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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // We found the node to delete.
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // If has both children. Find the inorder successor.
            TreeNode* currentNode = root->right;
            while (currentNode->left)
            {
                currentNode = currentNode->left;
            }
            root->val = currentNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        
        return root;
    }
};