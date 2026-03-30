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
    std::vector<std::string> SplitValues(const std::string& incomingString, char delimiter)
    {
        std::vector<std::string> results;
        std::stringstream stringStream(incomingString);
        std::string currentItem;
        while (std::getline(stringStream, currentItem, delimiter))
        {
            results.push_back(currentItem);
        }

        return results;
    }

    std::string JoinValues(const std::vector<std::string>& values, const std::string& delimiter)
    {
        std::ostringstream s;
        for (const auto& i : values)
        {
            if (&i != &values[0])
            {
                s << delimiter;
            }
            s << i;
        }

        return s.str();
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::vector<std::string> results;
        DFSSerialize(root, results);
        return JoinValues(results, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::string> values = SplitValues(data, ',');
        int i = 0;
        return DFSDeserialize(values, i);
    }

    void DFSSerialize(TreeNode* node, std::vector<std::string>& results)
    {
        if (!node)
        {
            results.push_back("N");
            return;
        }

        results.push_back(std::to_string(node->val));
        DFSSerialize(node->left, results);
        DFSSerialize(node->right, results);
    }

    TreeNode* DFSDeserialize(std::vector<std::string>& values, int& i)
    {
        if (values[i] == "N")
        {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(std::stoi(values[i]));
        i++;
        node->left = DFSDeserialize(values, i);
        node->right = DFSDeserialize(values, i);
        return node;
    }
};
