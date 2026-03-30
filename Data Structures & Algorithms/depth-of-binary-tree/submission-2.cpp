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
    int maxDepth(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> dfsStack;
        dfsStack.push({ root, 1 });
        int result = 0;

        while (!dfsStack.empty())
        {
            std::pair<TreeNode*, int> currentNode = dfsStack.top();
            dfsStack.pop();
            TreeNode* node = currentNode.first;
            int depth = currentNode.second;

            if (node != nullptr)
            {
                result = std::max(result, depth);
                dfsStack.push({node->left, depth + 1});
                dfsStack.push({node->right, depth + 1});
            }
        }

        return result;
        /*
        // A BFS on a tree, explores the breadth of each level.
        // BFS makes sure to explore a level in its entirety.
        std::queue<TreeNode*> depthQueue;
        if (root != nullptr)
        {
            depthQueue.push(root);
        }

        int level = 0;
        while (!depthQueue.empty())
        {
            int levelSize = depthQueue.size(); // Get the size of the current level.
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* top = depthQueue.front();
                depthQueue.pop();
                if (top->left != nullptr)
                {
                    depthQueue.push(top->left);
                }
                if (top->right != nullptr)
                {
                    depthQueue.push(top->right);
                }
            }

            level++;
        }

        return level;
        */
        /*
        if (root == nullptr)
        {
            return 0;
        }
        
        int leftTotal = maxDepth(root->left);
        int rightTotal = maxDepth(root->right);

        return 1 + std::max(leftTotal, rightTotal);
        */
    }
};
