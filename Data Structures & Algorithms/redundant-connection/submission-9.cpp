class Solution {
public:
    std::vector<bool> visit;
    std::vector<std::vector<int>> adj;
    std::unordered_set<int> cycle;
    int cycleStart;

    bool DFS(int node, int par)
    {
        if (visit[node])
        {
            cycleStart = node;
            return true;
        }
        visit[node] = true;
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            if (DFS(nei, node))
            {
                if (cycleStart != -1) cycle.insert(node);
                if (node == cycleStart)
                {
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visit.resize(n + 1, false);
        cycleStart = -1;
        DFS(1, - 1);

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v))
            {
                return { u, v };
            }
        }

        return {};
    }
};
