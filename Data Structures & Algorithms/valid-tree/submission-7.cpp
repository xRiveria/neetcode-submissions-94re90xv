class Solution {
public:

    bool DFS(int i, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& neis, std::set<int>& visited, int n, int parent)
    {
        visited.insert(i);

        for (auto nei : neis[i])
        {
            if (nei == parent)
            {
                continue;
            }

            if (visited.count(nei)) // Cycle detection. Alternatively, check if edges == n - 1 at the start of the problem.
            {
                return false;
            }

            if (!DFS(nei, edges, neis, visited, n, i))
            {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A graph is a valid tree if it has n - 1 edges, has no cycles and is fully connected.
        // We  do not even need explicit cycle detection if you check edge count first.
        // if (edges.size() != n - 1)
        // {
        //     return false;
        // }

        std::vector<std::vector<int>> neis(n);
        for (auto edge : edges)
        {
            neis[edge[0]].push_back(edge[1]);
            neis[edge[1]].push_back(edge[0]); // If undirected, we should add both sides. 
        }

        std::set<int> visited;

        if (!DFS(0, edges, neis, visited, n, -1)) return false;

        if (visited.size() == n)
        {
            return true;
        }

        return false;
    }
};
