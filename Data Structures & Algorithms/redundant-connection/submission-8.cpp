class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        std::vector<std::vector<int>> adj(n + 1);

        for (const auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            std::vector<bool> visited(n + 1, false);
            if (DFS(u, -1, adj, visited))
            {
                return { u, v };
            }
        }

        return {};
    }

    bool DFS(int node, int parent, std::vector<std::vector<int>>& adj, std::vector<bool>& visit)
    {
        if (visit[node]) return true;
        visit[node] = true;
        for (int nei : adj[node])
        {
            if (nei == parent) continue;
            if (DFS(nei, node, adj, visit)) return true;
        }

        return false;
    }
};
