class Solution {
public:
    int islandCount = 0;

    bool IsInRange(std::vector<std::vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return false;
        }

        if (grid[i][j] == '*' || grid[i][j] == '0')
        {
            return false;
        }

        return true;
    }

    void BFS(std::vector<std::vector<char>>& grid, int i, int j)
    {
        std::queue<std::pair<int, int>> values;
        values.push({ i, j });
        //grid[i][j] = '*';

        while (!values.empty())
        {
            std::pair<int, int> top = values.front();
            values.pop();
            int _i = top.first;
            int _j = top.second;
            grid[_i][_j] = '*';

            if (IsInRange(grid, _i + 1, _j)) { values.push({ _i + 1, _j });  }
            if (IsInRange(grid, _i - 1, _j)) { values.push({ _i - 1, _j }); }
            if (IsInRange(grid, _i, _j - 1)) { values.push({ _i, _j - 1 }); }
            if (IsInRange(grid, _i, _j + 1)) { values.push({ _i, _j + 1 }); }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    islandCount++;
                    BFS(grid, i, j);
                }
            }
        }

        return islandCount;
    }
};
