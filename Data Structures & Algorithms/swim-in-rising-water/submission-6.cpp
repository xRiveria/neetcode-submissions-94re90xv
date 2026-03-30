class Solution {
public:
    bool DFS(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int i, int j, int t)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] > t || visited[i][j])
        {
            return false;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return true; 
        }

        visited[i][j] = true;

        // Flood fill all tiles. If we reach the end successfully, we're done and this t is the answer. 
        return DFS(grid, visited, i + 1, j, t) ||
               DFS(grid, visited, i - 1, j, t) ||
               DFS(grid, visited, i, j + 1, t) ||
               DFS(grid, visited, i, j - 1, t);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        int minH = grid[0][0], maxH = grid[0][0];
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                minH = std::min(minH, grid[row][col]);
                maxH = std::max(maxH, grid[row][col]);
            }
        }

        for (int t = minH; t < maxH; ++t) // Or min to max height.
        {
            if (DFS(grid, visited, 0, 0, t))
            {
                return t; // If we can reach the end.
            }

            // Undo the visited list.
            for (int r = 0; r < n; ++r)
            {
                std::fill(visited[r].begin(), visited[r].end(), false); 
            }
        }

        return maxH; 
    }
};
