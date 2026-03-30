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

// The trick here is to treat the Preorder list as roots.
// We will also create a hashmap to store each value in the inorder list with their indexes.
// This is crucial to avoid constant lookups.
// Notice how at each root value's position in the inorder list, its left subtree is always to its left.
// And its right subtree is always to its right.
// We will use this property to keep rebuilding the tree, returning the top root at end recursively.
class Solution {
public:
    std::unordered_map<int, int> values;
    int preIndex = 0;

    TreeNode* DFS(std::vector<int> preorder, int l, int r)
    {
        if (l > r) return nullptr;
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int mid = values[rootValue]; // This index is surrounded by its left and right child.
        root->left = DFS(preorder, l, mid - 1);
        root->right = DFS(preorder, mid + 1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
        {
            // Value to Index
            values[inorder[i]] = i;
        }

        return DFS(preorder, 0, inorder.size() - 1);
    }
};
