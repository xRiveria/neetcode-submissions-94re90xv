class Solution {
public:
    std::map<std::pair<int, bool>, int> cache;
    int DFS(std::vector<int>& prices, int i, bool didBuy)
    {
        if (i >= prices.size())
        {
            return 0;
        }
        
        if (cache.count({ i, didBuy })) return cache[{ i, didBuy }];
        
        // Always an option to do nothing and skip.
        int result = DFS(prices, i + 1, didBuy);
        if (didBuy)
        {
            // Sell
            result = std::max(result, prices[i] + DFS(prices, i + 1, false));
        }
        else
        {
            // Buy
            result = std::max(result, -prices[i] + DFS(prices, i + 1, true));
        }
        
        cache[{ i, didBuy }] = result;
        return result;
    }

    int maxProfit(vector<int>& prices) {
        return DFS(prices, 0, false);
    }
};