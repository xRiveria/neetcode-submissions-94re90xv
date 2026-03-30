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
    void DFS(TreeNode* root, std::vector<int>& values)
    {
        if (root == nullptr)
        {
            return;
        }

        DFS(root->left, values);
        
        // Our Kth smallest value is guaranteed to exist once we reach K == 0.
        // We just need to grab whatever value is here right now and return it. 
        values[0]--;
        if (values[0] == 0)
        {
            values[1] = root->val;
            return;
        }

        DFS(root->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
       std::vector<int> tempStorage(2);
       tempStorage[0] = k;
       DFS(root, tempStorage);
       return tempStorage[1];
    }
};
