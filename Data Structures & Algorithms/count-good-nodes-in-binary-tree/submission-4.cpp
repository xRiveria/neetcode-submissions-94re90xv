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
    int goodNodes(TreeNode* root)
    {
        int results = 0;
        std::queue<std::pair<TreeNode*, int>> values;
        values.push({ root, INT_MIN });

        while (!values.empty())
        {
            std::pair<TreeNode*, int> topVal = values.front();
            values.pop();
            if (topVal.first == nullptr) continue;
            if (topVal.first->val >= topVal.second) results++;
            int maxValueThusFar = std::max(topVal.first->val, topVal.second);
            values.push({ topVal.first->left, maxValueThusFar });
            values.push({ topVal.first->right, maxValueThusFar });
        }

        return results;
    }

    // // The trick here is to realize that...
    // // A node is good if is the largest from itself to the root.
    // // We simply need to keep updating a "maxValue" whilst heading down the tree, DFS style.
    // // Everything accumulates into isGood, which sums up all good nodes beginning from the root and returns it.
    // int DFS(TreeNode* rootNode, int maxValueOnPath)
    // {
    //     if (rootNode == nullptr)
    //     {
    //         return 0;
    //     }

    //     int isGood = (rootNode->val >= maxValueOnPath) ? 1 : 0;
    //     maxValueOnPath = std::max(maxValueOnPath, rootNode->val);
    //     isGood += DFS(rootNode->left, maxValueOnPath);
    //     isGood += DFS(rootNode->right, maxValueOnPath);
        
    //     return isGood;
    // }

    // int goodNodes(TreeNode* root) {
    //     return DFS(root, root->val);
    // }
};
