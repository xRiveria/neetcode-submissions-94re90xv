class Solution {
public:
    std::unordered_map<int, int> values; // Stores minimum coins needed to make a certain amount.
    int DFS(std::vector<int>& coins, int amount)
    {
        if (amount == 0) { return 0; }
        if (values.count(amount))
        {
            return values[amount];
        }

        int coinCount = 1e9;
        for (auto coin : coins)
        {
            if (amount - coin >= 0)
            {
                coinCount = std::min(coinCount, 1 + DFS(coins, amount - coin));
            }
        }

        values[amount] = coinCount; // Stores minimum coins needed to make this amount.

        return coinCount;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCount = DFS(coins, amount);
        return (minCount >= 1e9) ? -1 : minCount;
    }
};
