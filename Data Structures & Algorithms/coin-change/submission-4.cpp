class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Holds minimum amount of coins needed to make the amount at i.
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                // coins[j] <= i implies that the coin at coins[j] can be used to make up i.
                if (coins[j] <= i)
                {
                    // “If I use this coin, how many coins would I need — and is that better than what I already have?”
                    // we ask: “What’s the minimum number of coins needed to make 4?” That value is already in dp.
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
