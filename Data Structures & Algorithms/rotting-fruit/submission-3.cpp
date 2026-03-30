class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> values;
        const int rowAdditions[4] = { 1, -1, 0, 0 };
        const int columnAdditions[4] = { 0, 0, 1, -1 };

        int freshOranges = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    values.push({ i, j });
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        // There are no fresh oranges. 0 minutes until there are no fresh oranges remaining!
        if (freshOranges == 0) return 0; 

        int minutesPassed = -1;
        while (!values.empty())
        {
            int currentItemsInQueue = values.size();
            minutesPassed++;
            for (int k = 0; k < currentItemsInQueue; k++)
            {
                auto [i, j] = values.front();
                values.pop();

                // We have a rotten fruit.
                for (int z = 0; z < 4; ++z)
                {
                    int newRow = i + rowAdditions[z];
                    int newColumn = j + columnAdditions[z];

                    // Observe neighbors.
                    // If neighbors are out of bounds, ignore.
                    if (newRow < 0 || newRow >= grid.size() || newColumn < 0 || newColumn >= grid[0].size())
                    {
                        continue;
                    }

                    // If neighbors are not fresh fruits, ignore.
                    if (grid[newRow][newColumn] != 1)
                    {
                        continue;
                    }

                    // These are fresh fruits! Rot them!
                    grid[newRow][newColumn] = 2;
                    freshOranges--;
                    // Add them to search from them next.
                    values.push({ newRow, newColumn });
                }
            }
        }
        
        return freshOranges == 0 ? minutesPassed : -1;
    }
};
