class Solution {
public:
    std::vector<std::vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    void DFS(int i, int j, std::vector<std::vector<bool>>& ocean, std::vector<std::vector<int>>& heights)
    {
        ocean[i][j] = true;

        for (auto& dir : dirs)
        {
            int nr = i + dir[0];
            int nc = j + dir[1];

            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && 
            !(ocean[nr][nc]) && heights[nr][nc] >= heights[i][j])
            {
                DFS(nr, nc, ocean, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // If we start from the ocean borders and reach a cell, it means that cell can flow down to that ocean.
        // We do this for both atlantic and pacific;
        std::vector<std::vector<int>> results;
        int rows = heights.size(), columns = heights[0].size();
        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(columns, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(columns, false));
        // From top and bottom.
        for (int c = 0; c < columns; ++c) 
        {
            DFS(0, c, pacific, heights);
            DFS(rows - 1, c, atlantic, heights);
        }

        // From left and right.
        for (int r = 0; r < rows; ++r)
        {
            DFS(r, 0, pacific, heights);
            DFS(r, columns - 1, atlantic, heights);
        }

        for (int i = 0; i < pacific.size(); ++i)
        {
            for (int j = 0; j < pacific[0].size(); ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    results.push_back({ i, j });
                }
            }
        }

        return results;
    }
};
