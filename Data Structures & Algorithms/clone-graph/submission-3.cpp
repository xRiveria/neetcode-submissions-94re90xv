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

    // BFS means that we're duplicating all neighbors of the current node first before moving on to the next node! Remember that!
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        m_NodeToClone[node] = new Node(node->val);
        std::queue<Node*> currentNodes;
        currentNodes.push(node);

        while (!currentNodes.empty())
        {
            Node* currentNode = currentNodes.front();
            currentNodes.pop();

            for (auto nodeNeighbor : currentNode->neighbors)
            {
                if (!m_NodeToClone.count(nodeNeighbor))
                {
                     Node* newNodeThing = new Node(nodeNeighbor->val);
                     m_NodeToClone[nodeNeighbor] = newNodeThing;
                     currentNodes.push(nodeNeighbor);
                }

                m_NodeToClone[currentNode]->neighbors.push_back(m_NodeToClone[nodeNeighbor]);
            }
        }

        return m_NodeToClone[node];
    }
};
