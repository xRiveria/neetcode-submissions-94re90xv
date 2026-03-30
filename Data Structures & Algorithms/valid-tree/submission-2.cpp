class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A fully connected tree must also have count of edges = (n - 1). Minus 1 since the root would have no incoming edge.
        // This is a fundamental property of trees.
        if (edges.size() != n - 1)
        {
            return false;
        }
        
        std::vector<std::vector<int>> edgesCache(n);
        for (auto& e : edges)
        {
            edgesCache[e[0]].push_back(e[1]);
            edgesCache[e[1]].push_back(e[0]);
        }

        std::unordered_set<int> visit;
        std::queue<std::pair<int, int>> q;
        q.push({ 0, -1 }); // Current Node, Parent Node
        visit.insert(0);

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();
            for (int neighbor : edgesCache[node])
            {
                if (neighbor == parent) continue;
                
                if (visit.count(neighbor)) return false;

                visit.insert(neighbor);
                q.push({ neighbor, node });
            }
        }

        return visit.size() == n;
    }
};
