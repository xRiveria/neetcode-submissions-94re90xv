class Solution {
public:
    std::vector<std::vector<int>> directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int BFS(std::vector<std::vector<int>>& grid, int i, int j)
    {
        std::queue<std::pair<int, int>> q;
        q.push({ i, j });
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        visited[i][j] = true;

        int level = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s > 0)
            {
                auto p = q.front();
                q.pop();
                if (grid[p.first][p.second] == 0)
                {
                    return level;
                }

                for (auto dir : directions)
                {
                    int row = p.first + dir[0], col = p.second + dir[1];
                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
                        !visited[row][col] && grid[row][col] != -1)
                        {
                            visited[row][col] = true;
                            q.push({ row, col });
                        }
                }


                s--;
            }

            level++;
        }

        return INT_MAX;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == INT_MAX)
                    grid[i][j] = BFS(grid, i, j);
            }
        }
    }
};
