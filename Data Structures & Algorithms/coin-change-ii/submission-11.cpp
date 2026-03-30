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
                    // We can choose to skip the current coin.
                    // Meaning we add the number of ways to form the same amount [a] from (i + 1) onwards.
                    // this is already filled since we came from the highest coin amount backwards.
                    dp[i][a] = dp[i + 1][a];
                    // Or we use the current coin.
                    // Meaning we add the number of ways to form the amount (a - coins[i]).
                    // This is already filled since we came from amount = 0 onwards.
                    dp[i][a] += dp[i][a - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};
