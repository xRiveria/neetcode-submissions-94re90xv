class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # If we know the minimum coins to make a - coin, then we know we can make a using 1 extra coin. 
        # Each amount depends on previously solved smaller amounts. 
        # Instead of asking how many coins to make this amount, we build answers from smaller amounts to larger ones. 
        # Each dp[a] is the minimum number of coins to make amount a.

        dp = [amount + 1] * (amount + 1) # 0 coins to make amount 0 .
        dp[0] = 0

        for a in range(1, amount + 1):
            for c in coins:
                if a - c >= 0:
                    dp[a] = min(dp[a], 1 + dp[a - c])
        return dp[amount] if dp[amount] != amount + 1 else - 1