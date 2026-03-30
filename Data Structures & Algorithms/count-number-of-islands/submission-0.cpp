class Solution {
public:

    int m_IslandCount = 0;
    void DFS(std::vector<std::vector<char>>& grid, int i, int j)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
        {
            return;
        }

        if (grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0';

        // Carry on search in all four directions.
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    m_IslandCount++;
                    DFS(grid, i, j);
                }
            }
        }

        return m_IslandCount;
    }
};
