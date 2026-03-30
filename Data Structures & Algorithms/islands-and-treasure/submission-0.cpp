class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> ourQueue;
        const int INF = 2147483647;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    ourQueue.push({ i, j });
                }
            }
        }

        while (!ourQueue.empty())
        {
            auto [i, j] = ourQueue.front();
            ourQueue.pop();

            for (int k = 0; k < 4; ++k)
            {
                int row = i + dr[k];
                int column = j + dc[k];

                if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size())
                {
                    continue;
                }

                if (grid[row][column] == -1)
                {
                    continue;
                }

                if (grid[row][column] != INF)
                {
                    continue;
                }

                grid[row][column] = grid[i][j] + 1; // Distance = Parent + 1
                ourQueue.push({ row, column });
            }   
        }
    }
};
