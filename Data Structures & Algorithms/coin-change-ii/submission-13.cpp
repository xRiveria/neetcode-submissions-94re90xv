class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0); // dp[a] represents the number of ways to form amount a.
        dp[0] = 1;
        for (int i = coins.size() - 1; i >= 0; --i)
        {
            for (int a = 1; a <= amount; ++a)
            {
                dp[a] += (coins[i] <= a ? dp[a - coins[i]] : 0);
            }
        }

        return dp[amount];
    }
};
