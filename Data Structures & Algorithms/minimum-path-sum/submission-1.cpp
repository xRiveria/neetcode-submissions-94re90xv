class Solution {
public:
    // std::set<std::pair<int, int>> cache;
    int m_MinimumSum = INT_MAX;

    void DFS(std::vector<std::vector<int>>& grid, int i, int j, int costThusFar)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }

        costThusFar += grid[i][j];

        if (costThusFar >= m_MinimumSum) 
        {
            return;
        }

        if ((i == (grid.size() - 1)) && (j == (grid[0].size() - 1)))
        {
            m_MinimumSum = std::min(m_MinimumSum, costThusFar);
            return;
        }

        DFS(grid, i + 1, j, costThusFar);
        DFS(grid, i, j + 1, costThusFar);
    }

    int minPathSum(vector<vector<int>>& grid) {
        DFS(grid, 0, 0, 0);
        return m_MinimumSum;
    }
};