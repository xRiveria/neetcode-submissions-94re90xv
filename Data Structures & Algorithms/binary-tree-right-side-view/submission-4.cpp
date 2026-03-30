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
    std::vector<int> values;
    void DFS(TreeNode* node, int depth)
    {
        if (!node) return;

        if (values.size() == depth)
        {
            values.push_back(node->val);
        }

        // Always traverse right. This means that we always add the right most value when we reach a new level.
        // If the right most level don't exist, we go left.
        DFS(node->right, depth + 1);
        DFS(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        DFS(root, 0);
        return values;
    }

    /*
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        std::vector<int> results;
        std::queue<TreeNode*> values;
        values.push(root);

        while (!values.empty())
        {
            TreeNode* rightNode = nullptr;
            int levelNodes = values.size();
            // For each level, we keep replacing the "rightNode" with nodes repeatedly.
            // The last node here is always the right mode value.
            for (int i = 0; i < levelNodes; ++i)
            {
                TreeNode* levelNode = values.front();
                values.pop();
                rightNode = levelNode;
                if (levelNode->left) values.push(levelNode->left);
                if (levelNode->right) values.push(levelNode->right);
            }

            if (rightNode)
            {
                results.push_back(rightNode->val);
            }
        }

        return results;
    }
    */
};
