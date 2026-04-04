class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != (n - 1))
        {
            return false;
        }

        std::vector<std::vector<int>> adj(n);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        std::queue<std::pair<int, int>> q;
        std::set<int> visited;
        q.push({ 0, -1 });
        while (!q.empty())
        {
            auto t = q.front(); q.pop();
            visited.insert(t.first);
            
            for (auto nei : adj[t.first])
            {
                if (nei == t.second) continue;
                if (visited.count(nei)) return false; // Cycle

                q.push({ nei, t.first });
            }
        }

        return visited.size() == n;
    }
};
