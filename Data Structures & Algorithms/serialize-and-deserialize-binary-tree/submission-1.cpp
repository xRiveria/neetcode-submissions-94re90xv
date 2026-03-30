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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        std::string results;
        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty())
        {
            TreeNode* treeNode = bfsQueue.front();
            bfsQueue.pop();

            if (treeNode == nullptr)
            {
                results += "N,";
            }
            else
            {
                results += std::to_string(treeNode->val) + ",";
                bfsQueue.push(treeNode->left);
                bfsQueue.push(treeNode->right);
            }
        }

        return results;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string currentString;
        std::getline(ss, currentString, ',');
        if (currentString == "N") return nullptr;

        TreeNode* rootNode = new TreeNode(std::stoi(currentString));
        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(rootNode);

        while (std::getline(ss, currentString, ','))
        {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();
            if (currentString != "N")
            {
                node->left = new TreeNode(std::stoi(currentString));
                bfsQueue.push(node->left);
            }
            std::getline(ss, currentString, ',');
            if (currentString != "N")
            {
                node->right = new TreeNode(std::stoi(currentString));
                bfsQueue.push(node->right);
            }
        }

        return rootNode;
    }
};
