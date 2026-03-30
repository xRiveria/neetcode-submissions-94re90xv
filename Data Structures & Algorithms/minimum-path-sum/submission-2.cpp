class Solution {
public:
    std::vector<std::vector<int>> dp;
    int dfs(int r, int c, std::vector<std::vector<int>>& grid)
    {
        if (r == grid.size() - 1 && c == grid[0].size() - 1)
        {
            return grid[r][c];
        }

        if (r == grid.size() || c == grid[0].size())
        {
            return INT_MAX;
        }

        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        dp[r][c] = grid[r][c] + std::min(dfs(r + 1, c, grid), dfs(r, c + 1, grid));
        return dp[r][c];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
        return dfs(0, 0, grid);
    }
};