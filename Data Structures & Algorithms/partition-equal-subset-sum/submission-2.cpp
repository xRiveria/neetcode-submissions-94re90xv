class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
        {
         sum += num;
        }   
        if (sum % 2 != 0)
        {
         return false;
        }

        int target = sum / 2;
        int n = nums.size();
        // Using the first i numbers, can we form j?
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = true; // We can always form target 0.
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= target; j++)
            {
                if (nums[i - 1] <= j) // Take it.
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j]; // Skip it.
                }
            }
        }

        return dp[n][target];
    }
};
