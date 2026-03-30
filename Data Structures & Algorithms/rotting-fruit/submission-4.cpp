class Solution {
public:
    std::queue<std::pair<int, int>> rottenOranges;
    int freshFruits = 0;
    int timePassed = 0;

    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    freshFruits++;
                }

                if (grid[i][j] == 2)
                {
                    rottenOranges.push({ i, j });
                }
            }
        }

        std::vector<std::pair<int, int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        while (freshFruits > 0 && !rottenOranges.empty())
        {
            int currentLevel = rottenOranges.size();
            for (int i = 0; i < currentLevel; ++i)
            {
                std::pair<int, int> rotten = rottenOranges.front();
                rottenOranges.pop();
                int r = rotten.first;
                int c = rotten.second;
                for (const auto& dir : directions)
                {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
                    grid[row][col] == 1) // FRESH
                    {
                        grid[row][col] = 2;
                        freshFruits--;
                        rottenOranges.push({ row, col });
                    }
                }
            }

            timePassed++; // Once done, done with the rot on this level.           
        }

            if (freshFruits > 0)
    {
        return -1;
    }
    return timePassed;
    }
};
