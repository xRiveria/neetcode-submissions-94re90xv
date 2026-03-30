class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        // We are allowed at most k stops, which means at most k + 1 flights (edges).
        // S -> Stop 1 -> D | If 1 stop, means 2 edges here as seen.
        for (int i = 0; i <= k; ++i)
        {
            std::vector<int> tempPrices = prices;
            for (const auto& flight : flights)
            {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];

                // If not reachable, skip.
                if (prices[s] == INT_MAX) continue;

                // Otherwise, we try relaxing the edge. 
                if (prices[s] + p < tempPrices[d])
                {
                    tempPrices[d] = prices[s] + p;
                }
            }

            prices = tempPrices;
        }

        // After all iterations, if prices[dst] is still infinity, we return -1. 
        return prices[dst] == INT_MAX? - 1 : prices[dst];
    }
};
