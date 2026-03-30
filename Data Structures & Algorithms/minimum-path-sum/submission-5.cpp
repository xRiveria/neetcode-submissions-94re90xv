class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<int> dp(cols + 1, INT_MAX);
        dp[cols - 1] = 0;

        // We only need one row at any time, because every cell depends only on the row below and the part of the current row to the right.
        // So we reuse the same array by replacig its values continously instead of creating a big 2-D table.
        for (int r = rows - 1; r >= 0; r--)
        {
            for (int c = cols - 1; c >= 0; c--)
            {
                dp[c] = grid[r][c] += std::min(dp[c], dp[c + 1]);
            }
        }

        return dp[0];
    }
};