class Solution {
public:
    int m_MaxArea = 0;
    void DFS(std::vector<std::vector<int>>& grid, int i, int j, int& currentArea)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
        {
            return;
        }

        if (grid[i][j] != 1)
        {
            return;
        }

        currentArea++;
        grid[i][j] = 0;

        DFS(grid, i + 1, j, currentArea);
        DFS(grid, i - 1, j, currentArea);
        DFS(grid, i, j + 1, currentArea);
        DFS(grid, i, j - 1, currentArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int currentArea = 0;
                DFS(grid, i, j, currentArea);
                m_MaxArea = std::max(currentArea, m_MaxArea);
            }
        }

        return m_MaxArea;
    }
};
