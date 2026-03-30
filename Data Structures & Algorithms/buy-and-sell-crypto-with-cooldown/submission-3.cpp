class Solution {
public:
    std::map<std::pair<int, bool>, int> dfs;
    // Maintain a Selling and Buying state.
    // Also maintain cooldown.
    int DFS(std::vector<int>& prices, int i, bool isBuying)
    {
        if (i >= prices.size())
        {
            return 0;
        }

        if (dfs.count({ i, isBuying }))
        {
            return dfs[{i, isBuying}];
        }

        int cooldown = DFS(prices, i + 1, isBuying);
        if (isBuying)
        {
            int buyRoute = DFS(prices, i + 1, false) - prices[i];
            dfs[{i, isBuying}] = std::max(buyRoute, cooldown);
            return std::max(buyRoute, cooldown);
        }

        if (!isBuying)
        {
            int sellRoute = DFS(prices, i + 2, true) + prices[i];
            dfs[{i, isBuying}] = std::max(sellRoute, cooldown);
            return std::max(sellRoute, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        return DFS(prices, 0, true);
    }


};
