class Solution {
public:
    std::vector<std::vector<int>> adj;
    std::vector<bool> visit;
    std::unordered_set<int> cycle;
    int cycleStart;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        for (auto& edge: edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visit.resize(n + 1, false);
        cycleStart = -1;
        DFS(1, -1);

        // There must be a redundant edge connecting two cycle nodes.
        // Return the first edge (u, v) where both endpoints are in cycle.
        // Return the first edge (u, v) where u and v are both in the cycle list.
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)) {
                return {u, v};
            }
        }
        return {};
    }

    // If we reach a node that is already visited, we just found the start of the cycle.
    // While recursion rewinds, we mark every node on that return path as part of the cycle until we come back to the cycle's start. 
    bool DFS(int node, int par)
    {
        if (visit[node]) // If we've been here before, it means we found a cycle. We will mark this node as the start of the cycle.
        {
            cycleStart = node;
            return true;
        }

        visit[node] = true;
        for (int neigh : adj[node])
        {
            if (neigh == par) continue;
            if (DFS(neigh, node))
            {
                if (cycleStart != -1)
                {
                    cycle.insert(node); // We are in a cycle. Record down this node.
                }
                if (node == cycleStart) // Once we're back at the start of the cycle, we're done. 
                {
                    cycleStart = -1;
                }

                return true;
            }
        }

        return false;
    }
};
