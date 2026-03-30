class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1, n); // Stores the smallest numbers of way to fill each target up to n.
        dp[0] = 0;

        // Build from target = 1 up to n.
        for (int target = 1; target <= n; target++)
        {   
            // Try every square (1, 4, 9, …) that is not bigger than target.
            for (int s = 1; s * s <= target; s++)
            {
                // If we use this square once, see if it gives us a better (smaller) answer.
                dp[target] = std::min(dp[target], 1 + dp[target - (s * s)]);
            }
        }

        return dp[n];
    }
};