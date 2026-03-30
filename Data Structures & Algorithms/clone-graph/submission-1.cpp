/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::unordered_map<Node*, Node*> m_NodeToClone;

    Node* DFS(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        if (m_NodeToClone.count(node))
        {
            return m_NodeToClone[node];
        }

        Node* newNode = new Node(node->val);
        m_NodeToClone[node] = newNode;

        for (auto node : node->neighbors)
        {
            newNode->neighbors.push_back(DFS(node));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        return DFS(node);
    }
};
