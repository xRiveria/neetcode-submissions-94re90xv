class Solution {
public:
    void DFS(std::vector<std::vector<int>>& edges, std::vector<bool>& visited, int node)
    {
        visited[node] = true;
        for (int i = 0; i < edges[node].size(); ++i)
        {
            if (!visited[edges[node][i]])
            {
                DFS(edges, visited, edges[node][i]);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<bool> visited(n, false);
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                DFS(adj, visited, i);
                result++;
            }
        }

        return result;
    }
};
