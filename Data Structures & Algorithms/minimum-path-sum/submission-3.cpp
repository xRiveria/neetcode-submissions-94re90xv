class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, INT_MAX));
        dp[rows - 1][cols] = 0;

        for (int r = rows - 1; r >= 0; r--)
        {
            for (int c = cols - 1; c >= 0; c--)
            {
                dp[r][c] = grid[r][c] + std::min(dp[r + 1][c], dp[r][c + 1]);
            }
        }

        return dp[0][0];
    }
};