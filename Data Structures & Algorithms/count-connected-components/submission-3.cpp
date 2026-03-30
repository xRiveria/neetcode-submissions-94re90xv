class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<bool> visit(n, false);
        for (const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visit[i])
            {
                result++;
                BFS(adj, visit, i);
            }
        }

        return result;
    }

    void BFS(std::vector<std::vector<int>>& adj, std::vector<bool>& visitedList, int node)
    {
        std::queue<int> vals;
        vals.push(node);
        visitedList[node] = true;
        while (!vals.empty())
        {
            int top = vals.front();
            vals.pop();

            for (int nei : adj[top])
            {
                if (!visitedList[nei])
                {
                    visitedList[nei] = true;
                    vals.push(nei);
                }
            }
        }
    }
};
