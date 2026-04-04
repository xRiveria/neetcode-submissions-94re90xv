class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    q.push({ i, j });
                }
            }
        }

        std::vector<std::vector<int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
        int dist = 0;

        while (!q.empty())
        {
            int row = q.front().first;
            int column = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int r = row + directions[i][0];
                int c = column + directions[i][1];

                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != INT_MAX)
                {
                    continue;
                }

                grid[r][c] = grid[row][column] + 1;
                q.push({ r, c });
            }
        }

    }
};
