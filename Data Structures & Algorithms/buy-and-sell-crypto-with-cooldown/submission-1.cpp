class Solution {
public:
    int DFS(std::vector<int>& prices, int i, bool isBuying) // isBuying indicates whether we are allowed to buy or must sell.
    {
        if (i >= prices.size())
        {
            return 0;
        }

        // Always compute the option to skip the current day (cooldown).
        // This means we move to the next day without changing state.
        int cooldown = DFS(prices, i + 1, isBuying);
        // If we are allowed to buy...
        if (isBuying)
        {
            // Subtract price and move to the buying state.
            int buy = DFS(prices, i + 1, false) - prices[i];
            // The other choice is to skip the day. We take the max of these 2 options.
            return std::max(buy, cooldown);
        }
        else // If we are holding stock...
        {
            // Sell it today and skip the next day due to cooldown.
            int sell = DFS(prices, i + 2, true) + prices[i];
            // The other choice is to skip the day. We take the max of these 2 options.
            return std::max(sell, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        // Start the recursion from day 0 with buying = True.
        return DFS(prices, 0, true);
    }
};
