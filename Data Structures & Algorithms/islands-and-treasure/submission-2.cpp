class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> treasures;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    treasures.push({ i, j });
                }
            }
        }
        
        std::vector<std::vector<int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!treasures.empty())
        {
            int row = treasures.front().first;
            int column = treasures.front().second;
            treasures.pop();

            for (int i = 0; i < 4; ++i)
            {
                int r = row + directions[i][0];
                int c = column + directions[i][1];

                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != INT_MAX)
                {
                    continue;
                }

                grid[r][c] = grid[row][column] + 1;
                treasures.push({ r, c });
            }
        }
    }
};
