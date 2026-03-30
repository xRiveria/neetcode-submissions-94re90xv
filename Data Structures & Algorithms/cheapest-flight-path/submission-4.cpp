class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& flight : flights)
        {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        std::queue<std::tuple<int, int, int>> q;
        // We only continue expanding a path if stops <= k.
        // The stop constraint naturally prevents infinite relaxation loops.
        // Only promising states (those that improve cost) are pushed into the queue.
        q.push({ 0, src, 0 }); // currentCost, city, stopsUsed

        while (!q.empty())
        {
            auto [cost, node, stops] = q.front();
            q.pop();
            if (stops > k) continue; // Too many stops made to keep continuing. Reject
            for (const auto& neighbor : adj[node])
            {
                int nei = neighbor.first, w = neighbor.second;
                int nextCost = cost + w;
                if (nextCost < prices[nei])
                {
                    prices[nei] = nextCost;
                    q.push({ nextCost, nei, stops + 1 });
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];

    }
};
