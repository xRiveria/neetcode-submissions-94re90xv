class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A graph is a valid tree if it has no cycles and if it is fully connected.
        // This means a tree with N nodes must have exactly (N - 1) edges. Otherwise, it is invalid.
        if (edges.size() != (n - 1))
        {
            return false;
        }

        std::vector<std::vector<int>> adjacencyList(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
        }

        std::unordered_set<int> visitedNodes;
        if (!DFS(0, -1, visitedNodes, adjacencyList))
        {
            return false;
        }

        // If we're visited every node once, it means every node is fully connected.
        return visitedNodes.size() == n;
    }

    bool DFS(int nodeIndex, int previousNode, std::unordered_set<int>& visitedNodes, std::vector<std::vector<int>>& adjacencyList)
    {
        // We've visited this node before.
        if (visitedNodes.count(nodeIndex))
        {
            return false;
        }

        visitedNodes.insert(nodeIndex);
        for (int neighbor : adjacencyList[nodeIndex])
        {
            // This will stop us from visiting the previous node because it is also a neighbor.
            if (neighbor == previousNode)
            {
                continue;
            }

            if (!DFS(neighbor, nodeIndex, visitedNodes, adjacencyList))
            {
                return false;
            }
        }

        return true;
    }
};
