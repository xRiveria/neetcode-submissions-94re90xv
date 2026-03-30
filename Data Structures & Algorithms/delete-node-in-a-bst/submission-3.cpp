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
        // Each recursive call modifies a subtree and returns its new root. Forgetting to assign the return value back to root.left or root.right means the deletion is not reflected in the tree.
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
            // “Delete the node, promote its right child, and hang the left subtree under the smallest node on the right.”
            currentNode->left = root->left;
            TreeNode* result = root->right;
            delete root;
            return result;
        }

        return root;
    }
};