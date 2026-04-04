class Solution {
public:

    void DFS(int i, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& neis, std::set<int>& visited, int n, int parent)
    {
        visited.insert(i);

        for (auto nei : neis[i])
        {
            if (nei == parent)
            {
                continue;
            }

            if (!visited.count(nei))
            {
                DFS(nei, edges, neis, visited, n, i);     
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A valid tree has no cycles and must have exactly n - 1 edges.
        if (edges.size() != n - 1)
        {
            return false;
        }


        std::vector<std::vector<int>> neis(n);
        for (auto edge : edges)
        {
            neis[edge[0]].push_back(edge[1]);
            neis[edge[1]].push_back(edge[0]); // If undirected, we should add both sides. 
        }

        std::set<int> visited;

        DFS(0, edges, neis, visited, n, -1);
        if (visited.size() == n)
        {
            return true;
        }

        return false;
    }
};
