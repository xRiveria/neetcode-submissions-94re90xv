class Solution {
public:
    std::map<std::pair<int, int>, bool> values;
    int DFS(std::vector<std::vector<int>>& grid, int i, int j)
    {
        // If we are stepping onto water, or stepping off the grid, it is an edge. We count that.
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 1;
        }

        // If this is already in the hashmap, it means we explored it before.
        if (values.count({ i, j }))
        {
            return 0; 
        }

        // Explore
        values[{ i, j}] = true;
        return DFS(grid, i + 1, j) + DFS(grid, i, j + 1) + DFS(grid, i - 1, j) + DFS(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    return DFS(grid, i, j); // There is only 1 island.
                }
            }
        }

        return 0;
    }
};