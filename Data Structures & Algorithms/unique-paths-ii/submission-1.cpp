class Solution {
public:
    std::map<std::pair<int, int>, int> dfs;

    int DFS(std::vector<std::vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1)
        {
            return 0;
        }

        if ((i == (grid.size() - 1)) && (j == (grid[0].size() - 1)))
        {
            return 1;
        }

        if (dfs.count({ i, j }))
        {
            return dfs[{ i, j }];
        }

        dfs[{ i, j }] = DFS(grid, i + 1, j) + DFS(grid, i, j + 1);

        return dfs[{ i, j }];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        return DFS(obstacleGrid, 0, 0);
    }
};