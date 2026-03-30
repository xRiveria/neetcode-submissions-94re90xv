class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Modified Dijkstra here as we have a stop limit.
        int INF = 1e9;
        // Adjacency list for each flight from u -> v with price w.
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        // dist[city][stopsUsed] = bestCost.
        std::vector<std::vector<int>> dist(n, std::vector<int>(k + 5, INF));

        for (auto& flight : flights)
        {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        dist[src][0] = 0; // Distance at the source with 0 stops used is 0. This is always true.
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> minHeap;
        minHeap.emplace(0, src, -1);

        while (!minHeap.empty())
        {
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();
            if (node == dst) return cost;
            if (stops == k || dist[node][stops + 1] < cost) continue; // Hit a stop limit, or if the cost is worst than the best recorded for this city at (stops + 1), skip.
            for (auto& [nei, w] : adj[node])
            {
                int nextCst = cost + w;
                int nextStops = stops + 1;
                // If nextCost improves dist[nextCity][nextStops+1], update it and push into heap.
                if (dist[nei][nextStops + 1] > nextCst)
                {
                    dist[nei][nextStops + 1] = nextCst;
                    minHeap.emplace(nextCst, nei, nextStops);
                }
            }
        }
        return -1;
    }
};
