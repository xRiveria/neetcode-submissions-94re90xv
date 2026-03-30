class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // root is the node to delete
            if (!root->left) {
                TreeNode* r = root->right;
                delete root;
                return r;
            }
            if (!root->right) {
                TreeNode* l = root->left;
                delete root;
                return l;
            }

            // two children: replace with inorder successor (min in right subtree)
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;

            root->val = succ->val;                  // copy successor value
            root->right = deleteNode(root->right, succ->val); // delete successor node
        }
        return root;
    }
};
