class Solution {
public:
    // Maintain a Selling and Buying state.
    // Also maintain cooldown.
    int DFS(std::vector<int>& prices, int i, bool isBuying)
    {
        if (i >= prices.size())
        {
            return 0;
        }

        if (isBuying)
        {
            int buyRoute = DFS(prices, i + 1, false) - prices[i];
            int cooldown = DFS(prices, i + 1, true);
            return std::max(buyRoute, cooldown);
        }

        if (!isBuying)
        {
            int sellRoute = DFS(prices, i + 2, true) + prices[i];
            int cooldown = DFS(prices, i + 1, false);
            return std::max(sellRoute, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        return DFS(prices, 0, true);
    }


};
