class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coinCount = coins.size();
        std::sort(coins.begin(), coins.end());
        // dp[i][a] represents the number of ways to form amount 'a' using coins from index i onwards.
        std::vector<std::vector<int>> dp(coinCount + 1, std::vector<int>(amount + 1, 0));

        // 1 way to form amount 0 (choose no coins).
        for (int i = 0; i <= coinCount; ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = coinCount - 1; i >= 0; --i)
        {
            for (int a = 0; a <= amount; ++a)
            {
                // If the current coin can be used...
                if (a >= coins[i])
                {
                    // Either we skip the current coin. 
                    dp[i][a] = dp[i + 1][a];
                    // Or we use the current coin.
                    // Add both to get the total number of ways to form amount a using coins from index i onwards.
                    dp[i][a] += dp[i][a - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};
