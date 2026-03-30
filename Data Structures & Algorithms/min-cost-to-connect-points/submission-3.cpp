class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        for (int i = 0; i < n; ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; ++j)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = std::abs(x1 - x2) + std::abs(y1 - y2);
                adj[i].push_back({ dist, j });
                adj[j].push_back({ dist, i });
            }
        }

        int result = 0;
        std::unordered_set<int> visit;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

        minHeap.push({ 0, 0 });
        while (visit.size() < n) // As long as we haven't visited all nodes...
        {
            // Always visit the cheapest node connected to the current one. 
            auto current = minHeap.top();
            minHeap.pop();
            int cost = current.first;
            int i = current.second;
            if (visit.count(i)) continue;
            visit.insert(i);

            result += cost;
            for (const auto& nei : adj[i])
            {
                int neiCost = nei.first;
                int neiIndex = nei.second;
                if (!visit.count(neiIndex))
                {
                    minHeap.push({ neiCost, neiIndex });
                }
            }
        }

        return result;
    }
};
