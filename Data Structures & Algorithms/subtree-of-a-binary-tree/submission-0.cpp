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
    bool IsSame(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (root && subRoot && root->val == subRoot->val)
        {
            bool leftSame = IsSame(root->left, subRoot->left);
            bool rightSame = IsSame(root->right, subRoot->right);
            return leftSame && rightSame;
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::stack<TreeNode*> values;
        values.push(root);

        while (!values.empty())
        {
            TreeNode* val = values.top();
            values.pop();
            if (val == nullptr) continue;

            if (IsSame(val, subRoot))
            {
                return true;
            }
            else
            {
                values.push(val->left);
                values.push(val->right);
            }
        }

        return false;
    }
};
